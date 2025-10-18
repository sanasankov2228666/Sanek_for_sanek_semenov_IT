#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//ассерт


/// @brief фанкция "ассерт"
/// @param n условие: 0 - вывввб, 1 - авава.
/// @return ничего не возвращает (говнокод)
int erroriftrue(int n)
{
    if (n == 1)
    {
        printf("ERROR ASSERT\n");
        exit(1);
    }
}
