//(пррграмма)
//! программа для решения квадратного уравнения
//! a, b, c - коэффиценты
//! х1 и х2 - корни уравнения 
//! после надписи write parametrs нужно написать коэффиценты уравнения 
//! после каждого введённого коэфицента нажать ENTER
//! вводить символы нельзя
//
//(про тетст)
//! при запучке требуется выбрать тест либо сама программа
//! для проведения теста необходимо записать в файл data.txt данные для входа в формате a, b, c, NAN, NAN(enter для следующего)
//! в файл dataout.txt нужно внести правильные решения с котрыми тестер будет сравнивать программу в формате x1, x2, количесто корней
//! меньший из корней x1 должен быть x2, если коорень один то x2 = NAN, если корней нет или пустое множество то x1 = NAN, x2 = NAN
//! 
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "inout.h"
#include "solver.h"
#include "dinamicmassiv.h"
#include "test.h"
#include "openprogram.h"
#include "struct.h"
#include "showsolve.h"

#define ZERO_SOLUTION 0
#define INFINITY_SOLUTION -1
#define ONE_SOLUTION 1
#define TWO_SOLUTION 2

//main функция
int main()
{
    //создание структуры
    struct parametrs quadric = {};
    
    printf(ANSI_COLOR_BLUE "*** It is program for solving quadric equalation ***\n" ANSI_COLOR_RESET);
    //цикл возращающий программу к выбору
    int n = 1;
    while (n == 1)
    {
        //запуск программы
        int choose = program();
        switch (choose)
        {
            case 1:
            {
                test_solvesquare();
                break;
            }
            case 2:
            {
                //функция ввода
                input(&quadric);
    
                //функция решения уравнения
                int value = quadratic_solver(&quadric);

                //функция вывода
                output(value, &quadric);
                break;
            }
            default:
            {
                ;
            }                
        }
        printf("\n*** Press '1' for return for choice, press '2' for exit ***\n");
        int k = scanf("%d", &n);
        while((k != 1) || (n < 1 || n > 2))
        {
            while(getchar() != '\n');
            printf(ANSI_COLOR_RED "ERROR try again\n" ANSI_COLOR_RESET);
            printf("\n*** Press '1' for return for choice, press '2' for exit ***\n");
            k = scanf("%d", &n);
            printf("%d",n);
        }

    }
    getchar();
    getchar();
    return 0;
}
