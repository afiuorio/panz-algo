#include<stdio.h>

#define __SWAP(a,b,size) do \
{ \
	char temp, *al = a, *bl = b; \
	size_t s = size;\
	do{	\
		temp = *al; \
		*al = *bl;	\
		*bl = temp;	\
		al++;bl++;	\
	} while(--s > 0);	\
} while(0)

#define __array(index) array + (index*size)

void p_isort(void *array, size_t n, size_t size,int(*cmp)(const void*,const void*))
{
	size_t i, j, min_index;
	for(i=0;i<n;i++){
		min_index = i;
		for(j= i; j < n; j++){
			if(cmp(__array(min_index), __array(j)) > 0  )
				min_index = j;
		}
		__SWAP(__array(min_index), __array(i), size);
	}
}
