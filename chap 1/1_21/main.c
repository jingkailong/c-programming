#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?
*/
#define TAB_STOP 8

int getPos(int Pos) /* cal the offset to the tab stop */
{
    return (TAB_STOP - (Pos% TAB_STOP));
}
int main()
{
    int ch;
    int offset = 0;
    int pos = 1;
    int numofBlanks = 0;

    while ((ch = getchar()) != EOF)
    {
        pos++;
        offset = getPos(pos);

        if (ch == '\n')
        {
            pos = 1;
            putchar(ch);
        }

        else if (isspace(ch))
        {

            numofBlanks++;
            if ((numofBlanks == offset) || (numofBlanks == TAB_STOP))
            {
                putchar('\t');
                numofBlanks = 0;
            }
        }
        else
        {
            putchar(ch);
        }





    }
    return 0;
}
