#include <stdio.h>
#include <stdlib.h>
/* Exercise 4-8. Suppose that there will never be more than one character of pushback.
Modify getch and ungetch accordingly.
*/

#define MAX_BUF_SIZE 100
char buf[MAX_BUF_SIZE];
int buf_p = 0;
int getch(void)
{
    return (buf_p > 0)?buf[--buf_p]:getchar();

}

void ungetch(char ch)
{
    if (buf_p < MAX_BUF_SIZE)
    {
        buf[buf_p++] = ch;
    }
    else
    {
        printf("too many characters\n");
    }
}

int main()
{
    return 0;
}
