#ifndef inout
#define inout

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

//функция ввода
void input(struct parametrs* ptr_quadric);

//функция вывода
void output(int value, struct parametrs* ptr_quadric);

#endif