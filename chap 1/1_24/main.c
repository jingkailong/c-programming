#include <stdio.h>
#include <stdlib.h>
/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)

*/
typedef enum StateE
{
    UNMATCHED = 0,
    MATCHED,
}StateE;
int main()
{
    //1,read a c programme
    //2,check unmatched perentheses
    char* s = "][{";
    char* t;
    int state = UNMATCHED;
    char* begin = s;
    char startCh = ' ';
    while (*s != '\0')
    {
        if (*s == '[')
        {
            startCh = *s;
            t = s;
            while (*t != '\0')
            {
                if (*t == ']')
                {
                    state = MATCHED;
                    break;
                }
                t++;
            }
            if (state == UNMATCHED)
            {
                printf("error,unmatched,for %c\n",startCh);
            }
        }
        else if (*s == ']')
        {
            t = s;
            startCh = *s;
            /* step backwords */
            while (t != begin)
            {
                if (*t == '[')
                {
                    state = MATCHED;
                    break;
                }
                t--;
            }
            if (state == UNMATCHED)
            {
                printf("unmatched char is %c\n",startCh);
            }

        }
        s++;
    }

    return 0;
}
