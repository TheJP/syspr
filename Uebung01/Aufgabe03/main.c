#include <stdio.h>

void main(){
	for (char a = 0; a <= 126; a++){
		printf("+---+-+\n");
		printf("|%3d|%c|\n", a, a);
	}
	printf("+---+-+\n");
	getchar();
}