
#include <stdio.h>
#include <math.h>
#include "openprogram.h"

//функция выбора программы
int program()
{
    int choose = 0;
    printf("*** What you want? ***\n1 - Test program\n2 - Open program\n");
    scanf("%d",&choose);
    while(choose != 1 && choose != 2)
    {
        while(getchar() != '\n');
        printf(ANSI_COLOR_RED"ERROR try again\n"ANSI_COLOR_RESET);
        printf("*** What you want? ***\n1 - Test program\n2 - Open program\n");
        scanf("%d",&choose);
    }
    return choose;
}