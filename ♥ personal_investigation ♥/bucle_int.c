#include <unistd.h>

//Program useful to calculate the time that takes to loop from 1 to 2^31 (about 3 seconds)
//(which is weird bc 10^6 instructions are generally expected to take 1 second, and 2^31 ~ 2*10^9)
int main(void)
{
	int i = 0;
	while (i < 2147483647)
		++i;
	write(1, "finished\n", 9); //shout=out to my bro jcobos-d! without him, an eol would still be needed 
	return (0);
}
