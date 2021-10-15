#include <stdio.h>
#include <stdlib.h>
/* Exercise 5-3. Write a pointer version of the function strcat
that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
*/

void my_strcat(char* s,char* t)
{
    while (*s !='\0')
        s++; /* step to the '\0' */
    while ((*s++ = *t++) != '\0')
        ;
    return;



}
int main()
{
    char s[] = "I am jing";
    char t[] = "kailong";
    my_strcat(s,t);
    printf("%s",s);
    return 0;
}
