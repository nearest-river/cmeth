#ifndef CMETH_BVEC3_PRELUDE_H
#define CMETH_BVEC3_PRELUDE_H
#include "../prelude.h"

/// A 3-dimensional `bool` vector mask.
typedef struct {
  bool x;
  bool y;
  bool z;
} BVec3;


#ifdef _cplusplus
extern "C" {
#endif
/// Creates a 3-dimensional `bool` vector mask.
const BVec3 bvec3(bool x, bool y, bool z);

/// Creates a new vector mask.
const BVec3 bvec3_new(bool x, bool y, bool z);

/// Creates a vector mask with all elements set to `v`.
const BVec3 bvec3_splat(bool v);

/// Creates a vector mask with all elements set to `v`.
const BVec3 bvec3_from_array(bool a[3]);

/// Returns a bitmask with the lowest 3 bits set from the elements of `self`.
///
/// A true element results in a `1` bit and a false element in a `0` bit.  Element `x` goes
/// into the first lowest bit, element `y` into the second, etc.
const u32 bvec3_bitmask(const BVec3 self);

/// Returns true if any of the elements are true, false otherwise.
const bool bvec3_any(const BVec3 self);

/// Returns true if all the elements are true, false otherwise.
const bool bvec3_all(const BVec3 self);

/// Tests the value at `index`.
/// 
/// Panics if `index` is greater than 2.
const bool bvec3_test(const BVec3 self,usize index);

/// Sets the element at `index`.
///
/// Panics if `index` is greater than 2.
void bvec3_set(BVec3* self,usize index,bool value);




#ifdef _cplusplus
}
#endif


#define BVEC3_FALSE bvec3_splat(false)
#define BVEC3_TRUE bvec3_splat(true)



#endif
