/*
 * rt_assert.h
 *
 * Code generation for model "TrainBrakes".
 *
 * Model version              : 1.18
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C++ source code generated on : Tue Jan  7 14:25:30 2025
 */

#ifndef RTW_HEADER_rt_assert_h_
#define RTW_HEADER_rt_assert_h_

/*=========*
 * Asserts *
 *=========*/
#ifndef utAssert
# if defined(DOASSERTS)
#  if !defined(PRINT_ASSERTS)
#    include <assert.h>
#    define utAssert(exp)              assert(exp)
#  else
#    include <stdio.h>

static void _assert(char *statement, char *file, int line)
{
  printf("%s in %s on line %d\n", statement, file, line);
}

#   define utAssert(_EX)               ((_EX) ? (void)0 : _assert(#_EX, __FILE__, __LINE__))
#  endif

# else
#  define utAssert(exp)                                          /* do nothing */
# endif
#endif
#endif                                 /* RTW_HEADER_rt_assert_h_ */
