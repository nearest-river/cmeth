#include "vec3.h"
#include "math_impl.h"



inline_always
const Vec3 vec3(f32 x,f32 y,f32 z) {
  return vec3_new(x,y,z);
}

inline_always
const Vec3 vec3_new(f32 x,f32 y,f32 z) {
  Vec3 vec={
    .x=x,
    .y=y,
    .z=z
  };
  return vec;
}

inline
const Vec3 vec3_splat(f32 v) {
  Vec3 vec={
    .x=v,
    .y=v,
    .z=v
  };
  return vec;
}

inline
const Vec3 vec3_map(Vec3 self,f32 (*f)(f32)) {
  self.x=f(self.x);
  self.y=f(self.y);
  self.z=f(self.z);
  return self;
}

inline
const Vec3 vec3_from_array(f64 a[3]) {
  Vec3 vec={
    .x=a[0],
    .y=a[1],
    .z=a[2]
  };
  return vec;
}

inline
void vec3_write_to_slice(Vec3 self,f32* slice) {
  slice[0]=self.x;
  slice[1]=self.y;
  slice[2]=self.z;
}

// TODO
inline
const Vec3 vec3_from_vec4(f32 v[4]) {
  Vec3 vec={
    .x=v[0],
    .y=v[1],
    .z=v[2]
  };
  return vec;
}

inline
const f32 vec3_dot(Vec3 self,Vec3 rhs) {
  return (self.x*rhs.x)+(self.y*rhs.y)+(self.z*rhs.z);
}

inline
const Vec3 vec3_dot_into_vec(Vec3 self,Vec3 rhs) {
  return vec3_splat(vec3_dot(self,rhs));
}

inline
const Vec3 vec3_cross(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=self.y * rhs.z - rhs.y * self.z,
    .y=self.z * rhs.x - rhs.z * self.x,
    .z=self.x * rhs.y - rhs.x * self.y,
  };

  return vec;
}

inline
const Vec3 vec3_min(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=min(self.x,rhs.x),
    .y=min(self.y,rhs.y),
    .z=min(self.z,rhs.z)
  };
  return vec;
}

inline
const Vec3 vec3_max(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=max(self.x,rhs.x),
    .y=max(self.y,rhs.y),
    .z=max(self.z,rhs.z)
  };
  return vec;
}

inline
const f32 vec3_min_element(Vec3 self) {
  return min(self.x,min(self.y,self.z));
}

inline
const f32 vec3_max_element(Vec3 self) {
  return max(self.x,max(self.y,self.z));
}

inline
const f32 vec3_element_sum(Vec3 self) {
  return self.x+self.y+self.z;
}

inline
const f32 vec3_element_product(Vec3 self) {
  return self.x*self.y*self.z;
}

//TODO: BVec3


inline
const Vec3 vec3_abs(Vec3 self) {
  Vec3 vec={
    .x=f32_abs(self.x),
    .y=f32_abs(self.y),
    .z=f32_abs(self.z)
  };

  return vec;
}

inline
const Vec3 vec3_signum(Vec3 self) {
  Vec3 vec={
    .x=f32_signum(self.x),
    .y=f32_signum(self.y),
    .z=f32_signum(self.z)
  };

  return vec;
}

inline
const Vec3 vec3_copysign(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_copysign(self.x,rhs.x),
    .y=f32_copysign(self.y,rhs.y),
    .z=f32_copysign(self.z,rhs.z)
  };

  return vec;
}

inline
const u32 vec3_is_negative_bitmask(Vec3 self) {
  return ((u32)f32_is_sign_negative(self.x))
  | ((u32)f32_is_sign_negative(self.y)) << 1
  | ((u32)f32_is_sign_negative(self.z)) << 2;
}

inline
const bool vec3_is_finite(Vec3 self) {
  return f32_is_finite(self.x) && f32_is_finite(self.y) && f32_is_finite(self.z);
}

inline
const bool vec3_is_nan(Vec3 self) {
  return f32_is_nan(self.x) && f32_is_nan(self.y) && f32_is_nan(self.z);
}

inline
const f32 vec3_len(Vec3 self) {
  return f32_sqrt(vec3_dot(self,self));
}

inline
const f32 vec3_len_squared(Vec3 self) {
  return vec3_dot(self,self);
}

inline
const f32 vec3_len_recip(Vec3 self) {
  return 1.0F/vec3_len(self);
}

inline
const f32 vec3_distance(Vec3 self,Vec3 rhs) {
  return 0.0; // TODO
}

inline
const f32 vec3_distance_squared(Vec3 self,Vec3 rhs) {
  return 0.0; // TODO
}

inline
const Vec3 vec3_div_euclid(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_div_euclid(self.x,rhs.x),
    .y=f32_div_euclid(self.y,rhs.y),
    .z=f32_div_euclid(self.z,rhs.z)
  };

  return vec;
}

inline
const Vec3 vec3_rem_euclid(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_rem_euclid(self.x,rhs.x),
    .y=f32_rem_euclid(self.y,rhs.y),
    .z=f32_rem_euclid(self.z,rhs.z)
  };

  return vec;
}

inline
const Vec3 vec3_normalize(Vec3 self) {
  return vec3(0.0,0.0,0.0); // TODO
}

inline_always
const Vec3 vec3_default() {
  return vec3_splat(0.0F);
}

