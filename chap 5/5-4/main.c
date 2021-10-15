#include <stdio.h>
#include <stdlib.h>
/*Exercise 5-4. Write the function strend(s,t),
which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
*/
int strend(char* s, char* t)
{
    char* bs = s;
    char* bt = t;

    while (*s)
    {
        s++;
    }
    while (*t)
    {
        t++;
    }
#if 0
    for(;*s;s++)
        ;
    for(;*t;t++)
        ;
#endif

    while (*t == *s)
    {
        if ((bs == s) || (bt == t))
        {
           break;
        }
        s--;
        t--;
    }

    if ((*s == *t)&&(bt == t) && *s != '\0')
    {
        return 1;
    }
    return 0;

}
int main()
{
    int n = strend("abcd","cd");
    printf("%d\n",n);
    return 0;
}
