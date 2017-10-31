#ifndef PSORT_H_
#define PSORT_H_

void p_sort(void *base, size_t n, size_t size, int(*cmp)(const void *,const void *));

void p_isort(void *base, size_t n, size_t size,int(*cmp)(const void*,const void*));

int p_rsort(unsigned int *array, size_t n);

#endif
