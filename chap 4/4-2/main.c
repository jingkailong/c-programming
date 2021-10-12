#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
Exercise 4-2. Extend atof to handle scientific notation of the form

   123.45e-6

where a floating-point number may be followed by e or E and an optionally signed exponent.

*/
double atof1(char* s)
{
    int sign = 1;
    double val = 0;
    double power = 1.0;
    int exp = 1;
    int ponet = 0;
    /* skip white space*/
    for (;*s == ' ' || *s == '\t' || *s == '\n'; s++)
        ;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }

    for (;isdigit(*s);s++)
    {
        val = val * 10 + (*s - '0');

    }
    if (*s == '.')
    {
        s++;
    }
    for (power = 1.0;isdigit(*s);s++)
    {
        val = val * 10.0 + (*s - '0');
        power = power * 10.0;
    }

    val = sign * val/power;
    if (*s == 'e' || *s == 'E')
    {
        s++;
    }
    exp = *s == '-'?-1:1;
    if (*s == '-' || *s == '+')
    {
        s++;
    }
    for (;isdigit(*s);s++)
    {
        ponet = ponet * 10 + (*s - '0');

    }
    power = 1;
    for (int i = 0; i < ponet;i++)
    {
        power = power * 10;
    }
    if (exp == -1)
    {
        power = 1/power;
    }
    return val * power;



}
int main()
{
    char a[] = "123.45e-6";
    double n = atof1(a);
    printf("%.10f\n",n);
    return 0;
}
