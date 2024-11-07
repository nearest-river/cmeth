#include "bvec3.h"

/// Creates a 3-dimensional `bool` vector mask.
inline_always
const BVec3 bvec3(bool x, bool y, bool z) {
  return bvec3_new(x,y,z);
}

/// Creates a new vector mask.
inline_always
const BVec3 bvec3_new(bool x, bool y, bool z) {
  BVec3 vec={
    .x=x,
    .y=y,
    .z=z
  };
  return vec;
}

/// Creates a vector mask with all elements set to `v`.
inline
const BVec3 bvec3_splat(bool v) {
  return bvec3_new(v,v,v);
}

/// Creates a new vector mask from a bool array.
inline
const BVec3 bvec3_from_array(bool a[3]) {
  return bvec3_new(a[0],a[1],a[2]);
}

/// Returns a bitmask with the lowest 3 bits set from the elements of `self`.
///
/// A true element results in a `1` bit and a false element in a `0` bit.  Element `x` goes
/// into the first lowest bit, element `y` into the second, etc.
inline
const u32 bvec3_bitmask(const BVec3 self) {
  return ((u32)(self.x)) | ((u32)(self.y)) << 1 | ((u32)(self.z)) << 2;
}

/// Returns true if any of the elements are true, false otherwise.
inline
const bool bvec3_any(const BVec3 self) {
  return self.x || self.y || self.z;
}

/// Returns true if all the elements are true, false otherwise.
inline
const bool bvec3_all(const BVec3 self) {
  return self.x && self.y && self.z;
}

/// Tests the value at `index`.
/// 
/// Panics if `index` is greater than 2.
inline
const bool bvec3_test(const BVec3 self,usize index) {
  switch(index) {
    case 0: return self.x;
    case 1: return self.y;
    case 2: return self.z;
    default: panic("index out of bounds")
  }
}

/// Sets the element at `index`.
///
/// Panics if `index` is greater than 2.
inline
void bvec3_set(BVec3* self,usize index,bool value) {
  switch(index) {
    case 0:
      self->x=value;
    break;
    case 1:
      self->y=value;
    break;
    case 2:
      self->z=value;
    break;
    default: panic("index out of bounds")
  }
}

inline_always
const BVec3 bvec3_default() {
  return BVEC3_FALSE;
}

inline
const BVec3 bvec3_bitand(const BVec3 self,const BVec3 rhs) {
  const BVec3 vec={
    .x=self.x&rhs.x,
    .y=self.y&rhs.y,
    .z=self.z&rhs.z
  };

  return vec;
}

inline
void bvec3_bitand_assign(BVec3* self,const BVec3 rhs) {
  self->x&=rhs.x;
  self->y&=rhs.y;
  self->z&=rhs.z;
}

inline
const BVec3 bvec3_bitor(const BVec3 self,const BVec3 rhs) {
  const BVec3 vec={
    .x=self.x|rhs.x,
    .y=self.y|rhs.y,
    .z=self.z|rhs.z
  };

  return vec;
}

inline
void bvec3_bitor_assign(BVec3* self,const BVec3 rhs) {
  self->x|=rhs.x;
  self->y|=rhs.y;
  self->z|=rhs.z;
}

const BVec3 bvec3_bitxor(const BVec3 self,const BVec3 rhs) {
  const BVec3 vec={
    .x=self.x^rhs.x,
    .y=self.y^rhs.y,
    .z=self.z^rhs.z
  };

  return vec;
}

inline
void bvec3_bitxor_assign(BVec3* self,const BVec3 rhs) {
  self->x^=rhs.x;
  self->y^=rhs.y;
  self->z^=rhs.z;
}

const BVec3 bvec3_bitnot(const BVec3 self) {
  const BVec3 vec={
    .x=!self.x,
    .y=!self.y,
    .z=!self.z
  };

  return vec;
}










