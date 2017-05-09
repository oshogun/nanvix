#include <nanvix/rng.h>

/* Based on the glibc implementation of rand() */
PUBLIC int rand() {
	unsigned next = seed;
	int result;

	next*= 103515245;
	next+= 12345;
	result = (unsigned) (next / 65536) % 2048;

	next *= 1103515245;
	next += 12345;
	result <<= 10;
	result ^= (unsigned int) (next / 65536) % 1024;

	next *= 1103515245;
	next += 12345;
	result <<= 10;
	result ^= (unsigned int) (next / 65536) % 1024;

	seed = next;
	return result;
}

PUBLIC void srand(unsigned _seed) {
	seed = _seed;
}