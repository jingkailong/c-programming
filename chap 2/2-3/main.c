#include <stdio.h>
#include <stdlib.h>
/*
Exercise 2-3. Write a function htoi(s),
which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F. */
int htoi(char* s,int* nn)
{
    char* target = s;
    int n = 0;
    int lowerletterfound = 0;
    int upperletterfound = 0;
    /* make sure real string there */
    if (s == NULL || nn == NULL)
    {
        return -1;
    }
    target = s;
    /* skip the optional 0x or 0X */
    if ((s[0] == '0') && ((s[1] == 'x') || (s[1] == 'X')))
    {
        target = s+2;
    }
    while (*target)
    {
        if ((*target >= '0') && (*target <= '9'))
        {
            n = 16 * n + (*target - '0');
        }
        else if ((*target >= 'a') && (*target <= 'f'))
        {
            if (upperletterfound == 1)
            {
                printf("illegal lowercase characters detected,aborting....\n");
                return -1;
            }
            n = 16 * n + (*target - 'a' + 10);
            if (lowerletterfound == 0)
            {
                lowerletterfound = 1;
            }

        }
        else if ((*target >= 'A') && (*target <= 'F'))
        {
            if (lowerletterfound == 1)
            {
                printf("illegal uppercase characters detected,aborting....\n");
                return -1;
            }
            n = 16 * n + (*target - 'A' + 10);
            if (upperletterfound == 0)
            {
                upperletterfound = 1;
            }
        }
        else
        {
            printf("illegal characters detected,aborting....\n");
            return -1;
        }

        target++;
    }


    *nn = n;
    return 0;
}

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

int main()
{
    char s[100];
    int n = 0;
    int ret;
    while (getline(s,100))
    {
        ret = htoi(s,&n);
        if (ret == 0)
        {
           printf("%d\n",n);
        }
    }
    return 0;
}
