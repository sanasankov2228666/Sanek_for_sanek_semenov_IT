#include <stdio.h>
#include <math.h>
#include "head.h"

//функция ввода
void input(struct parametrs* ptr_quadric)
{
    

    double list[3];
    char par[4] = {'a', 'b', 'c'};
    int cheacker = 0;
    printf("*** Write parametrs ***\n");    
    for(int index = 0; index < 3; ++index)
    {
        printf("%c coefficent = ", par[index]);
        cheacker = scanf("%lg", &list[index]);
        while(cheacker != 1)
        {
            while(getchar() != '\n');
            printf(ANSI_COLOR_RED"ERROR, try again\n"ANSI_COLOR_RESET);
            printf("%c coefficent = ", par[index]);
            cheacker = scanf("%lg", &list[index]);
        }
    }
    ptr_quadric->a = list[0];
    ptr_quadric->b = list[1];
    ptr_quadric->c = list[2];
}

//функция вывода
void output(int value, struct parametrs* ptr_quadric)
{
    switch(value)
    {
        case infinity_solution:
            printf("infinity solurions, x belongs to allrational numbers");
            break;
        case zero_solutions:
            printf("zero solutions");
            break;
        case one_solution:
            printf("one solution:\nx = %lg", ptr_quadric->x1);
            break;
        case two_solution:
            printf("two solutions:\nx1 = %g, x2 = %g", ptr_quadric->x1, ptr_quadric->x2);
            break;
    }
}