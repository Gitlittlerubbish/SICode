#include <stdio.h>

int main() 
{
	union {
		int i;
		char ch[4];
	}data;
	data.i = 64;
	printf("Result of int 64.\n");
	for (int i = 0; i < 4; i++) {
		printf("data:0x%02x @ memory:%p\n", data.ch[i], &data.ch[i]);
	}
	
	return 0;
}
