#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dinamicmassiv.h"

//измерение размера файла входных данных
unsigned long int check_sizein(void)
{
    FILE* ptr;
    ptr = fopen("data.txt","r");
    fseek(ptr,0, SEEK_END);
    long int len = ftell(ptr);
    fclose(ptr);
    return (unsigned long int)len;
}

//измерение размера файла выходных данных
unsigned long int check_sizeout(void)
{
    FILE* ptr;
    ptr = fopen("dataout.txt","r");
    fseek(ptr,0, SEEK_END);
    long int len = ftell(ptr);
    fclose(ptr);
    return (unsigned long int)len;
}


//динамические массивы входных данных
char* dinamicdatain()
{
    unsigned long int size = check_sizein();
    char* str = (char*)calloc(size + 1,sizeof(char));
    FILE* ptr = fopen("data.txt","r");
    fread(str, 1,size, ptr);
    return str;
}

//динамические массивы выходных данных
char* dinamicdataout()
{
    unsigned long int size = check_sizeout();
    char* str = (char*)calloc(size + 1, sizeof(char));
    FILE* ptr = fopen("dataout.txt","r");
    fread(str, 1,size, ptr);
    return str;
}