#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.*/
/* at least two ways to implement */
void removeBlanks(char input[])
{
   // char* begin = input;
    char*s = input + strlen(input) -1; /* get end of the string */
    while ((*s == '\t') || (*s == ' '))
    {
        s--;
    }
    *(++s) = '\0';

}
int main()
{
    char s[] = "                ";
    removeBlanks(s);
    printf("%s--%d\n",s,strlen(s));
    return 0;
}
