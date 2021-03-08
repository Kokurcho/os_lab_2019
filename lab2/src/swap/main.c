#include <stdio.h>

#include "swap.h"

int main()
{
	char ch1 = 'a';
	char ch2 = 'b';

	Swap(&ch1, &ch2);

	printf("%c %c\n", ch1, ch2);
	return 0;
    //если шо использовал gcc -o SwapProgram main.c swap.c swap.h для компиляции
}
