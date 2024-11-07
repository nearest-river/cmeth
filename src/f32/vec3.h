#ifndef CMETH_F32_VEC3_H
#define CMETH_F32_VEC3_H
#include "../prelude.h"
#include "../bool/bvec3.h"


typedef struct {
  f32 x;
  f32 y;
  f32 z;
} Vec3;

#ifdef _cplusplus
extern "C" {
#endif
const Vec3 vec3(f32 x,f32 y,f32 z);
const Vec3 vec3_new(f32 x,f32 y,f32 z);
const Vec3 vec3_splat(f32 v);
const Vec3 vec3_select(BVec3 mask,Vec3 if_true,Vec3 if_false);
const Vec3 vec3_map(Vec3 self,f32 (*f)(f32));
const Vec3 vec3_from_array(f64 a[3]);
void vec3_write_to_slice(Vec3 self,f32* slice);
const Vec3 vec3_from_vec4(f32 v[4]);
const f32 vec3_dot(Vec3 self,Vec3 rhs);
const Vec3 vec3_dot_into_vec(Vec3 self,Vec3 rhs);
const Vec3 vec3_cross(Vec3 self,Vec3 rhs);
const Vec3 vec3_min(Vec3 self,Vec3 rhs);
const Vec3 vec3_max(Vec3 self,Vec3 rhs);
const Vec3 vec3_clamp(Vec3 self,Vec3 min,Vec3 max);
const f32 vec3_min_element(Vec3 self);
const f32 vec3_max_element(Vec3 self);
const f32 vec3_element_sum(Vec3 self);
const f32 vec3_element_product(Vec3 self);
const BVec3 vec3_cmpeq(Vec3 self,Vec3 rhs);
const BVec3 vec3_cmpne(Vec3 self,Vec3 rhs);
const BVec3 vec3_cmpge(Vec3 self,Vec3 rhs);
const BVec3 vec3_cmpgt(Vec3 self,Vec3 rhs);
const BVec3 vec3_cmple(Vec3 self,Vec3 rhs);
const BVec3 vec3_cmplt(Vec3 self,Vec3 rhs);
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
const Vec3 vec3_normalize_or(Vec3 self,Vec3 fallback);
const Vec3 vec3_normalize_or_zero(Vec3 self);
const bool vec3_is_normalized(Vec3 self);
const Vec3 vec3_default();
const Vec3 vec3_div(Vec3 self,Vec3 rhs);
void vec3_dev_assign(Vec3* self,Vec3 rhs);
const Vec3 vec3_div_f32(Vec3 self,f32 rhs);
void vec3_div_assign_f32(Vec3* self,f32 rhs);
const Vec3 f32_div_vec3(f32 self,Vec3 rhs);
const Vec3 vec3_mul(Vec3 self,Vec3 rhs);
void vec3_mul_assign(Vec3* self,Vec3 rhs);
const Vec3 vec3_mul_f32(Vec3 self,f32 rhs);
void vec3_mul_assign_f32(Vec3* self,f32 rhs);
const Vec3 f32_mul_vec3(f32 self,Vec3 rhs);
const Vec3 vec3_add(Vec3 self,Vec3 rhs);
void vec3_add_assign(Vec3* self,Vec3 rhs);
const Vec3 vec3_add_f32(Vec3 self,f32 rhs);
void vec3_add_assign_f32(Vec3* self,f32 rhs);
const Vec3 f32_add_vec3(f32 self,Vec3 rhs);
const Vec3 vec3_sub(Vec3 self,Vec3 rhs);
void vec3_sub_assign(Vec3* self,Vec3 rhs);
const Vec3 vec3_sub_f32(Vec3 self,f32 rhs);
void vec3_sub_assign_f32(Vec3* self,f32 rhs);
const Vec3 f32_sub_vec3(f32 self,Vec3 rhs);
const Vec3 vec3_rem(Vec3 self,Vec3 rhs);
void vec3_rem_assign(Vec3* self,Vec3 rhs);
const Vec3 vec3_rem_f32(Vec3 self,f32 rhs);
void vec3_rem_assign_f32(Vec3* self,f32 rhs);
const Vec3 f32_rem_vec3(f32 self,Vec3 rhs);
const Vec3 vec3_neg(Vec3 self);
const f32* vec3_index(Vec3* self,usize index);
#ifdef _cplusplus
}
#endif


/// All zeroes.
#define VEC3_ZERO vec3_splat(0.0)

/// All ones.
#define VEC3_ONE vec3_splat(1.0)

/// All negative ones.
#define VEC3_NEG_ONE vec3_splat(-1.0)

/// All `F32_MIN`.
#define VEC3_MIN vec3_splat(F32_MIN)

/// All `F32_MAX`.
#define VEC3_MAX vec3_splat(F32_MAX)

/// All `F32_NAN`.
#define VEC3_NAN vec3_splat(F32_NAN)

/// All `F32_INFINITY`.
#define VEC3_INFINITY vec3_splat(F32_INFINITY)

/// All `F32_NEG_INFINITY`.
#define VEC3_NEG_INFINITY vec3_splat(F32_NEG_INFINITY)

/// A unit vector pointing along the positive X axis.
#define VEC3_X vec3_new(1.0,0.0,0.0)

/// A unit vector pointing along the positive Y axis.
#define VEC3_Y vec3_new(0.0,1.0,0.0)

/// A unit vector pointing along the positive Z axis.
#define VEC3_Z vec3_new(0.0,0.0,1.0)

/// A unit vector pointing along the negative X axis.
#define VEC3_NEG_X vec3_new(-1.0,0.0,0.0)

/// A unit vector pointing along the negative Y axis.
#define VEC3_NEG_Y vec3_new(0.0,-1.0,0.0)

/// A unit vector pointing along the negative Z axis.
#define VEC3_NEG_Z vec3_new(0.0,0.0,-1.0)

/// The unit axes.
#define VEC3_AXES {VEC3_X,VEC3_Y,VEC3_Z}

#endif
