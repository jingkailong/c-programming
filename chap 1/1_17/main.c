#include <stdio.h>
#include <stdlib.h>
/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.

1,80���ַ������ȴ洢������ĳ����Ƕ��Ӧ���Ƕ�̬���顣
2,\tҪ��Ӧ����չ��\n
3,�����ʵ�ֻ������Ż���1024���ַ���������Բ��á�˼�����ȴ�80+1��������80���Ĳ��ô棬ֱ�������
*/
#define MIN_LINE_LEN 80+1 // ����'\0'.
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
