#include<stdio.h>
#include<palgo.h>
#include<math.h>

void test_sqrt(){
	printf("%.13f\n", p_sqrt(2));
	printf("%.13f\n", p_sqrt(3.14));
	printf("%.13f\n", p_sqrt(25));
	printf("%.13f\n", p_sqrt(196));
	printf("%.13f\n", p_sqrt(2000));
}

void test_cordic(){
	printf("%.13f\n", p_cos(2));
	printf("%.13f\n", p_cos(3.14159265358979323846));
	printf("%.13f\n", p_cos(1.5));
	printf("%.13f\n", p_cos(3* 3.14159265358979323846));
	printf("%.13f\n", p_sin(2));
	//printf("%.16f\n", p_sin(3.14159265358979323846));
	printf("%.13f\n", p_sin(1.5));
	//printf("%.16f\n", p_sin(3* 3.14159265358979323846));
}

int main(){
	test_cordic();
	test_sqrt();
}
