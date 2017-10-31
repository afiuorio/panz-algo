#include<stdio.h>
#include<palgo.h>

#define PRINT_ARRAY do{ \
    int i = 0; \
	for(i=0;i< 14; i++) \
		printf("%d,", array[i]); \
    printf("\n"); \
} while(0)

int cmpfunc (const void * a, const void * b)
{
   return ( *((int*)a) - *((int*)b) );
}

void test_quicksort(){
    int array[14] = { 2, 453,443, 665, 433, 322, 11, 34, 245, 243, 664, 34564,213245, 1002};
	p_sort(array, 14, sizeof(int), cmpfunc);
	PRINT_ARRAY;
}

void test_insertionSort(){
    int array[14] = { 2, 453,443, 665, 433, 322, 11, 34, 245, 243, 664, 34564,213245, 1002};
	p_isort(array, 14, sizeof(int), cmpfunc);
	PRINT_ARRAY;
}

void test_radixSort(){
    unsigned int array[14] = { 2, 453,443, 665, 433, 322, 11, 34, 245, 243, 664, 34564,213245, 1002};
	p_rsort(array, 14);
	PRINT_ARRAY;
}

int main(){
    test_quicksort();
    test_radixSort();
    test_insertionSort();
}
