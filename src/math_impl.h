#ifndef CMETH_MATH_IMPL_H
#define CMETH_MATH_IMPL_H

#define MATH_IMPL_H
#include <math.h>
#include "prelude.h"
#include "../include/cprimitives/src/consts/f32.h"


const f32 f32_abs(f32 self);
const f32 f32_signum(f32 self);
const bool f32_is_nan(f32 self);
const f32 f32_copysign(f32 self,f32 sign);
const bool f32_is_sign_negative(f32 self);
const bool f32_is_finite(f32 self);
const f32 f32_sqrt(f32 self);
const f32 f32_div_euclid(f32 self,f32 x);
const f32 f32_trunc(f32 self);
const f32 f32_rem(f32 self,f32 x);
const f32 f32_rem_euclid(f32 self,f32 rhs);
const f32 f32_neg(f32 self);

#endif
