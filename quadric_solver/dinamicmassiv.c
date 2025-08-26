#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//измерение размера файла входных данных
int check_sizein(void)
{
    FILE* ptr;
    ptr = fopen("data.txt","r");
    fseek(ptr,0, SEEK_END);
    int len = ftell(ptr);
    fclose(ptr);
    return len;
}

//измерение размера файла выходных данных
int check_sizeout(void)
{
    FILE* ptr;
    ptr = fopen("dataout.txt","r");
    fseek(ptr,0, SEEK_END);
    int len = ftell(ptr);
    fclose(ptr);
    return len;
}

//динамические массивы входных данных
char* dinamicdatain()
{
    int size = check_sizein();
    char* str = (char*)calloc(size,1);
    FILE* ptr = fopen("data.txt","r");
    fread(str, 1,size+1, ptr);
    return str;
}

//динамические массивы выходных данных
char* dinamicdataout()
{
    int size = check_sizeout();
    char* str = (char*)calloc(size,1);
    FILE* ptr = fopen("dataout.txt","r");
    fread(str, 1,size+1, ptr);
    return str;
}