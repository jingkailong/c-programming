#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_BUF_SIZE 100
/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero.
Fix it to push such a character back on the input. */
int getint(int* pn);
int main()
{
     int n;
     getint(&n);
     printf("%d\n",n);
    return 0;
}

int pos = 0;
char buff[MAX_BUF_SIZE];
int getch(void)
{

    return (pos > 0)?buff[--pos]:getchar();
}

void ungetch(int ch)
{
    if (pos >= MAX_BUF_SIZE)
    {
        printf("too many chars\n");
    }
    buff[pos++] = ch; /* point to next available slot */

}

int getint(int* pn)
{
    int ch,sign;
    int d; /* remember the sign */

    if (pn == NULL)
    {
        return -1;
    }

    sign = 1;
    *pn = 0;

    while ((ch = getch()) ==' ' || ch == '\t')
    {
        ; /* skip white space */
    }

    if (!isdigit(ch) && ch !=EOF && ch != '-' && ch != '+')
    {
        printf("not valid for converting\n");
        ungetch(ch);
        return 0;

    }
    if (ch =='-' || ch == '+')
    {
        d = ch;
        if (ch == '-')
            sign = -1;
        if (!isdigit(ch = getch()))
        {
            if (ch != EOF)
                ungetch(ch);
            ungetch(d);
            return ch;
        }

    }

    while (isdigit(ch = getch()))
    {
        *pn = *pn * 10 + (ch -'0');
    }

    *pn *= sign;
    if (ch != EOF)
    {
        ungetch(ch);
        return ch;
    }
    return 0;

}
