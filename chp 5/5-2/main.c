#include <stdio.h>
#include <stdlib.h>
/* Exercise 5-2. Write getfloat, the floating-point analog of getint.
What type does getfloat return as its function value?
*/
int main()
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
    return 0;
}
