#ifndef solver
#define solver

//создание структура
struct parametrs
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
};

//создание структуры
struct outtest_data
{
    double x1;
    double x2;
    int res;
};

//функия проверки нуля
int error(double a);

//функция дискриминант
double discr(double a, double b, double c);

//фунция решающая квадратное кравнение
int quadratic_solver(struct parametrs* ptr_quadric);

#endif