#include <stdio.h>
#include <stdlib.h>
/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character
in s1 that matches any character in the string s2.
*/

/* squeeze:  delete all c from s */
void squze(char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
      if (s[i] != c)
          s[j++] = s[i];
  s[j] = '\0';
}

void squeeze(char s1[],char s2[])
{
    while (*s2)
    {
        squze(s1,*s2);
        s2++;
    }

}

int main()
{
    char s1[] = "abcdefg";
    char* s2 = "de";
    squeeze(s1,s2);
    puts(s1);

    return 0;
}
