#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define MAX_OP 100
/* Exercise 4-4. Add the commands to print the top elements of the stack without popping, to duplicate it,
and to swap the top two elements. Add a command to clear the stack.
*/
void push(double value);
double pop();
int getop(char s[]);
void peek();
void clrstack();
int main()
{
    int type;
    double op2;
    char s[MAX_OP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;
            case '%':
                op2 = pop();
                if (op2 != 0)
                {
                    push(fmod(pop(),op2));
                }
                else
                {
                    printf("mod by zero,not ok\n");
                }
                break;

            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop()/op2);
                else
                    printf("divided by zero\n");
                break;

            case '\n':
                printf("\t%.8g\n",pop());
                break;
            case '@': /* Add the commands to print the top elements of the stack without popping, to duplicate it,
and to swap the top two elements*/
                peek();
                break;
            case '#': /* clear the stack */
                clrstack();
                break;

            default:
                printf("wrong operand given,%s\n",s);
                break;

            }

    }
    return 0;
}

/* implement stack */
#define MAXVAL 100

int pos = 0; /* next pos to be inserted element */
double stack[MAXVAL];
void push(double value)
{
    if (pos < MAXVAL)
    {
        stack[pos++] = value;
    }
    else
    {
        printf("stack full\n");
    }
}

double pop()
{
    if (pos > 0)
    {
        return stack[--pos];
    }
    printf("stack empty\n,");
    return -1;

}
void clrstack()
{
    pos = 0;
}
void peek()
{
    double n;

    if (pos > 0)
    {
       n = stack[--pos];
       printf("element on top is %f\n",n);
       ++pos; /* restore index */
       push(n);
    }
    else
    {
        printf("no element in stack\n");

    }
}
int getch(void);
void ungetch(char ch);

int getop(char s[])
{
    int i,c;

    while ((s[0] = c = getch()) == ' ' || s[0] == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c !='-')
        return c;
    i = 0;
    if (c == '-')
    {
        s[i] = c;
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    else if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;

    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;

    }

    s[i] = '\0';

    if (c != EOF)
    {
        ungetch(c); /* put other chs like blanks into buf, so we can get it from the buf next time */
    }

    return NUMBER;
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
