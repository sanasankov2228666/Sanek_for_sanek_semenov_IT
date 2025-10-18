#include <stdio.h>
#include <math.h>
#include "struct.h"
#include "solver.h"
#include "showsolve.h"

#define ZERO_SOLUTION 0
#define INFINITY_SOLUTION -1
#define ONE_SOLUTION 1
#define TWO_SOLUTION 2

void prettyuot(int a, struct parametrs* ptr_quadric)
{
    switch(a)
    {
        case INFINITY_SOLUTION:
            printf("%lgx^2 + %lgx + %lg = 0\n0 = 0\n",ptr_quadric->a, ptr_quadric->b, ptr_quadric->c);
            break;
        case ZERO_SOLUTION:
            printf("%lgx^2 + %lgx + %lg = 0\nD = (%lg)^2 - 4*%lg*%lg, %lg < 0\n",
            ptr_quadric->a, ptr_quadric->b, ptr_quadric->c, ptr_quadric->b, ptr_quadric->a, ptr_quadric->c,
            discr(ptr_quadric->a,ptr_quadric->b,ptr_quadric->c));
            break;
        case ONE_SOLUTION:
            printf("%lgx^2 + %lgx + %lg = 0\nD = (%lg)^2 - 4*%lg*%lg, %lg = 0\nx = -%lg/(2*%lg)\n",
            ptr_quadric->a, ptr_quadric->b, ptr_quadric->c, ptr_quadric->b, ptr_quadric->a, ptr_quadric->c,
            discr(ptr_quadric->a,ptr_quadric->b,ptr_quadric->c), ptr_quadric->b, ptr_quadric->a);
            break;
        case TWO_SOLUTION:
            printf("%lgx^2 + %lgx + %lg = 0\nD = (%lg)^2 - 4*%lg*%lg\nx1 = (-%lg + sqrt(%lg))/(2*%lg)\nx1 = (-%lg - sqrt(%lg))/(2*%lg)\n",
            ptr_quadric->a, ptr_quadric->b, ptr_quadric->c, ptr_quadric->b, ptr_quadric->a, ptr_quadric->c,
            ptr_quadric->b, discr(ptr_quadric->a,ptr_quadric->b,ptr_quadric->c), ptr_quadric->a, 
            ptr_quadric->b, discr(ptr_quadric->a,ptr_quadric->b,ptr_quadric->c), ptr_quadric->a );
            break;
        default:
            ;
    }
}