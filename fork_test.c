#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int i;
	if (!fork()) {
		printf("Sub process created.\n");
		sleep(20);
	} else {
		printf("Father process: waiting for sub process terminating......\n");
		wait(&i);
	}
	printf("clock per second is %d\n", CLOCKS_PER_SEC);	
	return 0;
}
