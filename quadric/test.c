#include <stdio.h>
#include <math.h>
#include "head.h"

//


//функция выбора программы
int program()
{
    int choose = 0;
    printf("*** What you want? ***\n1 - Test program\n2 - Open program\n");
    scanf("%d",&choose);
    while(choose != 1 && choose != 2)
    {
        while(getchar() != '\n');
        printf(ANSI_COLOR_RED"ERROR try again\n"ANSI_COLOR_RESET);
        printf("*** What you want? ***\n1 - Test program\n2 - Open program\n");
        scanf("%d",&choose);
    }
    return choose;
}


 //проверка на NAN
int testnan(struct parametrs inarr[])
{
    int i= 0;   //вспомогательный индекс
    int numnumber = 0;
    if (isnan(inarr[i].x2))
    {
        numnumber++;
    }
    
    if (isnan(inarr[i].x1))
    {
        numnumber++;
    }
    i++;
    return numnumber;
}

//unit test helper
int help(struct parametrs inarr[], struct outtest_data outarr[])
{
    int i= 0;   //вспомогательный индекс
    int var = quadratic_solver(&inarr[i]);
    if(var != outarr[i].res)
    {
        printf(ANSI_COLOR_RED"FALSE\n"ANSI_COLOR_RESET);
        printf("x1 = %lg, x2 = %lg, n = %d\n",inarr[i].x1, inarr[i].x2, var);
    }
    else
    {   
        if(inarr[i].x1 == outarr[i].x1 && inarr[i].x2 == outarr[i].x2)
        {
            printf(ANSI_COLOR_GREEN"TRUE\n"ANSI_COLOR_RESET);
        }
        else
        {
            if((testnan(&inarr[i])) == 1)
            {
                if(inarr[i].x1 == outarr[i].x1 && isnan(outarr[i].x1) == 0)
                {
                    printf(ANSI_COLOR_GREEN"TRUE\n"ANSI_COLOR_RESET);
                }
                else
                {
                    printf(ANSI_COLOR_RED"FALSE\n"ANSI_COLOR_RESET);
                    printf("x1 = %lg, x2 = %lg, %d\n",inarr[i].x1, inarr[i].x2, var);
                }
            }
            else if (testnan(&inarr[i]) == 2 && (outarr[i].res == 0 || outarr[i].res == -1))
            {
                printf(ANSI_COLOR_GREEN"TRUE\n"ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED"FALSE\n"ANSI_COLOR_RESET);
                printf("x1 = %lg, x2 = %lg, %d\n",inarr[i].x1, inarr[i].x2, var);
            }
            i++;
        }
    }
}

//makefiles

//unit test
int test_solvesquare() 
{
    //массив структур входных данных
    struct parametrs inarr[4];

    FILE* ptrin = fopen("data.txt","r");
    char my_filein[200];

    fread(my_filein, 1,199, ptrin);

    int nin = 0, posin = 0;

    for (int index = 0; index < 4;index++ )
    {
        sscanf(my_filein + posin,"%lg, %lg, %lg, %lg, %lg%n", &inarr[index].a, &inarr[index].b, &inarr[index].c, &inarr[index].x1, &inarr[index].x2, &nin);
        posin += nin;
    }

    //массив структур входных данных
    struct outtest_data outarr[4];

    FILE* ptrout = fopen("dataout.txt","r");
    char my_fileout[200];

    fread(my_fileout, 1,199, ptrout);


    int posout = 0, nout = 0;

    for (int index = 0; index < 4;index++ )
    {
        sscanf(my_fileout + posout,"%lg, %lg, %d%n", &outarr[index].x1, &outarr[index].x2, &outarr[index].res, &nout);
        posout += nout;
    }

    //вывод тестов
    for(int index = 0; index < 4; index++)
    {
        printf("TEST %d:\n",index + 1);
        help(&inarr[index], &outarr[index]);
    }
    return 0;
}

