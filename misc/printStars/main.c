#include <stdio.h>
#include <stdlib.h>
//know about caret and tabstop.
int main()
{
    int i = 0;
    int j = 0;
    int t = 0;
    for (i = 0; i <= 5; i++) //each line
    {
        for (t = 0; t < 5-i; t++)   //blank ,caret to the next *.
        {
            putchar(' ');
        }
        for (j = 0; j <= 2*i; j++) //j < i means how many stars to print in each line.
        {

            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
