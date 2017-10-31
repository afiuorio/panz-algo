#include<stdio.h>

char *p_strcpy(char *s, const char *ct){
	size_t i = 0;
	while(ct[i] !='\0'){
		s[i] = ct[i];
		i++;
	}
	s[i] = '\0';
	return s;
}

char *p_strcat(char *s, const char *ct){
	char *dest = s;
	while( *dest++ != '\0' );
	dest--;
	p_strcpy(dest,ct);

	return s;
}

int p_strcmp(const char *cs, const char *ct){
	size_t i;

	for( i = 0; cs[i] == ct[i] && cs[i] != '\0'; i++);

	return cs[i] - ct[i];
}
