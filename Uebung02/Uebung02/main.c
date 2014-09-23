#include <stdio.h>
#define MAX 10
#define DEBUG

int sum(int value){ if (value <= 1){ return 1; } return value + sum(value - 1); }

int main(){
	int i; int summe = 0;
	for (i = 1; i <= MAX; ++i){ summe += i; }
	printf("a: %d\n", summe);

	i = 1; summe = 0;
	while (i <= MAX){ summe += i; ++i; }
	printf("b: %d\n", summe);

	i = 1; summe = 0;
	do { summe += i; ++i; } while (i <= MAX);
	printf("c: %d\n", summe);

	printf("d: %d\n", sum(MAX));

	getchar();

#ifdef DEBUG
	printf("\n\nDEEEEEBUUUUG\n");
#else
	printf("\n\nNOT DEBUG!\n");
#endif

	getchar();

	return 0;
}