#include <stdio.h>
#include <string.h>

#define fast_time_5(num) \
({ \
	register int __res;  \
	__asm__("leal (%%eax, %%eax, 4), %%eax" \
			:"=a" (__res)	 \
			:"%%eax" (num)   \
		   );			 \
	__res;})

int main()
{	
	int a = 5;
	a = fast_time_5(a);
	printf("The number after fast_time_5 is: %d, original number is: %d\n", a, 5);
	return 0;
}
