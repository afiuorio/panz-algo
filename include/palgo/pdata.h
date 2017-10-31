#ifndef PDATA_H_
#define PDATA_H_

void **alloc_pMatrix(size_t numRow, size_t numCol, size_t elem_size);
void free_pMatrix(void **matrix);

#endif
