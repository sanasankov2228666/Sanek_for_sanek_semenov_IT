#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//ассерт
int erroriftrue(int n)
{
    if (n == 1)
    {
        printf("ERROR ASSERT\n");
        exit(1);
    }
}