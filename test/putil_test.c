#include<stdio.h>
#include<palgo.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *((int*)a) - *((int*)b) );
}

void test_bsearch(){
    int array[14] = { 2,11,34,243,245,322,433,443,453,664,665,1002,34564,213245};
    int key = 34;
	int *k = (int *)p_search(&key,array,14, sizeof(int), cmpfunc);
    printf("%ld\n", k-array);
}

void test_string(){
    char *a = "Hello";
    char *b = "World";
    char c[32];

    p_strcpy(c,a);
    printf("%s\n",c);

    p_strcat(c,b);
    printf("%s\n",c);

    int i = p_strcmp(c,a);
    printf("%d\n",i);

}

int main(){
	test_bsearch();
    test_string();
}
