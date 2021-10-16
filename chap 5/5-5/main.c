#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp,
which operate on at most the first n characters of their argument strings.
For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
*/
/* strncpy(s,t,n) copies at most n characters of t to s. */
char* my_strncpy(char*s, char*t ,int n)
{
    char* bs = s;
    int i = 0;
    while (*s)
        s++;
    for (i = 0; (*t)&&(i < n); i++)
    {
        *s = *t;
        s++;
        t++;
    }
    if (i < n)
    {
        printf("string not long enough to copy to destination\n");
    }
    *s = '\0';
    return bs;

}
int main()
{
    char s[] = "I am a ";
    char t[] = "dog,please";
    //char*z = my_strncpy(s,t,3);
    char* z = strncat(s,t,3);
    printf("%s\n",s);
    return 0;
}
