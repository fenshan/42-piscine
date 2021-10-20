//to test the time that takes a loop from 1 to 2^31
#include <unistd.h>
int main(void)
{
	int i = 0;
	while (i < 2147483647)
		++i;
	write(1, "finished\n", 8);
	return (0);
}
