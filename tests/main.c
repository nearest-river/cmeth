#include "../src/f32/vec3.h"
#include <stdio.h>

int main() {
  Vec3 xd=vec3_splat(1.0F);

  printf("x: %f, y: %f, z: %f\n",xd.x,xd.y,xd.z);

  return 0;
}

