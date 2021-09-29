#include <stdio.h>
#include <stdlib.h>

/*
Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/

#define MAXCOL 35
#define TAB_SIZE 8
#define CURTAB(c) (TABSIZE - (c%TAB_SIZE))

int main()
{
    int pos = 0;
    int ch;


    while ((ch = getchar() )!= EOF)
    {
        pos++;
        putchar(ch);
        if (ch == '\n')
        {
            pos = 0;
        }
        if ((pos%MAXCOL) == 0)
        {
            putchar('\n');
            pos = 0;
        }

    }

    return 0;
}
