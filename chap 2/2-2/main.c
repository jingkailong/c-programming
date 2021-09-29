#include <stdio.h>
#include <stdlib.h>
/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

*/

int getline(char array[], int lim)
{
    int ch;
    int i = 0;
    for (i = 0; ((ch = getchar()) != EOF) && (ch != '\n') && (i < lim-1); i++)
        array[i] = ch;
    if (ch == '\n')
    {
        array[i] = '\n';
    }
    array[i] = '\0';
    return i;
}

int getline2(char s[],int lim)
{
    int ch;
    int i = 0;
    while ((ch = getchar()) != EOF)
    {
        s[i] = ch;
        i++;
        if (ch == '\n')
        {
            break;
        }
        if (i > lim-1)
        {
            s[i] = '\0';
            break;
        }

    }
    return i;
}
int main()
{
    char s[100];
    getline2(s,100);
    puts(s);
    return 0;
}
