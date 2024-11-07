#include "vec3.h"
#include "prelude.h"


/// Creates a 3-dimensional vector.
inline_always
const Vec3 vec3(f32 x,f32 y,f32 z) {
  return vec3_new(x,y,z);
}

/// Creates a new vector.
inline_always
const Vec3 vec3_new(f32 x,f32 y,f32 z) {
  Vec3 vec={
    .x=x,
    .y=y,
    .z=z
  };
  return vec;
}

/// Creates a vector with all elements set to `v`.
inline
const Vec3 vec3_splat(f32 v) {
  Vec3 vec={
    .x=v,
    .y=v,
    .z=v
  };
  return vec;
}

/// Creates a vector from the elements in `if_true` and `if_false`, selecting which to use
/// for each element of `self`.
///
/// A true element in the mask uses the corresponding element from `if_true`, and false
/// uses the element from `if_false`.
inline
const Vec3 vec3_select(BVec3 mask,Vec3 if_true,Vec3 if_false) {
  Vec3 vec={
    .x=bvec3_test(mask,0)? if_true.x : if_false.x,
    .y=bvec3_test(mask,1)? if_true.y : if_false.y,
    .z=bvec3_test(mask,2)? if_true.z : if_false.z,
  };

  return vec;
}

/// Returns a vector containing each element of `self` modified by a mapping function `f`.
inline
const Vec3 vec3_map(Vec3 self,f32 (*f)(f32)) {
  self.x=f(self.x);
  self.y=f(self.y);
  self.z=f(self.z);
  return self;
}

/// Creates a new vector from an array.
inline
const Vec3 vec3_from_array(f64 a[3]) {
  Vec3 vec={
    .x=a[0],
    .y=a[1],
    .z=a[2]
  };
  return vec;
}

/// writes the elements of `self` to the first 3 elements in `slice`.
///
/// # panics
///
///panics if `slice` is less than 3 elements long.
inline
void vec3_write_to_slice(Vec3 self,f32* slice) {
  slice[0]=self.x;
  slice[1]=self.y;
  slice[2]=self.z;
}

// TODO
/// Internal method for creating a 3D vector from a 4D vector, discarding `w`.
inline
const Vec3 vec3_from_vec4(f32 v[4]) {
  Vec3 vec={
    .x=v[0],
    .y=v[1],
    .z=v[2]
  };
  return vec;
}

/// Creates a 3D vector from `self` with the given value of `x`.
inline
const Vec3 vec3_with_x(Vec3 self,f32 x) {
  self.x=x;
  return self;
}

/// Creates a 3D vector from `self` with the given value of `y`.
inline
const Vec3 vec3_with_y(Vec3 self,f32 y) {
  self.y=y;
  return self;
}

/// Creates a 3D vector from `self` with the given value of `z`.
inline
const Vec3 vec3_with_z(Vec3 self,f32 z) {
  self.z=z;
  return self;
}

/// Computes the dot product of `self` and `rhs`.
inline
const f32 vec3_dot(Vec3 self,Vec3 rhs) {
  return (self.x*rhs.x)+(self.y*rhs.y)+(self.z*rhs.z);
}

/// Returns a vector where every component is the dot product of `self` and `rhs`.
inline
const Vec3 vec3_dot_into_vec(Vec3 self,Vec3 rhs) {
  return vec3_splat(vec3_dot(self,rhs));
}

/// Computes the cross product of `self` and `rhs`.
inline
const Vec3 vec3_cross(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=self.y * rhs.z - rhs.y * self.z,
    .y=self.z * rhs.x - rhs.z * self.x,
    .z=self.x * rhs.y - rhs.x * self.y,
  };

  return vec;
}

/// Returns a vector containing the minimum values for each element of `self` and `rhs`.
///
/// In other words this computes `[min(self.x,rhs.x), min(self.y,rhs.y), ..]`.
inline
const Vec3 vec3_min(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=min(self.x,rhs.x),
    .y=min(self.y,rhs.y),
    .z=min(self.z,rhs.z)
  };
  return vec;
}

/// Returns a vector containing the maximum values for each element of `self` and `rhs`.
///
/// In other words this computes `[max(self.x,rhs.x), max(self.y,rhs.y), ..]`.
inline
const Vec3 vec3_max(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=max(self.x,rhs.x),
    .y=max(self.y,rhs.y),
    .z=max(self.z,rhs.z)
  };
  return vec;
}

