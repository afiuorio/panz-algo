#include<math.h>

#define NUM_ITERATION 50

#define __CORDIC do{ \
    double __cordicAngles [] =  { \
    		0.785398163397448, 0.463647609000806, 0.244978663126864, 0.124354994546761, 0.062418809995957, 0.031239833430268, 0.015623728620477, \
			0.007812341060101, 0.003906230131967, 0.001953122516479, 0.000976562189559, 0.000488281211195, 0.000244140620149, 0.000122070311894, \
			0.000061035156174, 0.000030517578116, 0.000015258789061, 0.000007629394531, 0.000003814697266, 0.000001907348633, 0.000000953674316, \
			0.000000476837158, 0.000000238418579, 0.000000119209290, 0.000000059604645, 0.000000029802322, 0.000000014901161, 0.000000007450581, \
			0.000000003725290, 0.000000001862645, 0.000000000931323, 0.000000000465661, 0.000000000232831, 0.000000000116415, 0.000000000058208, \
			0.000000000029104, 0.000000000014552, 0.000000000007276, 0.000000000003638, 0.000000000001819, 0.000000000000909, 0.000000000000455, \
			0.000000000000227, 0.000000000000114, 0.000000000000057, 0.000000000000028, 0.000000000000014, 0.000000000000007, 0.000000000000004, \
			0.000000000000002 }; \
 \
    double ang = __cordicAngles[0]; \
	double newX, newY; \
	double powerTwo = 1.0; \
	double sign; \
	register unsigned int i; \
    double final_sign = 1.0; \
    x = fmod(x, 2.0 * M_PI); \
    if( x < M_PI / 2.0 || x > M_PI /2.0) {\
        if(x < 0) \
            x = x + M_PI; \
        else  \
            x = x - M_PI; \
    final_sign = -1.0;} \
 \
	for(i=0; i < NUM_ITERATION; i++){ \
		sign = x < 0 ? -1.0: 1.0; \
		x -= sign * ang; \
		ang = __cordicAngles[i+1]; \
		newX = __pCordicValue[0] - ( __pCordicValue[1] * sign * powerTwo );	 \
		newY = ( __pCordicValue[0] * sign * powerTwo ) + __pCordicValue[1]; \
		powerTwo /= 2; \
		__pCordicValue[0] = newX; \
		__pCordicValue[1] = newY; \
	} \
    __pCordicValue[0]*=final_sign; \
    __pCordicValue[1]*=final_sign; \
} while(0)

double p_cos(double x){
    double __pCordicValue[2] = {1,0};
    __CORDIC;
    return 	__pCordicValue[0]*0.60725293500888;
}

double p_sin(double x){
    double __pCordicValue[2] = {1,0};
    __CORDIC;
    return __pCordicValue[1]*0.60725293500888;
}

#undef __CORDIC
#undef NUM_ITERATION
