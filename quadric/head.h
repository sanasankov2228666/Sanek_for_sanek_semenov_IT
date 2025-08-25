#ifndef Quadratca_prototyps
#define Quadratca_prototyps

#define zero_solutions 0
#define infinity_solution -1 
#define one_solution 1
#define two_solution 2  
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


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


//прототип ассемпер
int erroriftrue(int n);

//прототип quadratic_solver
int quadratic_solver(struct parametrs* ptr_quadric);

//функция выбора программы
int program();

//проверка на NAN
int testnan(struct parametrs* test);

//unit test helper
int help(struct parametrs* test, struct outtest_data* outtest);

//unit test
int test_solvesquare();

//функция соединения выбора и теста
int start();

//функция вывода
void output(int value, struct parametrs* ptr_quadric);

//функия проверки нуля
int error(double a);

//функция ввода
void input(struct parametrs* ptr_quadric);

//функция дискриминант
double discr(double a, double b, double c);

//фунция решающая квадратное кравнение
int quadratic_solver(struct parametrs* ptr_quadric);
#endif