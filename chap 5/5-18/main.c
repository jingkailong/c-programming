#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
enum {NAME,PARENS,BRACKETS};
void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
/* parse a declarator */

int getch(void);
void ungetch(int c);
/* In words, a dcl is a direct-dcl, perhaps preceded by *'s.
. */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';)
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out," pointer to");
}
/* dirdcl: parse a direct declarator   A direct-dcl is a name, or a parenthesized dcl, or a direct-dcl followed by parentheses,
 or a direct-dcl followed by brackets with an optional size */
void dirdcl(void)
{
    int type;

    if (tokentype == '(')
    {
        dcl();
        if (tokentype != ')')
        {
            printf("error:missing )\n");
        }
    }
    else if (tokentype == NAME)
    {
        strcpy(name,token);
    }
    else
        printf("error:expected name or dcl()\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
        {
            strcat(out," function returning ");
        }
        else
        {
            strcat(out," array");
            strcat(out,token);
            strcat(out," of");
        }
    }
}
int main()
{
    while (gettoken() != EOF)
    {
        strcpy(datatype,token); /*a declaration starts with type firstly*/
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n",name,out,datatype);
    }
    return 0;
}
/* return next token */
int gettoken(void)
{
    int c,getch(void);
    void ungetch(int);
    char* p = token;

    while ((c = getch()) ==' '|| c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token,"()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ =c;(*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;

}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
}