/// Component-wise clamping of values, similar to `f32_clamp`.
///
/// Each element in `min` must be less-or-equal to the corresponding element in `max`.
///
/// # Panics
 ///
/// Will panic if `min` is greater than `max` when `cmeth_assert` is enabled.
inline
const Vec3 vec3_clamp(Vec3 self,Vec3 min,Vec3 max) {
  cmeth_assert(bvec3_all(vec3_cmple(min,max)));
  return vec3_min(vec3_max(self,min),max);
}

/// Returns the horizontal minimum of `self`.
///
/// In other words this computes `min(x, y, ..)`.
inline
const f32 vec3_min_element(Vec3 self) {
  return min(self.x,min(self.y,self.z));
}

/// Returns the horizontal maximum of `self`.
///
/// In other words this computes `max(x, y, ..)`.
inline
const f32 vec3_max_element(Vec3 self) {
  return max(self.x,max(self.y,self.z));
}

/// Returns the sum of all elements of `self`.
///
/// In other words, this computes `self.x + self.y + ..`.
inline
const f32 vec3_element_sum(Vec3 self) {
  return self.x+self.y+self.z;
}

/// Returns the product of all elements of `self`.
///
/// In other words, this computes `self.x * self.y * ..`.
inline
const f32 vec3_element_product(Vec3 self) {
  return self.x*self.y*self.z;
}

/// Returns a vector mask containing the result of a `==` comparison for each element of
/// `self` and `rhs`.
///
/// In other words, this computes `[self.x == rhs.x, self.y == rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmpeq(Vec3 self,Vec3 rhs) {
  return bvec3_new(self.x==rhs.x,self.y==rhs.y,self.z==rhs.z);
}

/// Returns a vector mask containing the result of a `!=` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x != rhs.x, self.y != rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmpne(Vec3 self,Vec3 rhs) {
  return bvec3_new(self.x!=rhs.x,self.y!=rhs.y,self.z!=rhs.z);
}

/// Returns a vector mask containing the result of a `>=` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x >= rhs.x, self.y >= rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmpge(Vec3 self,Vec3 rhs) {
  return bvec3_new(self.x>=rhs.x,self.y>=rhs.y,self.z>=rhs.z);
}

/// Returns a vector mask containing the result of a `>` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x > rhs.x, self.y > rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmpgt(Vec3 self,Vec3 rhs) {
  return bvec3_new(self.x>rhs.x,self.y>rhs.y,self.z>rhs.z);
}

/// Returns a vector mask containing the result of a `<=` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x <= rhs.x, self.y <= rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmple(Vec3 self,Vec3 rhs) {
  return bvec3_new(self.x<=rhs.x,self.y<=rhs.y,self.z<=rhs.z);
}


/// Returns a vector mask containing the result of a `<` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x < rhs.x, self.y < rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmplt(Vec3 self,Vec3 rhs) {
  return bvec3_new(self.x<rhs.x,self.y<rhs.y,self.z<rhs.z);
}

/// Returns a vector containing the absolute value of each element of `self`.
inline
const Vec3 vec3_abs(Vec3 self) {
  Vec3 vec={
    .x=f32_abs(self.x),
    .y=f32_abs(self.y),
    .z=f32_abs(self.z)
  };

  return vec;
}

/// Returns a vector with elements representing the sign of `self`.
///
/// - `1.0` if the number is positive, `+0.0` or `INFINITY`
/// - `-1.0` if the number is negative, `-0.0` or `NEG_INFINITY`
/// - `NAN` if the number is `NAN`
inline
const Vec3 vec3_signum(Vec3 self) {
  Vec3 vec={
    .x=f32_signum(self.x),
    .y=f32_signum(self.y),
    .z=f32_signum(self.z)
  };

  return vec;
}

/// Returns a vector with signs of `rhs` and the magnitudes of `self`.
inline
const Vec3 vec3_copysign(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_copysign(self.x,rhs.x),
    .y=f32_copysign(self.y,rhs.y),
    .z=f32_copysign(self.z,rhs.z)
  };

  return vec;
}

/// Returns a bitmask with the lowest 3 bits set to the sign bits from the elements of `self`.
///
/// A negative element results in a `1` bit and a positive element in a `0` bit.  Element `x` goes
/// into the first lowest bit, element `y` into the second, etc.
inline
const u32 vec3_is_negative_bitmask(Vec3 self) {
  return ((u32)f32_is_sign_negative(self.x))
  | ((u32)f32_is_sign_negative(self.y)) << 1
  | ((u32)f32_is_sign_negative(self.z)) << 2;
}

