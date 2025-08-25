#include <stdio.h>
#include <math.h>
#include "head.h"

//функия проверки нуля
int error(double a)
{
    if (fabs(a) < 0.00000000000001)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//функция дискриминант

double discr(double a, double b, double c)
{
    return(b*b - 4*a*c);
}

//фунция решающая квадратное кравнение

int quadratic_solver(struct parametrs* ptr_quadric)
{
    double d = discr( ptr_quadric->a, ptr_quadric->b, ptr_quadric->c);
    if (error( ptr_quadric->a))
    {
        if (error(ptr_quadric->b))
        {
            if (error(ptr_quadric->c))
            {
                return -1;
            }
            //если a=0,b=0,c не 0
            return 0;
        }
        //если a=0, b и c не 0
        else
        {
            ptr_quadric->x1 = (-ptr_quadric->c)/(ptr_quadric->b);
            return 1;
        }
    }
    //если коэффиценты не 0
    else
    {
        //если дискриминант = 0
        if(error(d))
        {
            ptr_quadric->x1 = (-ptr_quadric->b)/(2*ptr_quadric->a);
            return 1;
        }
        //если дискриминант < 0
        if(d < 0)
        {
            return 0;
        }
        //если дискриминант не 0 и коэффиценты не 0
        ptr_quadric->x1 = (-ptr_quadric->b + sqrt(d))/(2*ptr_quadric->a);
        ptr_quadric->x2 = (-ptr_quadric->b - sqrt(d))/(2*ptr_quadric->a);
        if (ptr_quadric->x1 > ptr_quadric->x2)
        {
            ptr_quadric->x1 = (-ptr_quadric->b - sqrt(d))/(2*ptr_quadric->a);
            ptr_quadric->x2 = (-ptr_quadric->b + sqrt(d))/(2*ptr_quadric->a);
        }
        return 2;   
    }
}
