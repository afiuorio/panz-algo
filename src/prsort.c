#include<stdlib.h>
#include<string.h>

int p_rsort(unsigned int *array, size_t n){
	register unsigned int i,q;
	unsigned int c;
	unsigned int *temp;
	void *exec;
	size_t counter[256];
	size_t index[256];

	temp = malloc ( sizeof(unsigned int) * n);
	if( temp == NULL)
		return -1;

	for( q = 0; q < sizeof(int); q++){

		memset(counter,0,sizeof(size_t) * 256);

		for(i = 0; i <n; i++){
			c = (array[i] >> (q << 3) ) &0xff;
			counter[c]++;
		}

		index[0] = 0;
		for( i = 1; i < 256; i++)
			index[i] = index[i-1] + counter[i-1];

		for( i = 0; i < n; i++){
			c = (array[i] >> (q << 3) ) &0xff;
			temp[ index[c]++] = array[i];
		}

		exec = array;
		array = temp;
		temp = exec;
	}
	free(temp);
	return n;
}
