#ifndef CMETH_PRELUDE_H
#define CMETH_PRELUDE_H

#include "../include/cprimitives/src/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define inline_always __inline __attribute__ ((__always_inline__))
#define min(X,Y) ((X)<(Y))?(X):(Y)
#define max(X,Y) ((X)>(Y))?(X):(Y)
#define panic(...) { fprintf(stderr,__VA_ARGS__);exit(1); }
#define cmeth_assert(...) assert(__VA_ARGS__)



#endif
