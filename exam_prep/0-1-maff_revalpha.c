#include <unistd.h>

int main(void)
{
	int counter = 0;
	char c;

	while (counter < 26)
	{
		c = 'z' - counter;
		if (counter % 2 == 1)
		{
			c = c - 'z' + 'Z';
		}
		write(1, &c, 1);
		counter++;
	}
	write(1, "\n", 1);
}
