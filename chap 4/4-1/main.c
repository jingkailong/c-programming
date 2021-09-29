#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Exercise 4-1. Write the function strindex(s,t)
which returns the position of the rightmost occurrence of t in s, or -1 if there is none. */

int strindex(char s[], char t[])
{
   int i, j, k;

   for (i = 0; s[i] != '\0'; i++) {
       for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
           ;
       if (k > 0 && t[k] == '\0')
           return i;
   }
   return -1;
}
int strindex2(char s[], char t[])
{
   int i, j, k,l;
   l = 0;
   for (i = strlen(s) - 1; i >= 0; i--)
   {
       j = i;
       k = strlen(t) - 1;
       for (; t[k] == s[j] && (l< strlen(t));l++ )
       {
           j--;
           k--;
       }
       if ( k == -1)
       {
           return j;
       }

   }
   return -1;
}

int main()
{
    char a[] = "dabcdefgabcafdafabc";
    char b[] = "abc";
    int n = strindex2(a,b);
    printf("%d\n",n);
    return 0;
}