inline
const Vec3 vec3_div(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=self.x/rhs.x,
    .y=self.y/rhs.y,
    .z=self.z/rhs.z
  };

  return vec;
}

inline
void vec3_dev_assign(Vec3* self,Vec3 rhs) {
  self->x/=rhs.x;
  self->y/=rhs.y;
  self->z/=rhs.z;
}

inline
const Vec3 vec3_div_f32(Vec3 self,f32 rhs) {
  Vec3 vec={
    .x=self.x/rhs,
    .y=self.y/rhs,
    .z=self.z/rhs
  };

  return vec;
}

inline
void vec3_div_assign_f32(Vec3* self,f32 rhs) {
  self->x/=rhs,
  self->y/=rhs,
  self->z/=rhs;
}

inline
const Vec3 f32_div_vec3(f32 self,Vec3 rhs) {
  Vec3 vec={
    .x=self/rhs.x,
    .y=self/rhs.y,
    .z=self/rhs.z
  };

  return vec;
}

inline
const Vec3 vec3_mul(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=self.x*rhs.x,
    .y=self.y*rhs.y,
    .z=self.z*rhs.z
  };

  return vec;
}

inline
void vec3_mul_assign(Vec3* self,Vec3 rhs) {
  self->x*=rhs.x;
  self->y*=rhs.y;
  self->z*=rhs.z;
}

inline
const Vec3 vec3_mul_f32(Vec3 self,f32 rhs) {
  Vec3 vec={
    .x=self.x*rhs,
    .y=self.y*rhs,
    .z=self.z*rhs
  };

  return vec;
}

inline
void vec3_mul_assign_f32(Vec3* self,f32 rhs) {
  self->x*=rhs;
  self->y*=rhs;
  self->z*=rhs;
}

inline
const Vec3 f32_mul_vec3(f32 self,Vec3 rhs) {
  Vec3 vec={
    .x=self*rhs.x,
    .y=self*rhs.y,
    .z=self*rhs.z
  };

  return vec;
}

inline
const Vec3 vec3_add(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=self.x+rhs.x,
    .y=self.y+rhs.y,
    .z=self.z+rhs.z
  };

  return vec;
}

inline
void vec3_add_assign(Vec3* self,Vec3 rhs) {
  self->x+=rhs.x;
  self->y+=rhs.y;
  self->z+=rhs.z;
}

inline
const Vec3 vec3_add_f32(Vec3 self,f32 rhs) {
  Vec3 vec={
    .x=self.x+rhs,
    .y=self.y+rhs,
    .z=self.z+rhs
  };

  return vec;
}

inline
void vec3_add_assign_f32(Vec3* self,f32 rhs) {
  self->x+=rhs;
  self->y+=rhs;
  self->z+=rhs;
}

inline
const Vec3 f32_add_vec3(f32 self,Vec3 rhs) {
  Vec3 vec={
    .x=self+rhs.x,
    .y=self+rhs.y,
    .z=self+rhs.z
  };

  return vec;
}

inline
const Vec3 vec3_sub(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=self.x-rhs.x,
    .y=self.y-rhs.y,
    .z=self.z-rhs.z
  };

  return vec;
}

inline
void vec3_sub_assign(Vec3* self,Vec3 rhs) {
  self->x-=rhs.x;
  self->y-=rhs.y;
  self->z-=rhs.z;
}

inline
const Vec3 vec3_sub_f32(Vec3 self,f32 rhs) {
  Vec3 vec={
    .x=self.x-rhs,
    .y=self.y-rhs,
    .z=self.z-rhs
  };

  return vec;
}

inline
void vec3_sub_assign_f32(Vec3* self,f32 rhs) {
  self->x-=rhs;
  self->y-=rhs;
  self->z-=rhs;
}

inline
const Vec3 f32_sub_vec3(f32 self,Vec3 rhs) {
  Vec3 vec={
    .x=self-rhs.x,
    .y=self-rhs.y,
    .z=self-rhs.z
  };

  return vec;
}

inline
const Vec3 vec3_rem(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_rem(self.x,rhs.x),
    .y=f32_rem(self.y,rhs.y),
    .z=f32_rem(self.z,rhs.z)
  };

  return vec;
}

inline
void vec3_rem_assign(Vec3* self,Vec3 rhs) {
  self->x=f32_rem(self->x,rhs.x);
  self->y=f32_rem(self->x,rhs.y);
  self->z=f32_rem(self->x,rhs.z);
}

inline
const Vec3 vec3_rem_f32(Vec3 self,f32 rhs) {
  Vec3 vec={
    .x=f32_rem(self.x,rhs),
    .y=f32_rem(self.y,rhs),
    .z=f32_rem(self.z,rhs)
  };

  return vec;
}

inline
void vec3_rem_assign_f32(Vec3* self,f32 rhs) {
  self->x=f32_rem(self->x,rhs);
  self->y=f32_rem(self->y,rhs);
  self->z=f32_rem(self->z,rhs);
}

inline
const Vec3 f32_rem_vec3(f32 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_rem(self,rhs.x),
    .y=f32_rem(self,rhs.y),
    .z=f32_rem(self,rhs.z)
  };

  return vec;
}

inline
const Vec3 vec3_neg(Vec3 self) {
  Vec3 vec={
    .x=f32_neg(self.x),
    .y=f32_neg(self.y),
    .z=f32_neg(self.z)
  };

  return vec;
}



































