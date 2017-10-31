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

#define __PUSH(base, l,h) do{ \
	*(base++) = l; \
	*(base++) = h; \
}while(0);

#define __POP(base, l,h) do{ \
	h = *(--base); \
	l = *(--base); \
}while(0);

size_t __part(void *array, size_t p, size_t q, size_t size, int (*cmp)(const void *, const void *)){
	size_t i = p+1;
	size_t j = q;
	while(i<=j){
		while( cmp(__array(j),__array(p)) > 0 ) j--;
		while( cmp(__array(i),__array(p)) <= 0 && i<=j) i++;
		if(i<j){
			__SWAP(__array(i), __array(j), size);
			i++;
			j--;
		}
	}
	__SWAP(__array(p),__array(j), size);
	return j;
}

void p_sort(void *base, size_t n, size_t size, int(*cmp)(const void *,const void *)){
	size_t stack [8 * sizeof(size_t)];
	size_t *top = stack;
	size_t p = 0, q = n-1;

	__PUSH(top, p,q);
	while(stack < top){
		__POP(top, p,q);
		while(p<q){
			size_t l = __part(base,p,q,size,cmp);
			if(l==0)
				p=1;
			else if( l-p < q-l){
				__PUSH(top, l+1,q);
				q = l-1;
			}
			else{
				__PUSH(top, p,l-1);
				p= l+1;
			}
		}
	}
}
