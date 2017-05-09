#ifndef RNG_H_
#define RNG_H_

	#include <nanvix/const.h>

unsigned seed;

EXTERN int rand(void);
EXTERN void srand(unsigned _seed);

#endif