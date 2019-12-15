#include "stack.h"
#include "stacktype.h"
#include <stdio.h>
#include <stdlib.h>

void readvalue(stackelem_t * elemp){
	float result  = 0;
	char buf[100];
	while(result != 1){
		printf("Type an int:");
		fgets(buf, sizeof(buf), stdin);
		result = sscanf(buf, "%f", elemp);
	}
}

void printvalue(stackelem_t elem){
	printf("%f", elem);
}
