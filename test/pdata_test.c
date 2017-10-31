#include<stdio.h>
#include<palgo.h>

#define FOREACH(a,b) for(a=0; a < b; a++)

void test_matrix(){
    int** matrix = (int**) alloc_pMatrix(4,4,sizeof(int));
    int i, j;
    FOREACH(i,4)
        FOREACH(j,4)
            matrix[i][j] = 4*i+j;

    FOREACH(i,4){
        FOREACH(j,4)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    free_pMatrix((void**) matrix);
}

int main(){
	test_matrix();
}
