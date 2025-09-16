/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dc_motor_with_encoder_control_data.c
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

/* Block parameters (default storage) */
P_dc_motor_with_encoder_contr_T dc_motor_with_encoder_control_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant5'
   */
  -255.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant7'
   */
  -255.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant14'
   */
  -255.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant9'
   */
  -255.0,

  /* Expression: -255
   * Referenced by: '<S2>/Constant11'
   */
  -255.0,

  /* Expression: 30
   * Referenced by: '<Root>/Target_RPM'
   */
  30.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay1'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/Constant6'
   */
  0.01,

  /* Expression: 0.3
   * Referenced by: '<Root>/Constant7'
   */
  0.3,

  /* Expression: 60/(0.01*5760)
   * Referenced by: '<Root>/Gain1'
   */
  1.0416666666666667,

  /* Expression: 255
   * Referenced by: '<S2>/Constant2'
   */
  255.0,

  /* Expression: 255
   * Referenced by: '<S2>/Constant10'
   */
  255.0,

  /* Expression: 255
   * Referenced by: '<S2>/Constant12'
   */
  255.0,

  /* Expression: 3.355263157894737
   * Referenced by: '<S2>/K'
   */
  3.3552631578947372,

  /* Expression: 255
   * Referenced by: '<S2>/Constant8'
   */
  255.0,

  /* Expression: 1.028947368421053
   * Referenced by: '<S2>/Ki'
   */
  1.0289473684210531,

  /* Expression: 255
   * Referenced by: '<S2>/Constant6'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S2>/Kd'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay1'
   */
  0.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  0,

  /* Computed Parameter: Delay_InitialCondition_g
   * Referenced by: '<S2>/Delay'
   */
  0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S2>/Constant'
   */
  0U,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S2>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S2>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S2>/Constant4'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
