#include "vec3.h"
#include "math_impl.h"
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
/// In other words this computes `[MIN(self.x,rhs.x), MIN(self.y,rhs.y), ..]`.
inline
const Vec3 vec3_min(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=MIN(self.x,rhs.x),
    .y=MIN(self.y,rhs.y),
    .z=MIN(self.z,rhs.z)
  };
  return vec;
}

/// Returns a vector containing the maximum values for each element of `self` and `rhs`.
///
/// In other words this computes `[MAX(self.x,rhs.x), MAX(self.y,rhs.y), ..]`.
inline
const Vec3 vec3_max(Vec3 self,Vec3 rhs) {
  Vec3 vec={
    .x=MAX(self.x,rhs.x),
    .y=MAX(self.y,rhs.y),
    .z=MAX(self.z,rhs.z)
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
/// In other words this computes `MIN(x, y, ..)`.
inline
const f32 vec3_min_element(Vec3 self) {
  return MIN(self.x,MIN(self.y,self.z));
}

/// Returns the horizontal maximum of `self`.
///
/// In other words this computes `MAX(x, y, ..)`.
inline
const f32 vec3_max_element(Vec3 self) {
  return MAX(self.x,MAX(self.y,self.z));
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
  return bvec3_new(f32_eq(self.x,rhs.x),f32_eq(self.y,rhs.y),f32_eq(self.z,rhs.z));
}

/// Returns a vector mask containing the result of a `!=` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x != rhs.x, self.y != rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmpne(Vec3 self,Vec3 rhs) {
  return bvec3_new(f32_ne(self.x,rhs.x),f32_ne(self.y,rhs.y),f32_ne(self.z,rhs.z));
}

/// Returns a vector mask containing the result of a `>=` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x >= rhs.x, self.y >= rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmpge(Vec3 self,Vec3 rhs) {
  return bvec3_new(f32_ge(self.x,rhs.x),f32_ge(self.y,rhs.y),f32_ge(self.z,rhs.z));
}

/// Returns a vector mask containing the result of a `>` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x > rhs.x, self.y > rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmpgt(Vec3 self,Vec3 rhs) {
  return bvec3_new(f32_gt(self.x,rhs.x),f32_gt(self.y,rhs.y),f32_gt(self.z,rhs.z));
}

/// Returns a vector mask containing the result of a `<=` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x <= rhs.x, self.y <= rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmple(Vec3 self,Vec3 rhs) {
  return bvec3_new(f32_le(self.x,rhs.x),f32_le(self.y,rhs.y),f32_le(self.z,rhs.z));
}


