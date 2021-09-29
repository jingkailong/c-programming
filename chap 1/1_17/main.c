#include <stdio.h>
#include <stdlib.h>
/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.

1,80个字符必须先存储，数组的长度是多大，应该是动态数组。
2,\t要相应地扩展，\n
3,下面的实现还可以优化，1024个字符的数组可以不用。思想是先存80+1个，超过80个的不用存，直接输出。
*/
#define MIN_LINE_LEN 80+1 // 考虑'\0'.
#define MAX_LINE_LEN 1024
#define MAX_TAB_SIZE 4
int main()
{
    int ch;
    int i = 0;
    int j = 0;
    int chArray[MAX_LINE_LEN];

    while ((ch = getchar()) != EOF)
    {
        if (ch != '\n')
        {
            if (ch == '\t')
            {
                for (j = 0; j < MAX_TAB_SIZE; j++)
                {
                    chArray[i++] = ' '; //expand tab
                }
            }
            chArray[i++] = ch;
        }
        else
        {
            if (i > MIN_LINE_LEN)
            {
                for (j = 0; j < i; j++)
                {
                    putchar(chArray[j]);

                }
                i = 0;
            }
            else
            {
                i = 0;
            }
        }

    }

    return 0;
}
