#include <math.h>
#include "math_impl.h"


inline_always
const f32 _f32_abs_private(f32 self) {
  // SAFETY: This transmutation is fine. Probably. For the reasons rust-std is using it.
  u32 x=*((u32*)&self) & 0x7fffffff;
  return *((f32*)&x);
}


inline_always
const f32 f32_abs(f32 self) {
  return fabsf(self);
}

inline_always
const f32 f32_signum(f32 self) {
  return f32_is_nan(self)?F32_NAN:f32_copysign(1.0,self);
}

inline_always
const bool f32_is_nan(f32 self) {
  return self!=self;
}

inline_always
const f32 f32_copysign(f32 self,f32 sign) {
  return copysignf(self,sign);
}

inline_always
const bool f32_is_sign_negative(f32 self) {
  // IEEE754 says: isSignMinus(x) is true if and only if x has negative sign. isSignMinus
  // applies to zeros and NaNs as well.
  // SAFETY: This is just transmuting to get the sign bit, it's fine.
  u32 x=*((u32*)&self);
  return (x & 0x80000000)!=0;
}

inline_always
const bool f32_is_finite(f32 self) {
  return _f32_abs_private(self)<F32_INFINITY;
}

inline_always
const f32 f32_sqrt(f32 self) {
  return sqrtf(self);
}

inline_always
const f32 f32_rem(f32 self,f32 x) {
  return fmodf(self,x);
}

inline_always
const f32 f32_div_euclid(f32 self,f32 x) {
  f32 q=f32_trunc(self/x);
  if(f32_rem(self,x)<0.0) {
    return x>0.0?q-1.0:q+1.0;
  }

  return q;
}

inline_always
const f32 f32_trunc(f32 self) {
  return (f32)((i32)self);
}

inline_always
const f32 f32_rem_euclid(f32 self,f32 rhs) {
  f32 r=f32_rem(self,rhs);
  return r<0.0?r+f32_abs(rhs):r;
}




