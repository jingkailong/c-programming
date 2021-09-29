#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
/*
Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest
*/

typedef enum commE
{
    OUT_COMMENT_STATE = 0,
    IN_COMMENT_STATE,
}commStateE;
int main()
{
    int ch;
    int preCh;
    int state = OUT_COMMENT_STATE;

    while ((ch = getchar()) != EOF)
    {
        if (ch == '/')
        {
            preCh = ch;
            if ((ch = getchar()) == '*')
            {
                state = IN_COMMENT_STATE;
            }
            else
            {
                putchar(preCh);
            }

        }

        else if (state == IN_COMMENT_STATE)
        {
            if (ch == '*')
            {
                preCh = ch;

                if ( (ch = getchar()) == '/')
                {
                    state = OUT_COMMENT_STATE;
                }
                else
                {
                    putchar(preCh);
                }

            }
        }
        else
        {
            putchar(ch);
        }
    }
    return 0;
}
