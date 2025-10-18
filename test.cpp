#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "solver.h"
#include "dinamicmassiv.h"
#include "test.h"

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
void help(struct parametrs inarr[], struct outtest_data outarr[])
{
    int i= 0;   //вспомогательный индекс
    int var = quadratic_solver(&inarr[i]);
    if(var != outarr[i].res)
    {
        printf(ANSI_COLOR_RED "FALSE\n" ANSI_COLOR_RESET);
        printf("x1 = %lg, x2 = %lg, n = %d\n",inarr[i].x1, inarr[i].x2, var);
    }
    else
    {   
        if(error(inarr[i].x1) == error(outarr[i].x1) && error(inarr[i].x2) == error(outarr[i].x2))
        {
            printf(ANSI_COLOR_GREEN "TRUE\n" ANSI_COLOR_RESET);
        }
        else
        {
            if((testnan(&inarr[i])) == 1)
            {
                if(error(inarr[i].x1) == error(outarr[i].x1) && isnan(outarr[i].x1) == 0)
                {
                    printf(ANSI_COLOR_GREEN "TRUE\n" ANSI_COLOR_RESET);
                }
                else
                {
                    printf(ANSI_COLOR_RED "FALSE\n" ANSI_COLOR_RESET);
                    printf("x1 = %lg, x2 = %lg, %d\n",inarr[i].x1, inarr[i].x2, var);
                }
            }
            else if (testnan(&inarr[i]) == 2 && (outarr[i].res == 0 || outarr[i].res == -1))
            {
                printf(ANSI_COLOR_GREEN "TRUE\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED "FALSE\n" ANSI_COLOR_RESET);
                printf("x1 = %lg, x2 = %lg, %d\n",inarr[i].x1, inarr[i].x2, var);
            }
            i++;
        }
    }
}

//! unit test
int test_solvesquare() 
{
    //массив структур входных данных
    FILE* ptrin = fopen("data.txt","r");
    char* my_filein = dinamicdatain();

    fread(my_filein, 1,check_sizein(), ptrin);

    int iin = 0;
    unsigned long int numberin =  1;

    while (my_filein[iin] != '\0')
    {
        if(my_filein[iin] == '\n')
        {
            numberin++;
        }
        iin++;
    }

    struct parametrs* inarr = (struct parametrs*)calloc(numberin, sizeof(struct parametrs));

    int nin = 0, posin = 0;
    
    for (unsigned long int index = 0; index < numberin ;index++ )
    {
        sscanf(my_filein + posin,"%lg, %lg, %lg, %lg, %lg%n", &inarr[index].a, &inarr[index].b, &inarr[index].c, &inarr[index].x1, &inarr[index].x2, &nin);
        posin += nin;
    }
    free(my_filein);

    //массив структур выходных данных
    FILE* ptrout = fopen("dataout.txt","r");
    char* my_fileout = dinamicdataout();

    fread(my_fileout, 1,check_sizeout(), ptrout);

    int iout = 0;
    unsigned long int numberout =  1;

    while (my_fileout[iout] != '\0')
    {
        if(my_fileout[iout] == '\n')
        {
            numberout++;
        }

        iout++;
    }

    struct outtest_data* outarr = (struct outtest_data*)calloc(numberout,sizeof(struct outtest_data));

    int posout = 0, nout = 0;

    for (unsigned long int index = 0; index < numberout;index++ )
    {
        sscanf(my_fileout + posout,"%lg, %lg, %d%n", &outarr[index].x1, &outarr[index].x2, &outarr[index].res, &nout);
        posout += nout;
    }
    
    free(my_fileout);
    
    if (numberin != numberout)
    {
        printf(ANSI_COLOR_RED "ERROR in test data\n" ANSI_COLOR_RESET);
        return 0;
    }
    //вывод тестов
    printf("____________________________________________________________________________________________\n");
    for(unsigned long int index = 0; index < numberout; index++)
    {
        printf("TEST %lu:\n",index + 1);
        help(&inarr[index], &outarr[index]);
    }
    printf("____________________________________________________________________________________________\n");
    free(inarr);
    free(outarr);
    return 0;
}


