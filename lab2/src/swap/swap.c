#include "swap.h"

void Swap(char *left, char *right)
{
	// ваш код здесь
    char buf;
    buf = *left;
    *left = *right;
    *right = buf;
}
