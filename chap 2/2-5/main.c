#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
<<<<<<< HEAD

=======
#include <string.h>
>>>>>>> initial version
=======
#include <string.h>
>>>>>>> initial version
/*
Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the location.) */
<<<<<<< HEAD
<<<<<<< HEAD
int main()
{
=======
int any(char* s1, char* s2)
{
    char* pos = strpbrk(s1,s2);
    if (pos == NULL)
    {
        return -1;
    }
    return (pos - s1);
}
int main()
{
    printf("%d\n",any("abc","d"));
>>>>>>> initial version
=======

int any(char* s1, char* s2)
{
    char* pos = strpbrk(s1,s2);
    if (pos == NULL)
    {
        return -1;
    }
    return (pos - s1);
}
int main()
{
    printf("%d\n",any("abc","d"));
>>>>>>> initial version
    return 0;
}
