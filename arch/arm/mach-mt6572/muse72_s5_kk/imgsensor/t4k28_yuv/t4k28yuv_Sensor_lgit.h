/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SENSOR_LGIT_H
#define __SENSOR_LGIT_H

t4k28_short_t T4K28_Init_Reg_Lgit[] = {
	{0x3000,0x08},//[RO] VERNUM[15:8];
	{0x3001,0x40},//[RO] VERNUM[7:0];
	{0x3002,0x00},//[RO] PISO[15:8];
	{0x3003,0x00},//[RO] PISO[7:0];
	{0x3004,0x00},//-/-/-/-/-/-/-/PISO_MSKN;
	{0x3005,0xa8},//[RO] FRAME_COUNT[7:0];

	// [LGE_UPDATE][youmi.jun@lge.com][2014-02-05] Apply H/V flip (0x00->0x03) for pudding camera and hidden menu
	{0x3011,0x03},//-/-/-/-/-/-/VREVON/HREVON;

	{0x3012,0x02},//-/-/-/-/-/-/VLAT_ON/GROUP_HOLD;
	{0x3014,0x00},//-/-/-/-/-/-/PARALLEL_OUT_SW[1:0];
	{0x3015,0x05},//-/-/-/H_COUNT[12:8];
	{0x3016,0x16},//H_COUNT[7:0];
	{0x3017,0x01},//-/-/-/V_COUNT[12:8];
	{0x3018,0x75},//V_COUNT[7:0];
	{0x3019,0x00},//-/-/-/-/-/-/-/SCALE_M[8];
	{0x301A,0x20},//SCALE_M[7:0];
	{0x301B,0x10},//-/-/-/V_ANABIN/-/-/-/-;
	{0x301C,0x01},//-/-/-/-/-/-/-/SCALING_MODE;
	{0x3020,0x03},//-/-/-/-/-/HOUTPIX[10:8];
	{0x3021,0x20},//HOUTPIX[7:0];
	{0x3022,0x02},//-/-/-/-/-/VOUTPIX[10:8];
	{0x3023,0x58},//VOUTPIX[7:0];
	{0x3025,0x00},//-/-/-/-/-/-/VCROP[9:8];
	{0x3026,0x00},//VCROP[7:0];
	{0x3027,0x00},//-/-/-/-/OUTPUT_FORMAT[3:0];
	{0x302C,0x00},//-/-/-/-/TEST_HC/VSYNC_PH/HSYNC_PH/ESYNC_SW;
	{0x302D,0x00},//-/-/H_PRESET[13:8];
	{0x302E,0x00},//H_PRESET[7:0];
	{0x302F,0x00},//V_PRESET[15:8];
	{0x3030,0x00},//V_PRESET[7:0];
	{0x3031,0x01},//-/-/-/-/-/HREG_HRST_POS[10:8];
	{0x3032,0x98},//HREG_HRST_POS[7:0];
	{0x3033,0x83},//OADJ_AT_SW/OADJ_AT_SET/OADJ_MN_EN/-/OADJ_AT_DLY_H[3:0];
	{0x3034,0x01},//OADJ_AT_STA_V[3:0]/OADJ_AT_WID_V[3:0];
	{0x3037,0x00},//-/-/-/-/-/-/VCI[1:0];
	{0x303C,0x80},//SDA_DRVUP/-/-/-/-/-/-/-;
	{0x303E,0x01},//-/-/-/-/-/-/-/DCLK_POL;
	{0x303F,0x00},//-/-/CKST_SEL[1:0]/CKSP_SEL[1:0]/CKMR_SEL[1:0];
	{0x3040,0x80},//PISO_STP_X_SW/SLEEP_SW/VCO_STP_SW/PHY_PWRON_SW/PISO_STP_X_MN/SLEEP;
	{0x3044,0x02},//-/-/-/-/PLLEV_SEL/PCMODE/ICP_PCH/ICP_NCH;
	{0x3045,0x04},//-/-/-/-/-/PRE_PLL_CNTL[2:0];
	{0x3046,0x00},//-/-/-/-/-/-/-/PLL_MULTI[8];
	{0x3047,0x5A},//PLL_MULTI[7:0];
	{0x3048,0x01},//-/-/-/-/VT_SYS_CNTL[3:0];
	{0x3049,0x01},//-/-/-/-/OP_SYS_CNTL[3:0];
	{0x304A,0x0a},//-/-/-/-/VT_PIX_CNTL[3:0];
	{0x304B,0x0a},//-/-/-/-/ST_CLK_CNTL[3:0];
	{0x304C,0x00},//-/-/-/-/-/-/PLL_CNTL[1:0];
	{0x304E,0x01},//-/-/-/-/-/BST_CNTL[2:0];
	{0x3050,0x60},//VCO_CONV[2:0]/-/-/-/-/-;
	{0x3051,0x82},//VCO_EN/-/-/-/-/DIVRSTX_SEL/DIVRSTX_SW/DIVRSTX_MN;
	{0x3052,0x10},//-/-/REGVD_SEL[1:0]/-/AMON0_SEL[2:0];
	{0x3053,0x00},//-/AUTO_ICP_R_SEL/-/-/-/HS_SR_CNT/-/LPFR_SEL;
	{0x3055,0x84},//CAMP15_EN/-/-/-/-/VOUT15_SEL[2:0];
	{0x3056,0x02},//CLDET_EN/-/-/-/-/-/BIAS_SEL/-;
	{0x3059,0x18},//EXTCLK_FRQ_MHZ[15:8];
	{0x305A,0x00},//EXTCLK_FRQ_MHZ[7:0];
	{0x3068,0xf0},//SY_SPARE1[7:0];
	{0x3069,0xf0},//SY_SPARE2[7:0];
	{0x306C,0x06},//[RO] -/-/-/-/XCROP_SC[11:8];
	{0x306D,0x40},//[RO] XCROP_SC[7:0];
	{0x306E,0x00},//[RO] -/-/-/-/XSTA_SC[11:8];
	{0x306F,0x04},//[RO] XSTA_SC[7:0];
	{0x3070,0x06},//[RO] -/-/-/-/XEND_SC[11:8];
	{0x3071,0x43},//[RO] XEND_SC[7:0];
	{0x3072,0x02},//[RO] -/-/-/-/-/YCROP_SC[10:8];
	{0x3073,0x58},//[RO] YCROP_SC[7:0];
	{0x3074,0x00},//[RO] -/-/-/-/-/YSTA_SC[10:8];
	{0x3075,0x04},//[RO] YSTA_SC[7:0];
	{0x3076,0x02},//[RO] -/-/-/-/-/YEND_SC[10:8];
	{0x3077,0x5b},//[RO] YEND_SC[7:0];
	{0x307F,0x03},//[RO] -/-/-/-/-/-/mode_vdl[1:0];
	{0x3080,0x70},//CLKPOSPRD[4:0]/-/-/-;
	{0x3081,0x28},//HSPREPRD[4:0]/-/-/-;
	{0x3082,0x60},//HS0PRD[4:0]/-/-/-;
	{0x3083,0x48},//HSTRLPRD[4:0]/-/-/-;
	{0x3084,0x40},//CLKTRIPRD[4:0]/-/-/-;
	{0x3085,0x28},//CLKPREPRD[4:0]/-/-/-;
	{0x3086,0xf8},//CLK0PRD[4:0]/-/-/-;
	{0x3087,0x38},//TLPXPRD[4:0]/-/-/-;
	{0x3088,0x03},//-/-/-/-/-/-/LNKBTWK_ON/LNKBT_ON;
	{0x3089,0x02},//MSB_LBRATE[15:8];
	{0x308A,0x58},//MSB_LBRATE[7:0];
	{0x3091,0x00},//-/-/-/-/-/-/CLKULPS/ESCREQ;
	{0x3092,0x44},//[RO] RO_CRC[15:8];
	{0x3093,0x8a},//[RO] RO_CRC[7:0];
	{0x3095,0x78},//ESCDATA[7:0];
	{0x3097,0x00},//LVDS_D1_DELAY[3:0]/LVDS_CLK_DELAY[3:0];
	{0x3098,0x40},//-/PHASE_ADJUST[2:0]/-/-/-/LP_SR_CNT;
	{0x309A,0x00},//TEST_PN9/-/-/-/OP_TEST[3:0];
	{0x309B,0x00},//T_VALUE1[7:0];
	{0x309D,0x00},//-/-/-/-/-/-/-/MIPI_CLK_MODE;
	{0x309E,0x00},//-/-/-/-/LB_TEST_CLR/LB_TEST_EN/-/LB_MODE;
	{0x309F,0x00},//[RO] -/RO_LPBT_ERR_K/RO_LPBT_ERR_M/RO_LPBT_CNT[4:0];
	{0x30A0,0x00},//-/-/-/-/-/-/FIFODLY[9:8];
	{0x30A1,0x00},//FIFODLY[7:0];
	{0x30A2,0xa7},//NUMWAKE[7:0];
	{0x30A3,0x00},//TX_TRIGOPT/-/TRIG_Z5_X/-/-/-/-/-;
	{0x30A4,0xff},//TRIG_DUMMY[7:0];
	{0x30A5,0x80},//CLKPRE2/-/-/-/-/-/-/-;
	{0x30A6,0xff},//NUMINIT[7:0];
	{0x30A7,0x00},//EN_PHASE_SEL[1:0]/-/-/-/-/-/-;
	{0x30A8,0x01},//MIPI_FS_CD[3:0]/MIPI_FE_CD[3:0];
	{0x30F1,0x00},//-/-/-/T_OUTSEL[4:0];
	{0x30F2,0x00},//-/-/-/-/-/-/-/T_VWIDTH_LAT_ON;
	{0x30FE,0x80},//T_PROTECT/-/-/-/-/-/-/-;
	{0x3100,0xd2},//POSLFIX/NEGLFIX/NEGLEAKCUT/BOOSTEN_L/BSTREADEV/POSBSTSEL/READVDSEL;
	{0x3101,0xd3},//RSTVDSEL_AZS/POSBSTCNT[2:0]/-/POSBSTHG[2:0];
	{0x3102,0x65},//NEGBSTCNT[3:0]/-/POSBSTGA[2:0];
	{0x3103,0x80},//TAUREADEN/-/-/-/-/-/-/LNOBMODE;
	{0x3104,0x31},//GDMOSBGREN/-/VSIGDRSEL[1:0]/GDMOSCNT[3:0];
	{0x3105,0x04},//-/-/-/-/KBIASCNT[3:0];
	{0x3106,0x23},//-/-/DRADRVI[1:0]/-/DRADRVLV[2:0];
	{0x3107,0x20},//TESTDACEN/-/VREFSWG[1:0]/-/-/-/VREFDLYCNT;
	{0x3108,0x7b},//S1CNT[3:0]/CBIASIB/-/CBIASIA[1:0];
	{0x3109,0x80},//BOOSTEN_R/-/-/IDLINGOFFEN/-/-/EDGETESTEN[1:0];
	{0x310A,0x00},//-/-/-/-/-/SENSEMODE[2:0];
	{0x310B,0x00},//SPARE[1:0]/-/-/ANAMON1_SEL[3:0];
	{0x3110,0x11},//-/-/-/FBC_SUBSMPL/-/-/-/BIN_MODE;
	{0x3111,0x11},//-/-/ES_MODE[1:0]/-/-/-/ESREAD_ALT_OFF;
	{0x3112,0x00},//-/-/-/-/-/-/-/DIS_MODE;
	{0x3113,0x00},//-/-/-/-/-/-/-/ALLZEROSET_ON;
	{0x3114,0x10},//-/-/ALLZEROSET_1ST_ON[1:0]/-/-/-/ALLZEROSET_CHG_ON;
	{0x3115,0x22},//-/-/LTCH_POS[1:0]/-/RODATA_U/DMR_ON/ALLREAD_ON;
	{0x3120,0x08},//BSC_OFF/-/-/-/SADR_1PULSE/-/-/DRESET_1PULSE;
	{0x3121,0x13},//-/BSCPULSE_INTVL[6:0];
	{0x3122,0x33},//-/DRESET_1U[6:0];
	{0x3123,0x0e},//-/-/-/DRESET_W[4:0];
	{0x3124,0x26},//-/FTLSNS_1U[2:0]/FTLSNS_W[3:0];
	{0x3125,0x00},//-/-/-/-/-/SADR_1U[2:0];
	{0x3126,0x0c},//-/-/-/SADR_1W[4:0];
	{0x3127,0x08},//-/-/SADR_2W[5:0];
	{0x3128,0x80},//AUTO_READ_W/-/-/-/-/-/-/-;
	{0x3129,0x65},//ESREAD_1U[7:0];
	{0x312A,0x27},//-/ESREAD_2U[6:0];
	{0x312B,0x77},//-/ESREAD_1W[6:0];
	{0x312C,0x77},//-/ESREAD_2W[6:0];
	{0x312D,0x1a},//-/-/-/ESTGRESET_D[4:0];
	{0x312E,0xb8},//VSIGPU_U[7:0];
	{0x312F,0x38},//VSIGPU_W[7:0];
	{0x3130,0x80},//VSIGPU_LOW/-/-/-/-/-/-/-;
	{0x3131,0x33},//-/ROREAD_U[6:0];
	{0x3132,0x63},//-/ROREAD_W[6:0];
	{0x3133,0x00},//-/-/-/-/-/-/-/ROTGRESET_U[8];
	{0x3134,0xdd},//ROTGRESET_U[7:0];
	{0x3135,0x07},//EXTD_ROTGRESET/-/-/-/ROTGRESET_W[3:0];
	{0x3136,0xb7},//ZEROSET_U[7:0];
	{0x3137,0x11},//-/-/ZEROSET_W[5:0];
	{0x3138,0x0b},//RSTDRAIN_HIGH/-/RSTDRAIN_D[5:0];
	{0x313B,0x0a},//-/-/-/RSTDRAIN_U[4:0];
	{0x313C,0x05},//-/-/-/RSTDRAIN3_U[4:0];
	{0x313D,0x01},//DRCUT_SIGIN/DRCUT_DMY_OFF/-/DRCUT_U[4:0];
	{0x313E,0x62},//DRCUT_NW[7:0];
	{0x313F,0x85},//DRCUT_VDER_W[7:0];
	{0x3140,0x01},//BGRSH_OFF/-/BGRSH_U[1:0]/-/-/BGRSH_W[1:0];
	{0x3141,0x40},//VSIGDR_MODE[1:0]/-/VSIGDR_U[1:0]/-/VSIGDR_D[1:0];
	{0x3142,0x80},//S1_2PULSES/-/S1_ALL_HIGH/S1_STOPBST/-/-/-/-;
	{0x3143,0x22},//-/S1_1U[6:0];
	{0x3144,0x3e},//S1_1W[7:0];
	{0x3145,0x32},//-/S1_2U[6:0];
	{0x3146,0x2e},//-/S1_2W[6:0];
	{0x3147,0x23},//-/-/S1_AW[5:0];
	{0x3148,0x22},//-/S1A_USHIFT[2:0]/-/S1A_DSHIFT[2:0];
	{0x3149,0x11},//-/S1W_USHIFT[2:0]/-/S1W_DSHIFT[2:0];
	{0x314A,0x6b},//S2_W[7:0];
	{0x314B,0x30},//-/S3_W[6:0];
	{0x314C,0x69},//S4_W[7:0];
	{0x314D,0x80},//CDS_STOPBST/-/S4_AD[5:0];
	{0x314E,0x31},//BSTCKLFIX_HIGH/BSTCKLFIX_1U[2:0]/-/BSTCKLFIX_1D[2:0];
	{0x314F,0x32},//-/BSTCKLFIX_2U[2:0]/-/BSTCKLFIX_2D[2:0];
	{0x3150,0x32},//BSTCKLFIX_1P/BSTCKLFIX_3U[2:0]/-/BSTCKLFIX_3D[2:0];
	{0x3151,0x03},//-/-/-/INTEN_CU[4:0];
	{0x3152,0x0c},//-/-/INTEN_CW[5:0];
	{0x3153,0xb3},//INTEN_SU[7:0];
	{0x3154,0x20},//-/-/INTEN_AU[5:0];
	{0x3155,0x13},//-/-/BSTCKLFIX_1P_U[1:0]/INTEN_AD[3:0];
	{0x3156,0x66},//INTRS_CU[7:0];
	{0x3157,0x02},//-/-/-/INTRS_CD[4:0];
	{0x3158,0x03},//-/-/-/-/INTRS_SU[3:0];
	{0x3159,0x01},//-/-/-/-/-/-/INTRS_SD[1:0];
	{0x315A,0x16},//-/-/INTRS_AU[5:0];
	{0x315B,0x10},//-/-/-/INTRS_AW[4:0];
	{0x315C,0x00},//-/DRKCLIP_U[2:0]/CLR_GCNTR_D[3:0];
	{0x315D,0x44},//DRKCLIP_PRE_U[3:0]/-/DRKCLIP_PRE_D[2:0];
	{0x315E,0x1b},//-/HPL2_NU[6:0];
	{0x315F,0x52},//-/HPL2_AU[6:0];
	{0x3160,0x00},//EXT_AG_ON/-/-/-/-/-/-/-;
	{0x3161,0x03},//EXT_AG_PARAM[15:8];
	{0x3162,0x00},//EXT_AG_PARAM[7:0];
	{0x3163,0xff},//TDAC_INT[7:0];
	{0x3164,0x00},//TDAC_MIN[7:0];
	{0x3165,0x01},//TDAC_SWD[1:0]/-/-/TDAC_STEP[3:0];
	{0x3166,0x00},//DACS_INT[7:0];
	{0x3167,0xff},//DACS_MAX[7:0];
	{0x3168,0x01},//DACS_SWD[1:0]/-/-/DACS_STEP[3:0];
	{0x3169,0x00},//AG_TEST/-/LATCH_TEST[1:0]/-/-/-/-;
	{0x3180,0x00},//SIGIN_ON/VOB_DISP/HOB_DISP/-/-/-/-/-;
	{0x3181,0x20},//DATA_LATCH_SEL/-/EN_CBLK/OADJ_MODE[1:0]/-/OADJ_INTEN_W[1:0];
	{0x3182,0x40},//-/FBC_MODE[2:0]/-/FBC_PERIOD_SEL[2:0];
	{0x3183,0x96},//CP1_FBC_SEL/-/CP1_OADJ_U[5:0];
	{0x3184,0x30},//-/FBC_LEVEL[6:0];
	{0x3185,0x8f},//FBC_ON/-/FAST_FBC_ON/-/SLOW_FBC_RANGE[3:0];
	{0x3186,0x31},//-/FBC_START_CND[2:0]/-/FBC_SUSP_CND[2:0];
	{0x3187,0x06},//-/-/-/FBC_STOP_CND[4:0];
	{0x3188,0x0c},//FBC_OUT_LINES[7:0];
	{0x3189,0x44},//FBC_HIGH_OBAVE[3:0]/FBC_LOW_OBAVE[3:0];
	{0x318A,0x42},//FBC_IN_LINES[3:0]/FBC_IN_RANGE[3:0];
	{0x318B,0x0b},//FBC_STOP_RANGE/FBC_START_RANGE/-/-/FBC_AG_COEF_DIV[1:0]/FBC_OUT_CN;
	{0x318C,0x11},//FBC_AG_CONT_COEF[7:0];
	{0x318D,0xaa},//EN_ES_CHANGE/-/EN_AG_CHANGE/-/EN_OADJ_CHANGE/-/PSCLAMP_1ST_ON/-;
	{0x318E,0x40},//-/CLAMPSHIFT_SEL[2:0]/AG_CHANGE_VAL[3:0];
	{0x318F,0x30},//CLAMPSHIFT_VAL[7:0];
	{0x3190,0x03},//-/-/-/IDLINGOFF_U[4:0];
	{0x3191,0x01},//-/-/-/-/-/-/IDLINGOFF_D[1:0];
	{0x3192,0x00},//-/-/-/-/EXT_DACPARAM[11:8];
	{0x3193,0x00},//EXT_DACPARAM[7:0];
	{0x3194,0x00},//EXT_CLAMP_ON/EXT_OFFSET_ON/-/-/RET_INT_OFFSET/BIT_VERIF_TIME[2:0];
	{0x3195,0x00},//-/-/-/-/-/-/BLADJ_MODE[1:0];
	{0x3196,0x00},//-/-/-/-/-/BLADJ_COEF[10:8];
	{0x3197,0xde},//BLADJ_COEF[7:0];
	{0x3198,0x00},//-/-/-/-/BLADJ_INTC[11:8];
	{0x3199,0x00},//BLADJ_INTC[7:0];
	{0x319A,0x00},//OB_AVE_MON_SEL[1:0]/-/ST_CKI[4:0];
	{0x319B,0x00},//ST_RSVD_REG[7:0];
	{0x319C,0x16},//-/-/IDLINGOFF_AU[5:0];
	{0x319D,0x0a},//-/-/-/IDLINGOFF_AW[4:0];
	{0x31A0,0xbf},//EXT_HCNT_MAX_ON/-/HCNT_MAX_FIXVAL[13:8];
	{0x31A1,0xff},//HCNT_MAX_FIXVAL[7:0];
	{0x31A2,0x11},//HCNT_MAX_MODE/-/-/FBC_MASK_FRAM_EN/-/MASK_FRAME_NUM[2:0];
	{0x31B0,0x00},//[RO] fbc_operation/-/-/-/-/-/ob_ave[9:8];
	{0x31B1,0x30},//[RO] ob_ave[7:0];
	{0x31B2,0x17},//[RO] -/-/clamp_param[13:8];
	{0x31B3,0xd9},//[RO] clamp_param[7:0];
	{0x31B4,0x03},//[RO] -/-/-/-/offset_param[11:8];
	{0x31B5,0x2b},//[RO] offset_param[7:0];
	{0x31B6,0x18},//[RO] -/-/ps_clamp_param[13:8];
	{0x31B7,0x54},//[RO] ps_clamp_param[7:0];
	{0x31B8,0x00},//[RO] fbcline_cnt[15:8];
	{0x31B9,0x00},//[RO] fbcline_cnt[7:0];
	{0x31BA,0x3f},//[RO] -/-/hcnt_max[13:8];
	{0x31BB,0xff},//[RO] hcnt_max[7:0];
	{0x3300,0xff},//HLNRSW/DANSASW[1:0]/LDNRSW/VDNRSW/ABPCSW/WBPSW/BBPSW;
	{0x3301,0x35},//-/-/ANRSW/PEDAJSW/-/LSSCSW/LSSCAG_SW/PWBSW;
	{0x3303,0x40},//BLKADJ[7:0]; // LGIT and COWELL is same register value.
	{0x3304,0x00},//BLKR[3:0]/BLKGR[3:0];
	{0x3305,0x00},//BLKGB[3:0]/BLKB[3:0];
	{0x3306,0x30},//-/-/OBWIDTH[5:0];
	{0x3307,0x00},//-/-/-/-/-/OBCLIP/BLLVSEL/DANSA2L;
	{0x3308,0x87},//LDNRLIM1[3:0]/LDNRLIM0[3:0];
	{0x330A,0x60},//LDNRGA1[3:0]/LDNRGA0[3:0];
	{0x330B,0x56},//VDNRLIM1[3:0]/VDNRLIM0[3:0];
	{0x330D,0x39},//VDNRGA1[3:0]/VDNRGA0[3:0];
	{0x330E,0xff},//BBPLV0[7:0];
	{0x330F,0xff},//BBPLV1[7:0];
	{0x3310,0xff},//WBPLV0[7:0];
	{0x3311,0x7f},//WBPLV1[7:0];
	{0x3312,0x0f},//WBPOFS[7:0];
	{0x3313,0x0f},//BBPOFS[7:0];
	{0x3314,0x02},//-/-/-/-/CONTLV1[3:0];
	{0x3315,0xff},//CONTLV2[7:0];
	{0x3316,0x18},//ANREG_LEV0[7:0];
	{0x3317,0x00},//ANREG_LEV1[7:0];
	{0x3318,0x20},//ANRG0[7:0];
	{0x3319,0xd0},//ANRG1[7:0];
	{0x331B,0x00},//GRPED0[3:0]/GBPED0[3:0];
	{0x331C,0x00},//RPED0[3:0]/BPED0[3:0];
	{0x331D,0x00},//GRPED1[3:0]/GBPED1[3:0];
	{0x331E,0x00},//RPED1[3:0]/BPED1[3:0];
	{0x3322,0x00},//PWBGAINGR[7:0];
	{0x3323,0x00},//PWBGAINGB[7:0];
	{0x3324,0x00},//PWBGAINR[7:0];
	{0x3325,0x38},//PWBGAINB[7:0];
	{0x3327,0x00},//-/-/-/-/-/-/LIPOL/CSPOL;
	{0x3328,0x00},//-/-/-/-/-/LS1SIG[2:0];
	{0x3329,0x80},//LSHOFG[7:0];
	{0x332A,0x80},//LSHOFR[7:0];
	{0x332B,0x80},//LSHOFB[7:0];
	{0x332C,0x80},//LSVOFG[7:0];
	{0x332D,0x80},//LSVOFR[7:0];
	{0x332E,0x80},//LSVOFB[7:0];
	{0x332F,0x07},//LSALUG[7:0];
	{0x3330,0x00},//LSALUR[7:0];
	{0x3331,0x10},//LSALUB[7:0];
	{0x3332,0x00},//LSARUG[7:0];
	{0x3333,0x04},//LSARUR[7:0];
	{0x3334,0x08},//LSARUB[7:0];
	{0x3335,0x02},//LSALDG[7:0];
	{0x3336,0x20},//LSALDR[7:0];
	{0x3337,0x20},//LSALDB[7:0];
	{0x3338,0x05},//LSARDG[7:0];
	{0x3339,0x14},//LSARDR[7:0];
	{0x333A,0x10},//LSARDB[7:0];
	{0x333B,0x88},//LSBLG[7:0];
	{0x333C,0xd0},//LSBLR[7:0];
	{0x333D,0x58},//LSBLB[7:0];
	{0x333E,0x59},//LSBRG[7:0];
	{0x333F,0x9a},//LSBRR[7:0];
	{0x3340,0x36},//LSBRB[7:0];
	{0x3341,0x68},//LSCUG[7:0];
	{0x3342,0xD0},//LSCUR[7:0];
	{0x3343,0x3A},//LSCUB[7:0];
	{0x3344,0xb0},//LSCDG[7:0];
	{0x3345,0xF0},//LSCDR[7:0];
	{0x3346,0x64},//LSCDB[7:0];
	{0x3347,0x00},//LSBRG_L[3:0]/LSBLG_L[3:0];
	{0x3348,0x00},//LSBR R_L[3:0]/LSBL R_L[3:0];
	{0x3349,0x00},//LSBRB_L[3:0]/LSBLB_L[3:0];
	{0x334A,0x00},//LSCDG_L[3:0]/LSCUG_L[3:0];
	{0x334B,0x00},//LSCDR_L[3:0]/LSCUR_L[3:0];
	{0x334C,0x00},//LSCDB_L[3:0]/LSCUB_L[3:0];
	{0x334D,0x58},//LSHCNT_MPY[7:0];
	{0x334E,0x01},//-/-/-/-/LSVCNT_MPY[11:8];
	{0x334F,0x30},//LSVCNT_MPY[7:0];
	{0x3350,0x01},//-/-/-/-/-/-/LSMGSEL[1:0];
	{0x335F,0x00},//-/-/-/-/-/-/-/TESTPAT_SW;
	{0x3360,0x00},//PP_SPARE[7:0];
	{0x3400,0xa4},//LMCC_SW/-/PGC_SW/-/-/YSHP_SW/-/-;
	{0x3401,0x6a},//-/BRIGHT_SW/LCNT_SW/NLCNT_SW/UVLPF_SW/UVSHP_SW/FCS_SW/UVCRING_SW;
	{0x3402,0x00},//LCS_LI/LCS_CS/-/-/-/EFECT_SEL[2:0];
	{0x3403,0x06},//LCS_CRING[7:0];
	{0x3404,0x53},//LM_RMG[7:0];
	{0x3405,0xFF},//LM_RMB[7:0];
	{0x3406,0x09},//LM_GMR[7:0];
	{0x3407,0x22},//LM_GMB[7:0];
	{0x3408,0x09},//LM_BMR[7:0];
	{0x3409,0x5A},//LM_BMG[7:0];
	{0x340A,0x1a},//-/GAM01P[6:0];
	{0x340B,0x29},//-/GAM02P[6:0];
	{0x340C,0x2d},//-/GAM03P[6:0];
	{0x340D,0x34},//-/GAM04P[6:0];
	{0x340E,0x34},//-/GAM05P[6:0];
	{0x340F,0x4e},//-/GAM06P[6:0];
	{0x3410,0x4e},//-/GAM07P[6:0];
	{0x3411,0x38},//-/GAM08P[6:0];
	{0x3412,0x38},//-/GAM09P[6:0];
	{0x3413,0x56},//-/GAM10P[6:0];
	{0x3414,0x47},//-/GAM11P[6:0];
	{0x3415,0x65},//-/GAM12P[6:0];
	{0x3416,0x47},//-/GAM13P[6:0];
	{0x3417,0x38},//-/GAM14P[6:0];
	{0x3418,0x2d},//-/GAM15P[6:0];
	{0x3419,0x29},//-/GAM16P[6:0];
	{0x341B,0x00},//-/-/BLK_ADJ[5:0];
	{0x341C,0x40},//CbG_MAT[7:0];
	{0x341D,0x63},//CbB_MAT[7:0];
	{0x341E,0x20},//Cb_GAIN[7:0];
	{0x341F,0x88},//CrR_MAT[7:0];
	{0x3420,0x6e},//CrG_MAT[7:0];
	{0x3421,0x00},//Cr_GAIN[7:0];
	{0x3422,0xa0},//Cbr_MGAIN[7:0];
	{0x3423,0x08},//-/-/-/-/CbP_GAIN1[3:0];
	{0x3424,0x08},//-/-/-/-/CbM_GAIN1[3:0];
	{0x3425,0x08},//-/-/-/-/CrP_GAIN1[3:0];
	{0x3426,0x08},//-/-/-/-/CrM_GAIN1[3:0];
	{0x342B,0x20},//-/-/DTL_CRNG0[5:0];
	{0x342C,0x10},//-/-/DTL_CRNG1[5:0];
	{0x342D,0x60},//DTL_PG0[7:0];
	{0x342E,0x90},//DTL_PG1[7:0];
	{0x342F,0x60},//DTL_MG0[7:0];
	{0x3430,0x90},//DTL_MG1[7:0];
	{0x3431,0x40},//DTL_LIM_PH[7:0];
	{0x3432,0x40},//DTL_LIM_MH[7:0];
	{0x3433,0x00},//DTL_LIM_PLS[7:0];
	{0x3434,0x00},//DTL_LIM_MLS[7:0];
	{0x3435,0x00},//DTL_LIM_PLE[7:0];
	{0x3436,0x00},//DTL_LIM_MLE[7:0];
	{0x343F,0x00},//BRIGHT1[7:0];
	{0x3440,0xC2},//BRIGHT0[7:0];
	{0x3441,0x93},//LCONT_LEV[7:0];
	{0x3442,0x00},//BLK_KNEE[7:0];
	{0x3443,0x00},//WHT_KNEE[7:0];
	{0x3444,0x00},//-/-/-/-/BLK_CONT[3:0];
	{0x3446,0x00},//-/-/-/-/WHT_CONT[3:0];
	{0x3447,0x00},//NLOFF_AG[7:0];
	{0x3448,0x00},//-/-/COL_LV[5:0];
	{0x3449,0x00},//-/-/-/-/COL_ED_G[3:0];
	{0x344A,0x00},//UV_CRING1[3:0]/UV_CRING0[3:0];
	{0x344B,0x00},//UV_SHP_AG[7:0];
	{0x344C,0x20},//FCS_EDG_CORING[7:0];
	{0x344D,0xff},//FCS_EDG_LIM[7:0];
	{0x344E,0x0f},//-/-/-/-/FCS_EDG_GAIN[3:0];
	{0x344F,0x20},//FCS_LV[7:0];
	{0x3450,0x80},//FCS_GAIN[7:0];
	{0x3451,0x0f},//-/-/-/-/FCS_AG[3:0];
	{0x3452,0x55},//UNICOFSU[7:0];
	{0x3453,0x49},//UNICOFSV[7:0];
	{0x3454,0x6a},//SEPIAOFSU[7:0];
	{0x3455,0x93},//SEPIAOFSV[7:0];
	{0x345C,0x00},//MP_VLAT_OFF/-/-/-/-/-/TEST_IN_SW[1:0];
	{0x345D,0x00},//TEST_AG[7:0];
	{0x345E,0x00},//MP_SPARE[7:0];
	{0x3500,0xc5},//ALCSW/AWBSW/ALCLOCK/-/ESLIMMODE/ROOMDET/-/ALCLIMMODE;
	{0x3501,0x00},//-/-/-/-/-/-/ALCAIM[9:8];
	{0x3502,0xee},//ALCAIM[7:0];
	{0x3503,0x29},//AGMIN[7:0];
	{0x3504,0x01},//-/-/-/-/AGMAX[11:8];
	{0x3505,0x00},//AGMAX[7:0];
	{0x3506,0x01},//MES[15:8];
	{0x3507,0x78},//MES[7:0];
	{0x3508,0x00},//MMES[15:8];
	{0x3509,0x86},//MMES[7:0];
	{0x350A,0x00},//-/-/-/-/MAG[11:8];
	{0x350B,0x1c},//MAG[7:0];
	{0x350C,0x00},//MDG[7:0];
	{0x350D,0x19},//A1WEIGHT[1:0]/A2WEIGHT[1:0]/A3WEIGHT[1:0]/A4WEIGHT[1:0];
	{0x350E,0x1B},//A5WEIGHT[1:0]/B1WEIGHT[1:0]/B2WEIGHT[1:0]/B3WEIGHT[1:0];
	{0x350F,0x92},//B4WEIGHT[1:0]/B5WEIGHT[1:0]/C1WEIGHT[1:0]/C2WEIGHT[1:0];
	{0x3510,0xA0},//C3WEIGHT[1:0]/C4WEIGHT[1:0]/C5WEIGHT[1:0]/-/-;
	{0x3511,0x1a},//UDMODE[1:0]/-/UPDNSPD[4:0];
	{0x3512,0x10},//ALCOFS[2:0]/NEARSPD[4:0];
	{0x3513,0x00},//ALC_ANJ_OFS[7:0];
	{0x3514,0x00},//-/-/-/-/-/-/ALC_ANJ_SPD[1:0];
	{0x3515,0x10},//ALCFRZLV1[7:0];
	{0x3516,0x10},//ALCFRZLV2[7:0];
	{0x3517,0x01},//ALCFRZTIM[7:0];
	{0x3518,0x00},//ALCSIGMIN[7:0];
	{0x3519,0xff},//ALCSIGMAX[7:0];
	{0x351A,0xc0},//SATSET[7:0];
	{0x351B,0xa8},//FAUTO/FCOUNT[2:0]/FCLSBON/EXPLIM[2:0];
	{0x351C,0x6c},//FLLONGON/FRMSPD[1:0]/FL600S[12:8];
	{0x351D,0x78},//FL600S[7:0];
	{0x351E,0xd6},//ACFDET/AC60M/FLMANU/ACDETDLY/MSKLINE[1:0]/ACDPWAIT[1:0];
	{0x351F,0x80},//FL600AT/TTL1V_ON/-/-/-/-/-/FLDETM[8];
	{0x3520,0x26},//FLDETM[7:0];
	{0x3521,0x02},//ACDET1LV[7:0];
	{0x3522,0x08},//ACDET2LV[7:0];
	{0x3523,0x0c},//SATGUP/SATFRZ/SAT1VDET/-/DETSEL[3:0];
	{0x3524,0x01},//AWBONDOT[2:0]/-/-/-/WBMRG[9:8];
	{0x3525,0x45},//WBMRG[7:0];
	{0x3526,0x3d},//CAREASEL[1:0]/AREAMODE[1:0]/HEXSW/YGATESW/WBMGG[9:8];
	{0x3527,0x00},//WBMGG[7:0];
	{0x3528,0x55},//SQ1SW/SQ1POL/SQ2SW/SQ2POL/SQ3SW/SQ3POL/WBMBG[9:8];
	{0x3529,0x5a},//WBMBG[7:0];
	{0x352A,0x20},//WBGRMAX[7:0];
	{0x352B,0x20},//WBGRMIN[7:0];
	{0x352C,0x20},//WBGBMAX[7:0];
	{0x352D,0x20},//WBGBMIN[7:0];
	{0x352E,0x30},//RBCUT0H[7:0];
	{0x352F,0xe0},//RBCUT0L[7:0];
	{0x3530,0x34},//-/RYCUT0P[6:0];
	{0x3531,0x30},//-/RYCUT0N[6:0];
	{0x3532,0x50},//-/BYCUT0P[6:0];
	{0x3533,0x34},//-/BYCUT0N[6:0];
	{0x3534,0x30},//RBCUT0HL[7:0];
	{0x3535,0xe0},//RBCUT0LL[7:0];
	{0x3536,0x1E},//-/RYCUT0PL[6:0];
	{0x3537,0x20},//-/RYCUT0NL[6:0];
	{0x3538,0x48},//-/BYCUT0PL[6:0];
	{0x3539,0x12},//-/BYCUT0NL[6:0];
	{0x353A,0x00},//RYCUT1H[7:0];
	{0x353B,0x00},//-/RYCUT1L[6:0];
	{0x353C,0x00},//BYCUT1H[7:0];
	{0x353D,0x00},//-/BYCUT1L[6:0];
	{0x353E,0x00},//RYCUT2H[7:0];
	{0x353F,0x00},//-/RYCUT2L[6:0];
	{0x3540,0x00},//BYCUT2H[7:0];
	{0x3541,0x00},//-/BYCUT2L[6:0];
	{0x3542,0x00},//RYCUT3H[7:0];
	{0x3543,0x00},//-/RYCUT3L[6:0];
	{0x3544,0x00},//BYCUT3H[7:0];
	{0x3545,0x00},//-/BYCUT3L[6:0];
	{0x3546,0xc8},//YGATEH[7:0];
	{0x3547,0x0a},//YGATEL[7:0];
	{0x3548,0x84},//CGRANGE[1:0]/-/AWBHUECOR/AWBSPD[3:0];
	{0x3549,0x00},//YGATE_SEL/YGATE_DATA[1:0]/AWBULV[4:0];
	{0x354A,0x00},//AWBFZTIM[2:0]/AWBVLV[4:0];
	{0x354B,0x00},//AWBSFTU[7:0];
	{0x354C,0x00},//AWBSFTV[7:0];
	{0x354D,0x00},//AWBWAIT[7:0];
	{0x354E,0x06},//-/-/-/-/CGCNGSLP[2:0]/CGCNGLV[8];
	{0x354F,0xb0},//CGCNGLV[7:0];
	{0x3550,0x00},//SPLMKON/SPLMKBL/FAREAMK/CAREAMK/CGATEMK/-/-/-;
	{0x3551,0x03},//-/-/-/-/-/SPLADRH[10:8];
	{0x3552,0x28},//SPLADRH[7:0];
	{0x3553,0x00},//MKFLKON/MKFLKSPD[1:0]/-/-/SPLADRV[10:8];
	{0x3554,0x60},//SPLADRV[7:0];
	{0x3555,0xf0},//AU_SPARE[7:0];
	{0x355D,0x00},//[RO] APL_DONE/-/-/-/-/-/APL_O[9:8];
	{0x355E,0xd3},//[RO] APL_O[7:0];
	{0x355F,0x06},//[RO] ALC_ES[15:8];
	{0x3560,0xc0},//[RO] ALC_ES[7:0];
	{0x3561,0x00},//[RO] -/-/-/-/ALC_AG[11:8];
	{0x3562,0x25},//[RO] ALC_AG[7:0];
	{0x3563,0x00},//[RO] -/-/-/-/-/-/ALC_DG[9:8];
	{0x3564,0x71},//[RO] ALC_DG[7:0];
	{0x3565,0x0b},//[RO] -/-/FR_TIM[5:0];
	{0x3566,0xd2},//[RO] ALC_OK/AC60M/DET_SIG/FL_ESLIM/-/-/mag_vg[9:8];
	{0x3567,0x98},//[RO] mag_vg[7:0];
	{0x3568,0x00},//[RO] -/-/-/-/-/-/AVE_USIG[9:8];
	{0x3569,0x00},//[RO] AVE_USIG[7:0];
	{0x356A,0x00},//[RO] -/-/-/-/-/-/AVE_VSIG[9:8];
	{0x356B,0x00},//[RO] AVE_VSIG[7:0];
	{0x356C,0xc1},//[RO] NUM_UVON[15:8];
	{0x356D,0xdb},//[RO] NUM_UVON[7:0];
	{0x356E,0x01},//[RO] -/-/-/-/-/-/AWBGAINR[9:8];
	{0x356F,0x1b},//[RO] AWBGAINR[7:0];
	{0x3570,0x01},//[RO] -/-/-/-/-/-/AWBGAING[9:8];
	{0x3571,0x00},//[RO] AWBGAING[7:0];
	{0x3572,0x01},//[RO] -/-/-/-/-/-/AWBGAINB[9:8];
	{0x3573,0x65},//[RO] AWBGAINB[7:0];
	{0x3574,0x00},//[RO] -/-/-/-/-/-/SET_ALCLV[9:8];
	{0x3575,0xc8},//[RO] SET_ALCLV[7:0];
	{0x3576,0x0e},//[RO] MKY_DATA[7:0];
	{0x3577,0xf7},//[RO] MKU_DATA[7:0];
	{0x3578,0x27},//[RO] MKV_DATA[7:0];
	{0x3579,0x09},//[RO] -/-/-/FL600A[12:8];
	{0x357A,0x99},//[RO] FL600A[7:0];
	{0x357B,0x00},//[RO] AG_CONT[7:0];
	{0x357C,0xe0},//[RO] AU_RO_SPARE[7:0];
	{0x357D,0x00},//[RO] -/-/-/-/-/-/-/ALCCLR;
	{0x3900,0x00},//OTP_STA/-/-/-/OTP_VMOD/OTP_VERIFY/OTP_WREC/OTP_ENBL;
	{0x3901,0x07},//OTP_GVRD/-/-/-/-/OTP_PCLK[2:0];
	{0x3902,0x00},//[RO] OTP_ISTS[2:0]/-/-/OTP_TOE/OTP_VE/OTP_BUSY;
	{0x3903,0x00},//-/-/-/-/-/-/OTP_ADRS[1:0];
	{0x3904,0x00},//OTP_DATA0[7:0];
	{0x3905,0x00},//OTP_DATA1[7:0];
	{0x3906,0x00},//OTP_DATA2[7:0];
	{0x3907,0x00},//OTP_DATA3[7:0];
	{0x3908,0x00},//OTP_DATA4[7:0];
	{0x3909,0x00},//OTP_DATA5[7:0];
	{0x390A,0x00},//OTP_DATA6[7:0];
	{0x390B,0x00},//OTP_DATA7[7:0];
	{0x390C,0x00},//OTP_PERR1/OTP_PERR2/OTP_CLRE/OTP_TEST[4:0];
	{0x30F0,0x00},//T_MONDIRECT/-/-/T_DACTEST/-/T_TMOSEL[2:0];
	{0x3010,0x01}//-/-/-/-/-/-/-/MODSEL;
};

#endif /* __SENSOR_LGIT_H */

