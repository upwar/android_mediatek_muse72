#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/xlog.h>

#include "kd_camera_hw.h"

#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_camera_feature.h"

/******************************************************************************
 * Debug configuration
******************************************************************************/
#define PFX "[kd_camera_hw]"
#define PK_DBG_NONE(fmt, arg...)    do {} while (0)
//#define PK_DBG_FUNC(fmt, arg...)    printk(KERN_INFO PFX "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_DBG_FUNC printk

#define DEBUG_CAMERA_HW_K
#ifdef  DEBUG_CAMERA_HW_K
#define PK_DBG PK_DBG_FUNC
#define PK_ERR(fmt, arg...)         printk(KERN_ERR PFX "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_XLOG_INFO(fmt, args...) \
        do {    \
                    xlog_printk(ANDROID_LOG_INFO, "kd_camera_hw", fmt, ##args); \
        } while(0)
#else
#define PK_DBG(a,...)
#define PK_ERR(a,...)
#define PK_XLOG_INFO(fmt, args...)
#endif


extern void ISP_MCLK1_EN(bool En); //[LGE_UPDATE][yonghwan.lym@lge.com][2014-04-30] MCLK set to low when MCLK is disabled.
static void MainCameraDigtalPowerCtrl(kal_bool on){
#if 0 // M4_TEMP
    if(mt_set_gpio_mode(GPIO_MAIN_CAMERA_12V_POWER_CTRL_PIN,0)){PK_DBG("[[CAMERA SENSOR] Set MAIN CAMERA_DIGITAL POWER_PIN ! \n");}
    if(mt_set_gpio_dir(GPIO_MAIN_CAMERA_12V_POWER_CTRL_PIN,GPIO_DIR_OUT)){PK_DBG("[[CAMERA SENSOR] Set CAMERA_POWER_PULL_PIN DISABLE ! \n");}
    if(mt_set_gpio_out(GPIO_MAIN_CAMERA_12V_POWER_CTRL_PIN,on)){PK_DBG("[[CAMERA SENSOR] Set CAMERA_POWER_PULL_PIN DISABLE ! \n");;}
#endif
}



/*#ifndef GPIO_MAIN_CAMERA_28V_POWER_CTRL_PIN
#define GPIO_MAIN_CAMERA_28V_POWER_CTRL_PIN GPIO37
#endif
static void MainCameraAnalogPowerCtrl(kal_bool on){
    if(mt_set_gpio_mode(GPIO_MAIN_CAMERA_28V_POWER_CTRL_PIN,0)){PK_DBG("[[CAMERA SENSOR] Set MAIN CAMERA_DIGITAL POWER_PIN ! \n");}
    if(mt_set_gpio_dir(GPIO_MAIN_CAMERA_28V_POWER_CTRL_PIN,GPIO_DIR_OUT)){PK_DBG("[[CAMERA SENSOR] Set CAMERA_POWER_PULL_PIN DISABLE ! \n");}
    if(mt_set_gpio_out(GPIO_MAIN_CAMERA_28V_POWER_CTRL_PIN,on)){PK_DBG("[[CAMERA SENSOR] Set CAMERA_POWER_PULL_PIN DISABLE ! \n");;}
}*/

int GetCameraId(void)
{
	int camera_id;

	mt_set_gpio_mode(GPIO_CAMERA_CMID_PIN, GPIO_CAMERA_CMID_PIN_M_GPIO);
	mt_set_gpio_dir(GPIO_CAMERA_CMID_PIN, GPIO_DIR_IN);
	camera_id = mt_get_gpio_in(GPIO_CAMERA_CMID_PIN);
	return camera_id;
}

int kdCISModulePowerOn(CAMERA_DUAL_CAMERA_SENSOR_ENUM SensorIdx, char *currSensorName, BOOL On, char* mode_name)
{
    u32 pinSetIdx = 0;//default main sensor
    u32 pinSetIdxTmp = 0;

    #define IDX_PS_CMRST 0
    #define IDX_PS_CMPDN 4

    #define IDX_PS_MODE 1
    #define IDX_PS_ON   2
    #define IDX_PS_OFF  3
    u32 pinSet[2][8] = {
          //for main sensor
          {GPIO_CAMERA_CMRST_PIN,
              GPIO_CAMERA_CMRST_PIN_M_GPIO,   /* mode */
              GPIO_OUT_ONE,                   /* ON state */
              GPIO_OUT_ZERO,                  /* OFF state */
           GPIO_CAMERA_CMPDN_PIN,
              GPIO_CAMERA_CMPDN_PIN_M_GPIO,
              GPIO_OUT_ONE,
              GPIO_OUT_ZERO,
          },
          //for sub sensor
          {GPIO_CAMERA_CMRST1_PIN,
           GPIO_CAMERA_CMRST1_PIN_M_GPIO,
              GPIO_OUT_ONE,
              GPIO_OUT_ZERO,
           GPIO_CAMERA_CMPDN1_PIN,
              GPIO_CAMERA_CMPDN1_PIN_M_GPIO,
              GPIO_OUT_ONE,
              GPIO_OUT_ZERO,
          }
         };

    PK_DBG("kdCISModulePowerOn: 4EC 8AA\n");

    if (DUAL_CAMERA_MAIN_SENSOR == SensorIdx){
        pinSetIdx = 0;
    }
    else if (DUAL_CAMERA_SUB_SENSOR == SensorIdx) {
        pinSetIdx = 1;
    }


    //power ON
    if (On) {

       PK_DBG("kdCISModulePowerOn -on:currSensorName=%s;\n",currSensorName);

	   //MainCameraDigtalPowerCtrl(1);

       if (currSensorName && (0 == strcmp(SENSOR_DRVNAME_T4K28_YUV,currSensorName)))
       {
		   PK_DBG("[CAMERA SENSOR] kdCISModulePowerOn get in---SENSOR_DRVNAME_T4K28_YUV sensorIdx:%d; pinSetIdx=%d\n",SensorIdx, pinSetIdx);
		   ISP_MCLK1_EN(false); //[LGE_UPDATE][yonghwan.lym@lge.com][2014-04-30] MCLK set to low when MCLK is disabled.
		   msleep(10); //[LGE_UPDATE][yonghwan.lym@lge.com][2014-04-30] MCLK set to low when MCLK is disabled.

		   if(TRUE != hwPowerOn(CAMERA_POWER_VCAM_D2, VOL_1800,mode_name))
		   {
			   PK_DBG("[CAMERA SENSOR] Fail to enable digital power\n");//2.8 ->1.8
			   //return -EIO;
			   goto _kdCISModulePowerOn_exit_;
		   }

		   if(TRUE != hwPowerOn(CAMERA_POWER_VCAM_D, VOL_1800,mode_name))
		   {
			   PK_DBG("[CAMERA SENSOR] Fail to enable digital power\n");//2.8 ->1.8
			   //return -EIO;
			   goto _kdCISModulePowerOn_exit_;
		   }

		   if(TRUE != hwPowerOn(CAMERA_POWER_VCAM_A, VOL_2800,mode_name))
		   {
			   PK_DBG("[CAMERA SENSOR] Fail to enable analog power\n");
			   //return -EIO;
			   goto _kdCISModulePowerOn_exit_;
		   }

#if 0
	   	   
		   if(TRUE != hwPowerOn(CAMERA_POWER_VCAM_A2, VOL_2800,mode_name))
		   {
			   PK_DBG("[CAMERA SENSOR] Fail to enable analog power\n");
			   //return -EIO;
			   goto _kdCISModulePowerOn_exit_;
		   }
#endif

		   msleep(5);
		   ISP_MCLK1_EN(true); //[LGE_UPDATE][yonghwan.lym@lge.com][2014-04-30] MCLK set to low when MCLK is disabled.
		   msleep(5); //[LGE_UPDATE][yonghwan.lym@lge.com][2014-04-30] MCLK set to low when MCLK is disabled.

		   if(mt_set_gpio_out(pinSet[pinSetIdx][IDX_PS_CMPDN],pinSet[pinSetIdx][IDX_PS_CMPDN+IDX_PS_OFF])){PK_DBG("[CAMERA LENS] set gpio failed!! \n");}
		   if(mt_set_gpio_out(pinSet[pinSetIdx][IDX_PS_CMRST],pinSet[pinSetIdx][IDX_PS_CMRST+IDX_PS_OFF])){PK_DBG("[CAMERA SENSOR] set gpio failed!! \n");}
		   if (GPIO_CAMERA_INVALID != pinSet[pinSetIdx][IDX_PS_CMRST])
		   {
			 //PDN pin
			 if(mt_set_gpio_mode(pinSet[pinSetIdx][IDX_PS_CMPDN],pinSet[pinSetIdx][IDX_PS_CMPDN+IDX_PS_MODE])){PK_DBG("[CAMERA LENS] set gpio mode failed!! \n");}
			 if(mt_set_gpio_dir(pinSet[pinSetIdx][IDX_PS_CMPDN],GPIO_DIR_OUT)){PK_DBG("[CAMERA LENS] set gpio dir failed!! \n");}
			 if(mt_set_gpio_out(pinSet[pinSetIdx][IDX_PS_CMPDN],pinSet[pinSetIdx][IDX_PS_CMPDN+IDX_PS_ON])){PK_DBG("[CAMERA LENS] set gpio failed!! \n");}
			 msleep(3);

			 //RST pin
			 if(mt_set_gpio_mode(pinSet[pinSetIdx][IDX_PS_CMRST],pinSet[pinSetIdx][IDX_PS_CMRST+IDX_PS_MODE])){PK_DBG("[CAMERA SENSOR] set gpio mode failed!! \n");}
			 if(mt_set_gpio_dir(pinSet[pinSetIdx][IDX_PS_CMRST],GPIO_DIR_OUT)){PK_DBG("[CAMERA SENSOR] set gpio dir failed!! \n");}
			 if(mt_set_gpio_out(pinSet[pinSetIdx][IDX_PS_CMRST],pinSet[pinSetIdx][IDX_PS_CMRST+IDX_PS_ON])){PK_DBG("[CAMERA SENSOR] set gpio failed!! \n");}
			 msleep(3);
		   }

		   //disable inactive sensor
		   if(pinSetIdx == 0) {//disable sub
			   pinSetIdxTmp = 1;
		   }
		   else{
			   pinSetIdxTmp = 0;
		   }
		   if (GPIO_CAMERA_INVALID != pinSet[pinSetIdxTmp][IDX_PS_CMRST]) {
			   if(mt_set_gpio_mode(pinSet[pinSetIdxTmp][IDX_PS_CMRST],pinSet[pinSetIdxTmp][IDX_PS_CMRST+IDX_PS_MODE])){PK_DBG("[CAMERA SENSOR] set gpio mode failed!! \n");}
			   if(mt_set_gpio_mode(pinSet[pinSetIdxTmp][IDX_PS_CMPDN],pinSet[pinSetIdxTmp][IDX_PS_CMPDN+IDX_PS_MODE])){PK_DBG("[CAMERA LENS] set gpio mode failed!! \n");}
			   if(mt_set_gpio_dir(pinSet[pinSetIdxTmp][IDX_PS_CMRST],GPIO_DIR_OUT)){PK_DBG("[CAMERA SENSOR] set gpio dir failed!! \n");}
			   if(mt_set_gpio_dir(pinSet[pinSetIdxTmp][IDX_PS_CMPDN],GPIO_DIR_OUT)){PK_DBG("[CAMERA LENS] set gpio dir failed!! \n");}
			   if(mt_set_gpio_out(pinSet[pinSetIdxTmp][IDX_PS_CMRST],pinSet[pinSetIdxTmp][IDX_PS_CMRST+IDX_PS_OFF])){PK_DBG("[CAMERA SENSOR] set gpio failed!! \n");} //low == reset sensor
			   if(mt_set_gpio_out(pinSet[pinSetIdxTmp][IDX_PS_CMPDN],pinSet[pinSetIdxTmp][IDX_PS_CMPDN+IDX_PS_OFF])){PK_DBG("[CAMERA LENS] set gpio failed!! \n");} //high == power down lens module
		   }
	   }
       else
	   {
            PK_DBG("[CAMERA SENSOR] Camera sensor type loading fail!! \n");
	   }

    }
    else {//power OFF

       PK_DBG("kdCISModulePowerOn -off:currSensorName=%s\n",currSensorName);
       if (GPIO_CAMERA_INVALID != pinSet[pinSetIdx][IDX_PS_CMRST]) {
           if(mt_set_gpio_mode(pinSet[pinSetIdx][IDX_PS_CMRST],pinSet[pinSetIdx][IDX_PS_CMRST+IDX_PS_MODE])){PK_DBG("[CAMERA SENSOR] set gpio mode failed!! \n");}
           if(mt_set_gpio_dir(pinSet[pinSetIdx][IDX_PS_CMRST],GPIO_DIR_OUT)){PK_DBG("[CAMERA SENSOR] set gpio dir failed!! \n");}
           if(mt_set_gpio_out(pinSet[pinSetIdx][IDX_PS_CMRST],pinSet[pinSetIdx][IDX_PS_CMRST+IDX_PS_OFF])){PK_DBG("[CAMERA SENSOR] set gpio failed!! \n");} //low == reset sensor

           if(mt_set_gpio_mode(pinSet[pinSetIdx][IDX_PS_CMPDN],pinSet[pinSetIdx][IDX_PS_CMPDN+IDX_PS_MODE])){PK_DBG("[CAMERA LENS] set gpio mode failed!! \n");}
           if(mt_set_gpio_dir(pinSet[pinSetIdx][IDX_PS_CMPDN],GPIO_DIR_OUT)){PK_DBG("[CAMERA LENS] set gpio dir failed!! \n");}
           if(mt_set_gpio_out(pinSet[pinSetIdx][IDX_PS_CMPDN],pinSet[pinSetIdx][IDX_PS_CMPDN+IDX_PS_OFF])){PK_DBG("[CAMERA LENS] set gpio failed!! \n");} //high == power down lens module
       }
	   ISP_MCLK1_EN(false); //[LGE_UPDATE][yonghwan.lym@lge.com][2014-04-30] MCLK set to low when MCLK is disabled.

       if(TRUE != hwPowerDown(CAMERA_POWER_VCAM_D2,mode_name))
       {
           PK_DBG("[CAMERA SENSOR] Fail to enable analog power\n");
           //return -EIO;
           goto _kdCISModulePowerOn_exit_;
       }

       if(TRUE != hwPowerDown(CAMERA_POWER_VCAM_D, mode_name)) {
           PK_DBG("[CAMERA SENSOR] Fail to OFF digital power\n");
           //return -EIO;
           goto _kdCISModulePowerOn_exit_;
       }

       if(TRUE != hwPowerDown(CAMERA_POWER_VCAM_A,mode_name)) {
           PK_DBG("[CAMERA SENSOR] Fail to OFF analog power\n");
           //return -EIO;
           goto _kdCISModulePowerOn_exit_;
       }


#if 0
       if(TRUE != hwPowerDown(CAMERA_POWER_VCAM_A2,mode_name))
       {
           PK_DBG("[CAMERA SENSOR] Fail to enable analog power\n");
           //return -EIO;
           goto _kdCISModulePowerOn_exit_;
       }
#endif
  }

  return 0;
_kdCISModulePowerOn_exit_:
    return -EIO;
}


EXPORT_SYMBOL(kdCISModulePowerOn);

//!--
//
