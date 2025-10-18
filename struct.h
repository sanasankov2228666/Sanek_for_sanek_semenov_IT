#ifndef STRUCTURE
#define STRUCTURE

typedef double coef;
typedef double root;
typedef int root_number;

//создание структура
struct parametrs
{
    coef a;
    coef b;
    coef c;
    root x1;
    root x2;
};

//создание структуры
struct outtest_data
{
    root x1;
    root x2;
    root_number res;
};

#endif