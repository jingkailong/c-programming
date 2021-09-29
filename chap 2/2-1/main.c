#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables,
both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
 Harder if you compute them: determine the ranges of the various floating-point types.

 */
int main()
{
    printf("size of signed char max %d---min %d!\n",CHAR_MAX,CHAR_MIN);
    printf("size of unsigned char max %d---min %d\n",1<<CHAR_BIT,0);

    printf("size of signed short max %d---min %d\n",INT_MAX,INT_MIN);
    printf("size of unsigned short max %d---min %d\n",USHRT_MAX,0);

    printf("sizeof signed long max %ld--min %ld\n",LONG_MAX,LONG_MIN);
    printf("sizeof unsigned long max %lu--min %u\n",ULONG_MAX,0);

    return 0;
}