/// Returns `true` if, and only if, all elements are finite.  If any element is either
/// `NaN`, positive or negative infinity, this will return `false`.
inline
const bool vec3_is_finite(Vec3 self) {
  return f32_is_finite(self.x) && f32_is_finite(self.y) && f32_is_finite(self.z);
}

/// Returns `true` if any elements are `NaN`.
inline
const bool vec3_is_nan(Vec3 self) {
  return f32_is_nan(self.x) && f32_is_nan(self.y) && f32_is_nan(self.z);
}

/// Computes the length of `self`.
inline
const f32 vec3_len(Vec3 self) {
  return f32_sqrt(vec3_dot(self,self));
}

/// Computes the squared length of `self`.
///
/// This is faster than `vec3_len` as it avoids a square root operation.
inline
const f32 vec3_len_squared(Vec3 self) {
  return vec3_dot(self,self);
}

/// Computes `1.0 / length()`.
///
/// For valid results, `self` must _not_ be of length zero.
inline
const f32 vec3_len_recip(Vec3 self) {
  return 1.0F/vec3_len(self);
}

/// Computes the Euclidean distance between two points in space.
inline
const f32 vec3_distance(Vec3 self,Vec3 rhs) {
  return vec3_len(vec3_sub(self,rhs));
}

/// Compute the squared euclidean distance between two points in space.
inline
const f32 vec3_distance_squared(Vec3 self,Vec3 rhs) {
  return vec3_len_squared(vec3_sub(self,rhs));
}

/// Returns the element-wise quotient of [Euclidean division] of `self` by `rhs`.
inline
const Vec3 vec3_div_euclid(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_div_euclid(self.x,rhs.x),
    .y=f32_div_euclid(self.y,rhs.y),
    .z=f32_div_euclid(self.z,rhs.z)
  };

  return vec;
}

/// Returns the element-wise remainder of [Euclidean division] of `self` by `rhs`.
///
/// [Euclidean division]: f32_rem_euclid
inline
const Vec3 vec3_rem_euclid(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=f32_rem_euclid(self.x,rhs.x),
    .y=f32_rem_euclid(self.y,rhs.y),
    .z=f32_rem_euclid(self.z,rhs.z)
  };

  return vec;
}

/// Returns `self` normalized to length 1.0.
///
/// For valid results, `self` must be finite and _not_ of length zero, nor very close to zero.
///
/// See also [`Self::try_normalize()`] and [`Self::normalize_or_zero()`].
///
/// Panics
///
/// Will panic if the resulting normalized vector is not finite when `glam_assert` is enabled.
inline
const Vec3 vec3_normalize(Vec3 self) {
  Vec3 normalized=vec3_mul_f32(self,vec3_len_recip(self));
  assert(vec3_is_finite(normalized));
  return normalized;
}

/// Returns `self` normalized to length 1.0 if possible, else returns a
/// fallback value.
///
/// In particular, if the input is zero (or very close to zero), or non-finite,
/// the result of this operation will be the fallback value.
///
/// See also [`vec3_try_normalize()`].
inline
const Vec3 vec3_normalize_or(Vec3 self,Vec3 fallback) {
  f32 rcp=vec3_len_recip(self);
  return f32_is_finite(rcp) && rcp>0.0?vec3_mul_f32(self,rcp):fallback;
}

/// Returns `self` normalized to length 1.0 if possible, else returns zero.
///
/// In particular, if the input is zero (or very close to zero), or non-finite,
/// the result of this operation will be zero.
///
/// See also [`vec3_try_normalize()`].
inline
const Vec3 vec3_normalize_or_zero(Vec3 self) {
  return vec3_normalize_or(self,VEC3_ZERO);
}

/// Returns whether `self` is length `1.0` or not.
///
/// Uses a precision threshold of approximately `1e-4`.
inline
const bool vec3_is_normalized(Vec3 self) {
  return f32_abs(vec3_len_squared(self) - 1.0) <= 2e-4;
}

inline_always
const Vec3 vec3_default() {
  return VEC3_ZERO;
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

inline
const f32* vec3_index(Vec3* self,usize index) {
  switch(index) {
    case 0: return &self->x;
    case 1: return &self->y;
    case 2: return &self->z;
    default: panic("index out of bounds");
  }
}
































