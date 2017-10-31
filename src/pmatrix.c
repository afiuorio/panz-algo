#include <stdlib.h>

void **alloc_pMatrix(size_t numRow, size_t numCol, size_t elem_size){
	void **matrix = malloc( sizeof(void *) * numCol + (numRow * numCol * elem_size));
	if(!matrix)
		return matrix;
	void *data = matrix + sizeof(void *) * numCol;
	size_t i;
	for(i=0; i < numRow; i++, data +=numCol * elem_size)
		matrix[i] = data;
	return matrix;
}

void free_pMatrix(void **matrix){
	free(matrix);
}
