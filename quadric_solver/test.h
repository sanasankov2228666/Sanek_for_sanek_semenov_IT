#ifndef test
#define test

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

//проверка на NAN
int testnan(struct parametrs inarr[]);

//unit test helper
int help(struct parametrs inarr[], struct outtest_data outarr[]);

//unit test
int test_solvesquare();

#endif