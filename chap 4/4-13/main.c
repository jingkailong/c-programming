#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.
*/
void reverser(char s[], int i, int len)
{
    int j,ch;
    j = len - i -  1;
    if (i < j)
    {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;

        reverser(s,++i,len);

    }

}
void reverse(char s[])
{
   int len = strlen(s);
   reverser(s,0,len); //add this function to add start&end index to stop recursion.

}
int main()
{
    char s[] = "abcdefg";
    reverse(s);
    printf("%s",s);
    return 0;
}
