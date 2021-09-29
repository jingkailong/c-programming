#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.

*/
#define MAX_LINE 10
int getline(char chArray[], int lim)
{
    int ch;
    int i;
    for (i = 0; ((ch = getchar()) != EOF) && (ch != '\n') && (i < lim -1); i++)
    {
        chArray[i] = ch;
    }
    if ( ch == '\n')
    {
        chArray[i] = '\n';
        i++;
    }
    chArray[i] = '\0';
    return i;
}

void copy(char to[],char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
int main()
{
    int ch;
    char longline[MAX_LINE];
    char line[MAX_LINE];
    int longNum = 0;
    int maxline = 0;

    while ((maxline = getline(line,MAX_LINE))> 0)
    {
        if (maxline > longNum)
        {
            longNum = maxline;
            copy(longline,line);
        }
    }
    if (longNum > 0)
    {
         printf("%s\n",longline);
        if (longNum >= MAX_LINE-1)
        {
            printf("reached max line leng\n");
            while ((ch = getchar()) != EOF)
            {
                putchar(ch);
            }
        }

    }

    return 0;
}