/// Returns a vector mask containing the result of a `<` comparison for each element of
/// `self` and `rhs`.
///
/// In other words this computes `[self.x < rhs.x, self.y < rhs.y, ..]` for all
/// elements.
inline
const BVec3 vec3_cmplt(Vec3 self,Vec3 rhs) {
  return bvec3_new(f32_lt(self.x,rhs.x),f32_lt(self.y,rhs.y),f32_lt(self.z,rhs.z));
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
/// Will panic if the resulting normalized vector is not finite when `cmeth_assert` is enabled.
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

/// Returns the vector projection of `self` onto `rhs`.
///
/// `rhs` must be of non-zero length.
///
/// # Panics
///
/// Will panic if `rhs` is zero length when `cmeth_assert` is enabled.
inline
const Vec3 vec3_project_into(Vec3 self,Vec3 rhs) {
  f32 other_len_sq_rcp=1/vec3_dot(rhs,rhs);
  cmeth_assert(f32_is_finite(other_len_sq_rcp));
  f32 x=vec3_dot(self,rhs)*other_len_sq_rcp;
  return vec3_mul_f32(self,x);
}

/// Returns the vector rejection of `self` from `rhs`.
///
/// The vector rejection is the vector perpendicular to the projection of `self` onto
/// `rhs`, in rhs words the result of `self - self.project_onto(rhs)`.
///
/// `rhs` must be of non-zero length.
///
/// # Panics
///
/// Will panic if `rhs` has a length of zero when `cmeth_assert` is enabled.
inline
const Vec3 vec3_reject_from(Vec3 self,Vec3 rhs) {
  Vec3 projection=vec3_project_into(self,rhs);
  return vec3_sub(self,projection);
}


/// Returns the vector projection of `self` onto `rhs`.
///
/// `rhs` must be normalized.
///
/// # Panics
///
/// Will panic if `rhs` is not normalized when `cmeth_assert` is enabled.
inline
const Vec3 vec3_project_onto_normalized(Vec3 self,Vec3 rhs) {
  cmeth_assert(vec3_is_normalized(rhs));
  f32 x=vec3_dot(self,rhs);
  return vec3_mul_f32(self,x);
}


/// Returns the vector rejection of `self` from `rhs`.
///
 /// The vector rejection is the vector perpendicular to the projection of `self` onto
/// `rhs`, in rhs words the result of `self - self.project_onto(rhs)`.
///
/// `rhs` must be normalized.
///
/// # Panics
///
/// Will panic if `rhs` is not normalized when `cmeth_assert` is enabled.
inline
const Vec3 vec3_reject_from_normalized(Vec3 self,Vec3 rhs) {
  Vec3 projection=vec3_project_onto_normalized(self,rhs);
  return vec3_sub(self,projection);
}

/// Returns a vector containing the nearest integer to a number for each element of `self`.
/// Round half-way cases away from 0.0.
inline
const Vec3 vec3_round(Vec3 self) {
  Vec3 vec={
    .x=f32_round(self.x),
    .y=f32_round(self.y),
    .z=f32_round(self.z)
  };

  return vec;
}

/// Returns a vector containing the largest integer less than or equal to a number for each
/// element of `self`.
inline
const Vec3 vec3_floor(Vec3 self) {
  Vec3 vec={
    .x=f32_floor(self.x),
    .y=f32_floor(self.y),
    .z=f32_floor(self.z)
  };

  return vec;
}

/// Returns a vector containing the smallest integer greater than or equal to a number for
/// each element of `self`.
inline
const Vec3 vec3_ceil(Vec3 self) {
  Vec3 vec={
    .x=f32_ceil(self.x),
    .y=f32_ceil(self.y),
    .z=f32_ceil(self.z)
  };

  return vec;
}

/// Returns a vector containing the integer part each element of `self`. This means numbers are
/// always truncated towards zero.
inline
const Vec3 vec3_trunc(Vec3 self) {
  Vec3 vec={
    .x=f32_trunc(self.x),
    .y=f32_trunc(self.y),
    .z=f32_trunc(self.z)
  };

  return vec;
}

/// Returns a vector containing the fractional part of the vector as `vec3_sub(self,vec3_trunc(self))`.
///
/// Note that this differs from the GLSL implementation of `fract` which returns
/// `vec3_sub(self,vec3_floor(self))`.
///
/// Note that this is fast but not precise for large numbers.
inline
const Vec3 vec3_fract(Vec3 self) {
  Vec3 truncated=vec3_trunc(self);
  return vec3_sub(self,truncated);
}

/// Returns a vector containing the fractional part of the vector as `vec3_sub(self,vec3_floor(self))`.
///
/// Note that this differs from the Rust implementation of `fract` which returns
/// `vec3_sub(self,vec3_trunc(self))`.
///
/// Note that this is fast but not precise for large numbers.
inline
const Vec3 vec3_fract_gl(Vec3 self) {
  Vec3 floored=vec3_floor(self);
  return vec3_sub(self,floored);
}

/// Returns a vector containing `e^self` (the exponential function) for each element of
/// `self`.
inline
const Vec3 vec3_exp(Vec3 self) {
  Vec3 vec={
    .x=f32_exp(self.x),
    .y=f32_exp(self.y),
    .z=f32_exp(self.z)
  };

  return vec;
}

/// Returns a vector containing each element of `self` raised to the power of `n`.
inline
const Vec3 vec3_pow(Vec3 self,f32 n) {
  Vec3 vec={
    .x=f32_pow(self.x,n),
    .y=f32_pow(self.y,n),
    .z=f32_pow(self.z,n)
  };

  return vec;
}

/// Returns a vector containing the reciprocal `1.0/n` of each element of `self`.
inline
const Vec3 vec3_recip(Vec3 self) {
  Vec3 vec={
    .x=1.0f/self.x,
    .y=1.0f/self.y,
    .z=1.0f/self.z
  };

  return vec;
}

/// Performs a linear interpolation between `self` and `rhs` based on the value `s`.
///
/// When `s` is `0.0`, the result will be equal to `self`.  When `s` is `1.0`, the result
/// will be equal to `rhs`. When `s` is outside of range `[0, 1]`, the result is linearly
/// extrapolated.
inline
const Vec3 vec3_lerp(Vec3 self,Vec3 rhs,f32 s) {
  Vec3 srhs=vec3_mul_f32(rhs,s);
  Vec3 s_1_self=vec3_mul_f32(self,(1.0f - s));
  return vec3_add(s_1_self,srhs);
}

  /// Moves towards `rhs` based on the value `d`.
  ///
  /// When `d` is `0.0`, the result will be equal to `self`. When `d` is equal to
  /// `vec3_distance(self,rhs)`, the result will be equal to `rhs`. Will not go past `rhs`.
  inline
  const Vec3 vec3_move_towards(Vec3* self,Vec3 rhs,f32 d) {
    Vec3 a=vec3_sub(rhs,*self);
    f32 len=vec3_len(a);
    if(len<=d || len<=1e-4) {
      return rhs;
    }

    return vec3_div_f32(vec3_add(*self,a),len+d);
  }

  /// Calculates the midpoint between `self` and `rhs`.
  ///
  /// The midpoint is the average of, or halfway point between, two vectors.
  /// `vec3_midpoint(a,b)` should yield the same result as `vec3_lerp(a, b, 0.5)`
  /// while being slightly cheaper to compute.
  inline
  const Vec3 vec3_midpoint(Vec3 self,Vec3 rhs) {
    return vec3_mul_f32(vec3_add(self,rhs),0.5);
  }

  /// Returns true if the absolute difference of all elements between `self` and `rhs` is
  /// less than or equal to `max_abs_diff`.
  ///
  /// This can be used to compare if two vectors contain similar elements. It works best when
  /// comparing with a known value. The `max_abs_diff` that should be used used depends on
  /// the values being compared against.
  ///
  /// For more see
  /// [comparing floating point numbers](https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/).
  inline
  const bool vec3_abs_diff_eq(Vec3 self,Vec3 rhs,f32 max_abs_diff) {
    Vec3 abs_diff=vec3_abs(vec3_sub(self,rhs));
    BVec3 mask=vec3_cmple(abs_diff,vec3_splat(max_abs_diff));
    return bvec3_all(mask);
  }

inline_always
const Vec3 _x_self_over_len(Vec3 self,f32 x,f32 len_sq) {
  f32 len=f32_sqrt(len_sq);
  Vec3 self_over_len=vec3_div_f32(self,len);
  return vec3_mul_f32(self_over_len,x);
}

  /// Returns a vector with a length no less than `min` and no more than `max`.
  ///
  /// # Panics
  ///
  /// Will panic if `min` is greater than `max`, or if either `min` or `max` is negative, when `cmeth_assert` is enabled.
  inline
  const Vec3 vec3_clamp_length(Vec3 self,f32 min,f32 max) {
    cmeth_assert(0.0 <= min);
    cmeth_assert(min <= max);
    f32 length_sq=vec3_len_squared(self);

    if(length_sq < min * min) {
      return _x_self_over_len(self,min,length_sq);
    } else if(length_sq > max * max) {
      return _x_self_over_len(self,max,length_sq);
    } else {
      return self;
    }
  }

  /// Returns a vector with a length no more than `max`.
  ///
  /// # Panics
  ///
  /// Will panic if `max` is negative when `cmeth_assert` is enabled.
  inline
  const Vec3 vec3_clamp_length_max(Vec3 self,f32 max) {
    cmeth_assert(0.0 <= max);
    f32 length_sq=vec3_len_squared(self);
    return (length_sq > max * max)? _x_self_over_len(self,max,length_sq) : self;
  }

  /// Returns a vector with a length no less than `min`.
  ///
  /// # Panics
  ///
  /// Will panic if `min` is negative when `cmeth_assert` is enabled.
  inline
  const Vec3 vec3_clamp_length_min(Vec3 self, f32 min) {
    cmeth_assert(0.0 <= min);
    f32 length_sq=vec3_len_squared(self);
    return (length_sq < min * min)? _x_self_over_len(self,min,length_sq) : self;
  }

  /// Fused multiply-add. Computes `vec3_add(vec3_mul(self,a),b)` element-wise with only one rounding
  /// error, yielding a more accurate result than an unfused multiply-add.
  ///
  /// Using `vec3_mul_add` *may* be more performant than an unfused multiply-add if the target
  /// architecture has a dedicated fma CPU instruction. However, this is not always true,
  /// and will be heavily dependant on designing algorithms with specific target hardware in
  /// mind.
  inline
  const Vec3 vec3_mul_add(Vec3 self,Vec3 a,Vec3 b) {
    Vec3 vec={
      .x=f32_mul_add(self.x, a.x, b.x),
      .y=f32_mul_add(self.y, a.y, b.y),
      .z=f32_mul_add(self.z, a.z, b.z)
    };

    return vec;
  }

  /// Returns the reflection vector for a given incident vector `self` and surface normal
  /// `normal`.
  ///
  /// `normal` must be normalized.
  ///
  /// # Panics
  ///
  /// Will panic if `normal` is not normalized when `cmeth_assert` is enabled.
  inline
  const Vec3 vec3_reflect(Vec3 self,Vec3 normal) {
    cmeth_assert(vec3_is_normalized(normal));
    f32 self_dot_normal=vec3_dot(self,normal);
    return vec3_sub(self,f32_mul_vec3(2.0f * self_dot_normal,normal));
  }

  /// Returns the refraction direction for a given incident vector `self`, surface normal
  /// `normal` and ratio of indices of refraction, `eta`. When total internal reflection occurs,
  /// a zero vector will be returned.
  ///
  /// `self` and `normal` must be normalized.
  ///
  /// # Panics
  ///
  /// Will panic if `self` or `normal` is not normalized when `cmeth_assert` is enabled.
  inline
  const Vec3 vec3_refract(Vec3 self,Vec3 normal,f32 eta) {
    cmeth_assert(vec3_is_normalized(self));
    cmeth_assert(vec3_is_normalized(normal));
    f32 n_dot_i=vec3_dot(normal,self);
    f32 k=1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if(k>=0.0f) {
      // eta * self - (eta * n_dot_i + f32_sqrt(k)) * normal
      return vec3_sub(f32_mul_vec3(eta,self),f32_mul_vec3((eta*n_dot_i+f32_sqrt(k)),normal));
    } else {
      return VEC3_ZERO;
    }
  }

  /// Returns the angle (in radians) between two vectors in the range `[0, +π]`.
  ///
  /// The inputs do not need to be unit vectors however they must be non-zero.
  inline
  const f32 vec3_angle_between(Vec3 self,Vec3 rhs) {
    //math::acos_approx(
    //  self.dot(rhs)
    //    .div(math::sqrt(self.length_squared().mul(rhs.length_squared()))),
    //);

    return 0;
  }

  /// Returns some vector that is orthogonal to the given one.
  ///
  /// The input vector must be finite and non-zero.
  ///
  /// The output vector is not necessarily unit length. For that use
  /// [`Self::any_orthonormal_vector()`] instead.
  inline
  const Vec3 vec3_any_orthogonal_vector(Vec3* self) {
    // This can probably be optimized
    if math::abs(self.x) > math::abs(self.y) {
      Self::new(-self.z, 0.0, self.x) // self.cross(Self::Y)
    } else {
      Self::new(0.0, self.z, -self.y) // self.cross(Self::X)
    }
  }

  /// Returns any unit vector that is orthogonal to the given one.
  ///
  /// The input vector must be unit length.
  ///
  /// # Panics
  ///
  /// Will panic if `self` is not normalized when `cmeth_assert` is enabled.
  inline
  const Vec3 vec3_any_orthonormal_vector(Vec3* self) {
    cmeth_assert(self.is_normalized());
    // From https://graphics.pixar.com/library/OrthonormalB/paper.pdf
    let sign=math::signum(self.z);
    let a=-1.0 / (sign + self.z);
    let b=self.x * self.y * a;
    Self::new(b, sign + self.y * self.y * a, -self.y)
  }

  /// Given a unit vector return two other vectors that together form an orthonormal
  /// basis. That is, all three vectors are orthogonal to each other and are normalized.
  ///
  /// # Panics
  ///
  /// Will panic if `self` is not normalized when `cmeth_assert` is enabled.
  inline
  const Vec3 vec3_any_orthonormal_pair(Vec3* self) -> (Vec3 self, Self) {
    cmeth_assert(self.is_normalized());
    // From https://graphics.pixar.com/library/OrthonormalB/paper.pdf
    let sign=math::signum(self.z);
    let a=-1.0 / (sign + self.z);
    let b=self.x * self.y * a;
    (
      Self::new(1.0 + sign * self.x * self.x * a, sign * b, -sign * self.x),
      Self::new(b, sign + self.y * self.y * a, -self.y),
    )
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
    case 0: return Vec3* self->x;
    case 1: return Vec3* self->y;
    case 2: return Vec3* self->z;
    default: panic("index out of bounds");
  }
}
































