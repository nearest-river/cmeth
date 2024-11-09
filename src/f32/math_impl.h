#ifndef CMETH_F32_MATH_IMPL_H
#define CMETH_F32_MATH_IMPL_H

#include <math.h>
#include "../prelude.h"
#include "../../include/cprimitives/src/consts/f32.h"

#ifdef _cplusplus
extern "C" {
#endif
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
const f32 f32_eq(f32 self,f32 rhs);
const f32 f32_ne(f32 self,f32 rhs);
const f32 f32_ge(f32 self,f32 rhs);
const f32 f32_gt(f32 self,f32 rhs);
const f32 f32_le(f32 self,f32 rhs);
const f32 f32_lt(f32 self,f32 rhs);
#ifdef _cplusplus
}
#endif

#endif
