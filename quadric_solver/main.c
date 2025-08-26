//
//! программа для решения квадратного уравнения
//! a, b, c - коэффиценты
//! х1 и х2 - корни уравнения 
//! после надписи write parametrs нужно написать коэффиценты уравнения 
//! после каждого введённого коэфицента нажать ENTER
//! вводить символы нельзя
//! gcc quadic.c test.c solver.c inout.c -o file name (компилирование)
//! .\file name
//


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "inout.h"
#include "solver.h"
#include "dinamicmassiv.h"
#include "test.h"
#include "openprogram.h"


#define zero_solutions 0
#define infinity_solution -1 
#define one_solution 1
#define two_solution 2  

//main функция
int main(void)
{
    //создание структуры
    struct parametrs quadric = {};      //struct parametrs quadric = {0, 0, 0, 0, 0};
    
    printf(ANSI_COLOR_BLUE"*** It is program for solving quadric equalation ***\n"ANSI_COLOR_RESET);
    //цикл возращающий программу к выбору
    int n = 1;
    while (n == 1)
    {

        //запуск программы
        int choose = program();
        switch (choose)
        {
            case 1:
                test_solvesquare();
                break;
    
            case 2:
            //функция ввода
            input(&quadric);
    
            //функция решения уравнения
            int value = quadratic_solver(&quadric);

            //функция вывода
            output(value, &quadric);
        }
        printf("\n*** Press '1' for return for choice, press '2' for exit ***\n");
        int k = scanf("%d", &n);
        while((k != 1) || (n < 1 || n > 2))
        {
            while(getchar() != '\n');
            printf(ANSI_COLOR_RED"ERROR try again\n"ANSI_COLOR_RESET);
            printf("\n*** Press '1' for return for choice, press '2' for exit ***\n");
            k = scanf("%d", &n);
            printf("%d",n);
        }

    }
    getchar();
    getchar();
    return 0;
}
