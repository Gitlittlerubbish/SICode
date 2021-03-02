#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n = rand() % 100;
	fprintf(stdout, "rand number is %d\n", n);
	return 0;
}
