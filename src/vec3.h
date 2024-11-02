#include "prelude.h"


typedef struct {
  f32 x;
  f32 y;
  f32 z;
} Vec3;


const Vec3 vec3(f32 x,f32 y,f32 z);
const Vec3 vec3_new(f32 x,f32 y,f32 z);
const Vec3 vec3_splat(f32 v);
const Vec3 vec3_map(Vec3 self,f32 (*f)(f32));
const Vec3 vec3_from_array(f64 a[3]);
void vec3_write_to_slice(Vec3 self,f32* slice);
const Vec3 vec3_from_vec4(f32 v[4]);
const f32 vec3_dot(Vec3 self,Vec3 rhs);
const Vec3 vec3_dot_into_vec(Vec3 self,Vec3 rhs);
const Vec3 vec3_cross(Vec3 self,Vec3 rhs);
const Vec3 vec3_min(Vec3 self,Vec3 rhs);
const Vec3 vec3_max(Vec3 self,Vec3 rhs);
const f32 vec3_min_element(Vec3 self);
const f32 vec3_max_element(Vec3 self);
const f32 vec3_element_sum(Vec3 self);
const f32 vec3_element_product(Vec3 self);
const Vec3 vec3_abs(Vec3 self);
const Vec3 vec3_signum(Vec3 self);
const Vec3 vec3_copysign(Vec3 self,Vec3 rhs);
const u32 vec3_is_negative_bitmask(Vec3 self);
const bool vec3_is_finite(Vec3 self);
const bool vec3_is_nan(Vec3 self);
const f32 vec3_len(Vec3 self);
const f32 vec3_len_squared(Vec3 self);
const f32 vec3_len_recip(Vec3 self);
const f32 vec3_distance(Vec3 self,Vec3 rhs);
const f32 vec3_distance_squared(Vec3 self,Vec3 rhs);
const Vec3 vec3_div_euclid(Vec3 self,Vec3 rhs);
const Vec3 vec3_rem_euclid(Vec3 self,Vec3 rhs);
const Vec3 vec3_normalize(Vec3 self);
const Vec3 vec3_default();
const Vec3 vec3_div(Vec3 self,Vec3 rhs);
void vec3_dev_assign(Vec3* self,Vec3 rhs);
const Vec3 vec3_div_f32(Vec3 self,f32 rhs);
void vec3_div_assign_f32(Vec3* self,f32 rhs);
const Vec3 f32_div_vec3(f32 self,Vec3 rhs);







