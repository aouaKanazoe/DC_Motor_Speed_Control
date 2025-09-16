/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dc_motor_with_encoder_control.c
 *
 * Code generated for Simulink model 'dc_motor_with_encoder_control'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Sep 16 08:33:25 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dc_motor_with_encoder_control.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "dc_motor_with_encoder_control_private.h"

/* Block signals (default storage) */
B_dc_motor_with_encoder_contr_T dc_motor_with_encoder_control_B;

/* Block states (default storage) */
DW_dc_motor_with_encoder_cont_T dc_motor_with_encoder_contro_DW;

/* Real-time model */
static RT_MODEL_dc_motor_with_encode_T dc_motor_with_encoder_contro_M_;
RT_MODEL_dc_motor_with_encode_T *const dc_motor_with_encoder_contro_M =
  &dc_motor_with_encoder_contro_M_;

/* Model step function */
void dc_motor_with_encoder_control_step(void)
{
  real_T rtb_Product_b;
  real_T rtb_Subtract_g;
  real_T tmp;
  int32_T rtb_Encoder_0;
  uint8_T rtb_Switch_m_idx_0;
  uint8_T rtb_Switch_m_idx_1;

  /* Constant: '<Root>/Target_RPM' */
  dc_motor_with_encoder_control_B.Target_RPM =
    dc_motor_with_encoder_control_P.Target_RPM_Value;

  /* MATLABSystem: '<Root>/Encoder' */
  if (dc_motor_with_encoder_contro_DW.obj.TunablePropsChanged) {
    dc_motor_with_encoder_contro_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(dc_motor_with_encoder_contro_DW.obj.Index, &rtb_Encoder_0);

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S1>/Delay1'
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Encoder'
   *  Product: '<S1>/Divide1'
   *  Product: '<S1>/Product'
   *  Sum: '<Root>/Subtract'
   *  Sum: '<S1>/Subtract1'
   */
  dc_motor_with_encoder_control_B.Add += (((real_T)rtb_Encoder_0 - (real_T)
    dc_motor_with_encoder_contro_DW.Delay_DSTATE) *
    dc_motor_with_encoder_control_P.Gain1_Gain -
    dc_motor_with_encoder_control_B.Add) *
    (dc_motor_with_encoder_control_P.Constant6_Value /
     dc_motor_with_encoder_control_P.Constant7_Value_b);

  /* SignalConversion generated from: '<Root>/Mux2' */
  dc_motor_with_encoder_control_B.TmpSignalConversionAtTAQSigLogg[0] =
    dc_motor_with_encoder_control_B.Target_RPM;
  dc_motor_with_encoder_control_B.TmpSignalConversionAtTAQSigLogg[1] =
    dc_motor_with_encoder_control_B.Add;

  /* Sum: '<S2>/Subtract' */
  rtb_Subtract_g = dc_motor_with_encoder_control_B.Target_RPM -
    dc_motor_with_encoder_control_B.Add;

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S2>/Constant11'
   *  Constant: '<S2>/Constant12'
   *  RelationalOperator: '<S8>/LowerRelop1'
   *  RelationalOperator: '<S8>/UpperRelop'
   *  Switch: '<S8>/Switch'
   */
  if (rtb_Subtract_g > dc_motor_with_encoder_control_P.Constant12_Value) {
    rtb_Subtract_g = dc_motor_with_encoder_control_P.Constant12_Value;
  } else if (rtb_Subtract_g < dc_motor_with_encoder_control_P.Constant11_Value)
  {
    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S2>/Constant11'
     */
    rtb_Subtract_g = dc_motor_with_encoder_control_P.Constant11_Value;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/K'
   */
  rtb_Product_b = rtb_Subtract_g * dc_motor_with_encoder_control_P.K_Value;

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Ki'
   *  Delay: '<S2>/Delay'
   *  Product: '<S2>/Product1'
   */
  tmp = floor(rtb_Subtract_g * dc_motor_with_encoder_control_P.Ki_Value +
              (real_T)dc_motor_with_encoder_contro_DW.Delay_DSTATE_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  dc_motor_with_encoder_contro_DW.Delay_DSTATE_f = tmp < 0.0 ? -(int32_T)
    (uint32_T)-tmp : (int32_T)(uint32_T)tmp;

  /* End of Sum: '<S2>/Add' */

  /* Product: '<S2>/Product2' incorporates:
   *  Constant: '<S2>/Kd'
   */
  tmp = floor(rtb_Subtract_g * dc_motor_with_encoder_control_P.Kd_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* Sum: '<S2>/Add1' incorporates:
   *  Delay: '<S2>/Delay1'
   *  Product: '<S2>/Product2'
   */
  dc_motor_with_encoder_contro_DW.Delay1_DSTATE_n = (real_T)(tmp < 0.0 ?
    -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) -
    dc_motor_with_encoder_contro_DW.Delay1_DSTATE_n;

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant9'
   *  RelationalOperator: '<S7>/LowerRelop1'
   *  RelationalOperator: '<S7>/UpperRelop'
   *  Switch: '<S7>/Switch'
   */
  if (rtb_Product_b > dc_motor_with_encoder_control_P.Constant10_Value) {
    rtb_Product_b = dc_motor_with_encoder_control_P.Constant10_Value;
  } else if (rtb_Product_b < dc_motor_with_encoder_control_P.Constant9_Value) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S2>/Constant9'
     */
    rtb_Product_b = dc_motor_with_encoder_control_P.Constant9_Value;
  }

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S2>/Constant14'
   *  Constant: '<S2>/Constant8'
   *  Delay: '<S2>/Delay'
   *  RelationalOperator: '<S6>/LowerRelop1'
   *  RelationalOperator: '<S6>/UpperRelop'
   *  Switch: '<S6>/Switch'
   */
  if (dc_motor_with_encoder_contro_DW.Delay_DSTATE_f >
      dc_motor_with_encoder_control_P.Constant8_Value) {
    tmp = dc_motor_with_encoder_control_P.Constant8_Value;
  } else if (dc_motor_with_encoder_contro_DW.Delay_DSTATE_f <
             dc_motor_with_encoder_control_P.Constant14_Value) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S2>/Constant14'
     */
    tmp = dc_motor_with_encoder_control_P.Constant14_Value;
  } else {
    tmp = dc_motor_with_encoder_contro_DW.Delay_DSTATE_f;
  }

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  Delay: '<S2>/Delay1'
   *  RelationalOperator: '<S5>/LowerRelop1'
   *  RelationalOperator: '<S5>/UpperRelop'
   *  Switch: '<S5>/Switch'
   */
  if (dc_motor_with_encoder_contro_DW.Delay1_DSTATE_n >
      dc_motor_with_encoder_control_P.Constant6_Value_d) {
    rtb_Subtract_g = dc_motor_with_encoder_control_P.Constant6_Value_d;
  } else if (dc_motor_with_encoder_contro_DW.Delay1_DSTATE_n <
             dc_motor_with_encoder_control_P.Constant7_Value) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S2>/Constant7'
     */
    rtb_Subtract_g = dc_motor_with_encoder_control_P.Constant7_Value;
  } else {
    rtb_Subtract_g = dc_motor_with_encoder_contro_DW.Delay1_DSTATE_n;
  }

  /* Sum: '<S2>/Add2' incorporates:
   *  Switch: '<S5>/Switch2'
   *  Switch: '<S6>/Switch2'
   *  Switch: '<S7>/Switch2'
   */
  dc_motor_with_encoder_control_B.Switch2 = (rtb_Product_b + tmp) +
    rtb_Subtract_g;

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant5'
   *  RelationalOperator: '<S4>/LowerRelop1'
   *  RelationalOperator: '<S4>/UpperRelop'
   *  Switch: '<S4>/Switch'
   */
  if (dc_motor_with_encoder_control_B.Switch2 >
      dc_motor_with_encoder_control_P.Constant2_Value) {
    /* Sum: '<S2>/Add2' incorporates:
     *  Switch: '<S4>/Switch2'
     */
    dc_motor_with_encoder_control_B.Switch2 =
      dc_motor_with_encoder_control_P.Constant2_Value;
  } else if (dc_motor_with_encoder_control_B.Switch2 <
             dc_motor_with_encoder_control_P.Constant5_Value) {
    /* Sum: '<S2>/Add2' incorporates:
     *  Constant: '<S2>/Constant5'
     *  Switch: '<S4>/Switch'
     *  Switch: '<S4>/Switch2'
     */
    dc_motor_with_encoder_control_B.Switch2 =
      dc_motor_with_encoder_control_P.Constant5_Value;
  }

  /* End of Switch: '<S4>/Switch2' */
  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (dc_motor_with_encoder_control_B.Switch2 >=
      dc_motor_with_encoder_control_P.CompareToConstant_const) {
    rtb_Switch_m_idx_0 = dc_motor_with_encoder_control_P.Constant_Value;
    rtb_Switch_m_idx_1 = dc_motor_with_encoder_control_P.Constant1_Value;
  } else {
    rtb_Switch_m_idx_0 = dc_motor_with_encoder_control_P.Constant3_Value;
    rtb_Switch_m_idx_1 = dc_motor_with_encoder_control_P.Constant4_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/IN1(input 1)' */
  writeDigitalPin(9, rtb_Switch_m_idx_0);

  /* MATLABSystem: '<S2>/IN2(input 2)' */
  writeDigitalPin(4, rtb_Switch_m_idx_1);

  /* MATLABSystem: '<S2>/PWM_D5' */
  dc_motor_with_encoder_contro_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(5UL);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Abs: '<S2>/Abs'
   */
  tmp = floor(fabs(dc_motor_with_encoder_control_B.Switch2));
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<S2>/PWM_D5' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  MW_PWM_SetDutyCycle
    (dc_motor_with_encoder_contro_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, (real_T)
     (uint8_T)tmp);

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  MATLABSystem: '<Root>/Encoder'
   */
  dc_motor_with_encoder_contro_DW.Delay_DSTATE = rtb_Encoder_0;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  dc_motor_with_encoder_contro_M->Timing.taskTime0 =
    ((time_T)(++dc_motor_with_encoder_contro_M->Timing.clockTick0)) *
    dc_motor_with_encoder_contro_M->Timing.stepSize0;
}

/* Model initialize function */
void dc_motor_with_encoder_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(dc_motor_with_encoder_contro_M, -1);
  dc_motor_with_encoder_contro_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  dc_motor_with_encoder_contro_M->Sizes.checksums[0] = (3425497764U);
  dc_motor_with_encoder_contro_M->Sizes.checksums[1] = (2234475558U);
  dc_motor_with_encoder_contro_M->Sizes.checksums[2] = (2425169284U);
  dc_motor_with_encoder_contro_M->Sizes.checksums[3] = (3995767038U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    dc_motor_with_encoder_contro_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(dc_motor_with_encoder_contro_M->extModeInfo,
      &dc_motor_with_encoder_contro_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(dc_motor_with_encoder_contro_M->extModeInfo,
                        dc_motor_with_encoder_contro_M->Sizes.checksums);
    rteiSetTFinalTicks(dc_motor_with_encoder_contro_M->extModeInfo, -1);
  }

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  dc_motor_with_encoder_control_B.Add =
    dc_motor_with_encoder_control_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  dc_motor_with_encoder_contro_DW.Delay_DSTATE =
    dc_motor_with_encoder_control_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  dc_motor_with_encoder_contro_DW.Delay_DSTATE_f =
    dc_motor_with_encoder_control_P.Delay_InitialCondition_g;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  dc_motor_with_encoder_contro_DW.Delay1_DSTATE_n =
    dc_motor_with_encoder_control_P.Delay1_InitialCondition_h;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  dc_motor_with_encoder_contro_DW.obj.Index = 0U;
  dc_motor_with_encoder_contro_DW.obj.matlabCodegenIsDeleted = false;
  dc_motor_with_encoder_contro_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &dc_motor_with_encoder_contro_DW.obj.Index);
  dc_motor_with_encoder_contro_DW.obj.isSetupComplete = true;
  dc_motor_with_encoder_contro_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(dc_motor_with_encoder_contro_DW.obj.Index);

  /* Start for MATLABSystem: '<S2>/IN1(input 1)' */
  dc_motor_with_encoder_contro_DW.obj_n.matlabCodegenIsDeleted = false;
  dc_motor_with_encoder_contro_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(9, 1);
  dc_motor_with_encoder_contro_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/IN2(input 2)' */
  dc_motor_with_encoder_contro_DW.obj_m.matlabCodegenIsDeleted = false;
  dc_motor_with_encoder_contro_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(4, 1);
  dc_motor_with_encoder_contro_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/PWM_D5' */
  dc_motor_with_encoder_contro_DW.obj_f.matlabCodegenIsDeleted = false;
  dc_motor_with_encoder_contro_DW.obj_f.isInitialized = 1L;
  dc_motor_with_encoder_contro_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (5UL, 0.0, 0.0);
  dc_motor_with_encoder_contro_DW.obj_f.isSetupComplete = true;
}

/* Model terminate function */
void dc_motor_with_encoder_control_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!dc_motor_with_encoder_contro_DW.obj.matlabCodegenIsDeleted) {
    dc_motor_with_encoder_contro_DW.obj.matlabCodegenIsDeleted = true;
    if ((dc_motor_with_encoder_contro_DW.obj.isInitialized == 1L) &&
        dc_motor_with_encoder_contro_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<S2>/IN1(input 1)' */
  if (!dc_motor_with_encoder_contro_DW.obj_n.matlabCodegenIsDeleted) {
    dc_motor_with_encoder_contro_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN1(input 1)' */

  /* Terminate for MATLABSystem: '<S2>/IN2(input 2)' */
  if (!dc_motor_with_encoder_contro_DW.obj_m.matlabCodegenIsDeleted) {
    dc_motor_with_encoder_contro_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN2(input 2)' */
  /* Terminate for MATLABSystem: '<S2>/PWM_D5' */
  if (!dc_motor_with_encoder_contro_DW.obj_f.matlabCodegenIsDeleted) {
    dc_motor_with_encoder_contro_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((dc_motor_with_encoder_contro_DW.obj_f.isInitialized == 1L) &&
        dc_motor_with_encoder_contro_DW.obj_f.isSetupComplete) {
      dc_motor_with_encoder_contro_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (dc_motor_with_encoder_contro_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      dc_motor_with_encoder_contro_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close
        (dc_motor_with_encoder_contro_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM_D5' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
