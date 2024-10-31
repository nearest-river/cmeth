#include "math.h"
#include "math_impl.h"


inline
const f32 _f32_abs_private(f32 self) {
  // SAFETY: This transmutation is fine. Probably. For the reasons rust-std is using it.
  u32 x=*((u32*)&self) & 0x7fffffff;
  return *((f32*)&x);
}


inline_always
const f32 f32_abs(f32 self) {
  return fabsf(self);
}

inline
const f32 f32_signum(f32 self) {
  return f32_is_nan(self)?F32_NAN:f32_copysignf(1.0,self);
}

inline
const bool f32_is_nan(f32 self) {
  return self!=self;
}

inline
const f32 f32_copysign(f32 self,f32 sign) {
  return copysignf(self,sign);
}

inline
const bool f32_is_sign_negative(f32 self) {
  // IEEE754 says: isSignMinus(x) is true if and only if x has negative sign. isSignMinus
  // applies to zeros and NaNs as well.
  // SAFETY: This is just transmuting to get the sign bit, it's fine.
  u32 x=*((u32*)&self);
  return (x & 0x80000000)!=0;
}

inline
const bool f32_is_finite(f32 self) {
  return _f32_abs_private(self)<F32_INFINITY;
}

inline
const f32_sqrt(f32 self) {
  return sqrtf(self);
}


