/*
 * rt_nrand_Upu32_Yd_f_pw_snf.cpp
 *
 * Code generation for model "ElectricalSystem".
 *
 * Model version              : 1.2076
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C++ source code generated on : Tue Jan  7 14:23:05 2025
 * Created for block: ElectricalSystem
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_urand_Upu32_Yd_f_pw_snf.h"
#include "rt_nrand_Upu32_Yd_f_pw_snf.h"

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}
