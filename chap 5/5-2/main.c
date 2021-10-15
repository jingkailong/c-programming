#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* Exercise 5-2. Write getfloat, the floating-point analog of getint.
What type does getfloat return as its function value?
*/
int getfloat(float* pn)
{
    int sign;
    int power;
    if (pn == NULL)
        return -1;

    int ch;
    while ((ch = getchar()) == ' ' || ch == '\t')
        ;

    if (ch == '+' || ch == '-')
    {
        sign = (ch == '-')?-1:1;
        if (!isdigit(ch = getchar()))
        {
            return -1;
        }
    }


     for (*pn = 0;isdigit(ch); ch = getchar())
     {
         *pn = *pn * 10 + (ch - '0');
     }
     if (ch == '.')
     {
         power = 1;
         while (isdigit(ch = getchar()))
         {
             *pn = *pn * 10 + (ch - '0');
             power *= 10;
         }
     }

     *pn = *pn * sign/power;
     return 0;

}
int main()
{
    float pn;
    getfloat(&pn);
    printf("%f\n",pn);
    return 0;
}
