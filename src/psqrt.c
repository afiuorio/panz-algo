#include<math.h>

#define _POW(x) x*x

double p_sqrt(double n)
{
	double next = 1.0, prec = 0;
	do{
		prec = next;
		next =(_POW(next) + n) / (2* next);
	} while( fabs(next - prec)  > 0.0000000000005);
	return next;
}

#undef _POW
