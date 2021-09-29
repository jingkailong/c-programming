#include <stdio.h>
#include <stdlib.h>
/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
*/
#define TAB_STOP 8 /* tab size */
int getPos(int Pos)
{
    return TAB_STOP - ((Pos-1) % TAB_STOP);
}
int main()
{
    int pos = 1; /* start of input */
    int ch;
    int numofBlanks = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch != '\t')
        {
            putchar(ch);
            pos++;
        }
        else if (ch == '\n')
        {
            putchar(ch);
            pos = 1;
        }
        else
        {
            numofBlanks = getPos(pos);
            pos = pos + numofBlanks;
            while (numofBlanks)
            {
                putchar('#');
                numofBlanks--;

            }

        }

    }

    return 0;
}

