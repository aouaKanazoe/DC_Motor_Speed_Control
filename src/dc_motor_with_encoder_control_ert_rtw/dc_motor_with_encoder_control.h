/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dc_motor_with_encoder_control.h
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

#ifndef dc_motor_with_encoder_control_h_
#define dc_motor_with_encoder_control_h_
#ifndef dc_motor_with_encoder_control_COMMON_INCLUDES_
#define dc_motor_with_encoder_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                      /* dc_motor_with_encoder_control_COMMON_INCLUDES_ */

#include "dc_motor_with_encoder_control_types.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define dc_motor_with_encoder_control_M (dc_motor_with_encoder_contro_M)

/* Block signals (default storage) */
typedef struct {
  real_T Target_RPM;                   /* '<Root>/Target_RPM' */
  real_T Add;                          /* '<S1>/Add' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T Switch2;                      /* '<S4>/Switch2' */
} B_dc_motor_with_encoder_contr_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Encoder' */
  codertarget_arduinobase_block_T obj_m;/* '<S2>/IN2(input 2)' */
  codertarget_arduinobase_block_T obj_n;/* '<S2>/IN1(input 1)' */
  codertarget_arduinobase_int_b_T obj_f;/* '<S2>/PWM_D5' */
  real_T Delay1_DSTATE_n;              /* '<S2>/Delay1' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T Delay_DSTATE;                /* '<Root>/Delay' */
  int32_T Delay_DSTATE_f;              /* '<S2>/Delay' */
} DW_dc_motor_with_encoder_cont_T;

/* Parameters (default storage) */
struct P_dc_motor_with_encoder_contr_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S3>/Constant'
                                       */
  real_T Constant5_Value;              /* Expression: -255
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant7_Value;              /* Expression: -255
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T Constant14_Value;             /* Expression: -255
                                        * Referenced by: '<S2>/Constant14'
                                        */
  real_T Constant9_Value;              /* Expression: -255
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T Constant11_Value;             /* Expression: -255
                                        * Referenced by: '<S2>/Constant11'
                                        */
  real_T Target_RPM_Value;             /* Expression: 30
                                        * Referenced by: '<Root>/Target_RPM'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T Constant6_Value;              /* Expression: 0.01
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value_b;            /* Expression: 0.3
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Gain1_Gain;                   /* Expression: 60/(0.01*5760)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 255
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant10_Value;             /* Expression: 255
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant12_Value;             /* Expression: 255
                                        * Referenced by: '<S2>/Constant12'
                                        */
  real_T K_Value;                      /* Expression: 3.355263157894737
                                        * Referenced by: '<S2>/K'
                                        */
  real_T Constant8_Value;              /* Expression: 255
                                        * Referenced by: '<S2>/Constant8'
                                        */
  real_T Ki_Value;                     /* Expression: 1.028947368421053
                                        * Referenced by: '<S2>/Ki'
                                        */
  real_T Constant6_Value_d;            /* Expression: 255
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T Kd_Value;                     /* Expression: 0
                                        * Referenced by: '<S2>/Kd'
                                        */
  real_T Delay1_InitialCondition_h;    /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay1'
                                        */
  int32_T Delay_InitialCondition;  /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
  int32_T Delay_InitialCondition_g;
                                 /* Computed Parameter: Delay_InitialCondition_g
                                  * Referenced by: '<S2>/Delay'
                                  */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S2>/Constant1'
                                        */
  uint8_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S2>/Constant3'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S2>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_dc_motor_with_encoder_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_dc_motor_with_encoder_contr_T dc_motor_with_encoder_control_P;

/* Block signals (default storage) */
extern B_dc_motor_with_encoder_contr_T dc_motor_with_encoder_control_B;

/* Block states (default storage) */
extern DW_dc_motor_with_encoder_cont_T dc_motor_with_encoder_contro_DW;

/* Model entry point functions */
extern void dc_motor_with_encoder_control_initialize(void);
extern void dc_motor_with_encoder_control_step(void);
extern void dc_motor_with_encoder_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_dc_motor_with_encode_T *const dc_motor_with_encoder_contro_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'dc_motor_with_encoder_control'
 * '<S1>'   : 'dc_motor_with_encoder_control/Subsystem'
 * '<S2>'   : 'dc_motor_with_encoder_control/Subsystem1'
 * '<S3>'   : 'dc_motor_with_encoder_control/Subsystem1/Compare To Constant'
 * '<S4>'   : 'dc_motor_with_encoder_control/Subsystem1/Saturation Dynamic'
 * '<S5>'   : 'dc_motor_with_encoder_control/Subsystem1/Saturation Dynamic1'
 * '<S6>'   : 'dc_motor_with_encoder_control/Subsystem1/Saturation Dynamic2'
 * '<S7>'   : 'dc_motor_with_encoder_control/Subsystem1/Saturation Dynamic3'
 * '<S8>'   : 'dc_motor_with_encoder_control/Subsystem1/Saturation Dynamic4'
 */
#endif                                 /* dc_motor_with_encoder_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
