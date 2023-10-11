//gcc -o executavel principal.c implementacao.c
//or
//make
#include <stdlib.h>
#include <stdio.h>
#include "data.h"


int main(int argc,char *argv[]) {

	int i = 0;
	printf("argc %d\n",argc);

	for(i=0; i<argc; i++)
		printf("argv %s\n", argv[i]);

	return 0;
}
