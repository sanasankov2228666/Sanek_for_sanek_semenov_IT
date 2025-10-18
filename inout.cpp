#include <stdio.h>
#include <math.h>
#include "inout.h"
#include "struct.h"
#include "showsolve.h"

#define ZERO_SOLUTION 0
#define INFINITY_SOLUTION -1 
#define ONE_SOLUTION 1
#define TWO_SOLUTION 2   

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//функция ввода



/// @brief cxzczxc
/// @param ptr_quadric указатель на структуру параметров квадратного уравнения 
void input(struct parametrs* ptr_quadric)
{
    

    double list[3];
    char par[8] = {'a', 'b', 'c', '\0'};
    int cheacker = 0;
    printf("\n____________________________________________________________________________________________\n");
    printf("*** Write parametrs ***\n");  

    for(int index = 0; index < 3; ++index)
    {
        printf("%c coefficent = ", par[index]);
        cheacker = scanf("%lg", &list[index]);
        while(cheacker != 1)
        {
            while(getchar() != '\n');
            printf(ANSI_COLOR_RED "ERROR, try again\n" ANSI_COLOR_RESET);
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
    prettyuot(value, ptr_quadric);
    switch(value)
    {
        case INFINITY_SOLUTION:
            printf("infinity solurions, x belongs to allrational numbers\n");
            break;
        case ZERO_SOLUTION:
            printf("zero solutions\n");
            break;
        case ONE_SOLUTION:
            printf("one solution:\nx = %lg\n", ptr_quadric->x1);
            break;
        case TWO_SOLUTION:
            printf("two solutions:\nx1 = %g, x2 = %g\n", ptr_quadric->x1, ptr_quadric->x2);
            break;
        default:
            ;
    }
    printf("\n____________________________________________________________________________________________\n");
}