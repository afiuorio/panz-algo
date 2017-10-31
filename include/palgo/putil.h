#ifndef PUTIL_H_
#define PUTIL_H_

#define PRAND_MAX 0x7fff

void p_srand(unsigned int seed);
int p_rand();

void *p_search(void *key,void *array, size_t num ,size_t size,int(*cmp)(const void *,const void *) );

char *p_strcpy(char *s, const char *ct);
char *p_strcat(char *s, const char *ct);
int p_strcmp(const char *cs, const char *ct);

#endif
