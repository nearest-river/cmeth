#ifndef CMETH_F32_TRIG_H
#define CMETH_F32_TRIG_H
#include "math_impl.h"


#ifdef _cplusplus
extern "C" {
#endif

/// Returns a very close approximation of `acos(f32_clamp(self,-1.0, 1.0))`.
const f32 _acos_approx_f32(f32 v); 

/// Arctangent of y/x (f32)
///
/// Computes the inverse tangent (arc tangent) of `y/x`.
/// Produces the correct result even for angles near pi/2 or -pi/2 (that is, when `x` is near 0).
/// Returns a value in radians, in the range of -pi to pi.
const f32 _atan2f(const f32 y,const f32 x);

/// Arctangent (f32)
///
/// Computes the inverse tangent (arc tangent) of the input value.
/// Returns a value in radians, in the range of -pi/2 to pi/2.
const f32 _atanf(const f32 x);










#ifdef _cplusplus
}
#endif

#endif
