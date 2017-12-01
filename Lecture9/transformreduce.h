#ifndef TRANSFORM_REDUCE_H
#define TRANSFORM_REDUCE_H

#if defined(_OPENMP)
#include "transformreduce_multicore.h"
#else
#include "transformreduce_singlecore.h"
#endif

#endif
