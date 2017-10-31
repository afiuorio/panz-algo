/* A simple LCG (linear congruential generator) implementation. */

static unsigned int __p_seed = 1;

void p_srand(unsigned int seed)
{
	__p_seed = seed;
}

int p_rand()
{
	__p_seed = ( (__p_seed * 513) +1 ) & 0x7fff;
	return __p_seed;
}
