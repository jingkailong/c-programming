#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?
*/
/* not implemented */
int getch(void);
void ungetch(char ch);
void ungets(char s[]);

void ungets1(const char *s)
{
  size_t i = strlen(s);

  while (i > 0)
    ungetch(s[--i]);
}


int main()
{
    char *s = " I am a programmer\n";
    ungets1(s);
    int ch;

    while ((ch = getch()) != EOF)
    {
        putchar(ch);
    }

    return 0;
}

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


/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?
*/
void ungets(char s[])
{
    while (*s != '\0')
    {
        ungetch(*s++);
    }

}
