#ifndef SOLVER
#define SOLVER

#include "struct.h"

//функия проверки нуля
int error(double a);

//функция дискриминант
double discr(double a, double b, double c);

//фунция решающая квадратное кравнение
int quadratic_solver(struct parametrs* ptr_quadric);

#endif