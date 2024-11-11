#include "trig.h"
#include "math_impl.h"

// 0x40490fdb
static const f32 PI=3.1415927410e+00;
// 0xb3bbbd2e
static const f32 PI_LO=-8.7422776573e-08;


inline
const f32 _acos_approx_f32(f32 v) {
  // Based on https://github.com/microsoft/DirectXMath `XMScalarAcos`
  // Clamp input to [-1,1].
  const bool nonnegative=!f32_is_sign_negative(v);
  const f32 x=f32_abs(v);
  f32 omx=1.0f-x;
  if(omx<0.0f) {
    omx=0.0;
  }
  f32 root=f32_sqrt(omx);
  // 7-degree minimax approximation
  f32 result=((((((-0.0012624911 * x + 0.00667009) * x - 0.017088126) * x + 0.03089188) * x
    - 0.050174303)
    * x
    + 0.08897899)
    * x
    - 0.2145988)
    * x
    + 1.5707963;
  result*=root;
  // acos(x)=pi - acos(-x) when x < 0
  return nonnegative?result:F32_PI-result;
}

inline
const f32 _atan2f(const f32 y,const f32 x) {
  if(f32_is_nan(x) || f32_is_nan(x)) {
    return x+y;
  }
  u32 ix=f32_to_bits(x);
  u32 iy=f32_to_bits(y);

  if(ix==0x3f800000) {
    // x=1.0
    return _atanf(y);
  }
  // 2*sign(x)+signy
  const u32 m=((iy>>31) & 1) | ((ix>>30) & 2);
  ix&=0x7fffffff;
  iy&=0x7fffffff;

  if(iy==0) {
    switch(m) {
      case 0: case 1: return y; // atan(+-0,+anything)=+-0
      case 2: return PI; // atan(+0,-anything)=pi
      default: return -PI; // atan(-0,-anything)=-pi
    }
  }

  if(ix==0) {
    return m&1? -PI/2.0f : PI/2.0f;
  }

  // when x is INF
  if(ix==0x7f800000) {
    if(iy==0x7f800000) {
      switch(m) {
        case 0: return PI/4.0f; // atan(+INF,+INF)
        case 1: return -PI/4.0f; // atan(-INF,+INF)
        case 2: return 3.0f * PI / 4.0f; // atan(+INF,-INF)
        default: return -3.0f * PI / 4.0f; // atan(-INF,-INF)
      }
    }

    switch(m) {
      case 0: return 0.0f; // atan(+...,+INF)
      case 1: return -0.0f; // atan(-...,+INF)
      case 2: return PI; // atan(+...,-INF)
      default: return -PI; // atan(-...,-INF)
    }
  }

  // |y/x| > 0x1p26 
  if(((ix + (22<<23)) < iy) || (ix==0x7f800000)) {
    return m&1? -PI/2.0f : PI/2.0f;
  }

  const f32 z=((m&2) && ((iy + (26<<23)) < ix))? 0.0f : atanf(fabsf(y/x));

  switch(m) {
    case 0: return z;
    case 1: return -z;
    case 3: return PI - (z-PI_LO);
    default: return (z-PI_LO) - PI;
  }
}













