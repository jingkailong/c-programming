#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

/* Exercise 6-1. Our version of getword does not properly handle underscores,
string constants, comments, or preprocessor control lines. Write a better version. */
struct key
{
    char* word;
    int count;
}keytab[] = {
{"auto",0},
{"if",0}};
#define NKEYS ((sizeof(keytab)))/(sizeof(keytab[0]))
int getword(char* word, int lim) /* get each word from input,no newline or EOF,*/
{
    int ch;
    if (word == NULL)
        return -1;
    char*p = word;
    while (isspace(ch = getchar()))
           ;
    if (isalpha(ch))
    {
        *p++ = ch;
        lim -= 1;
        for (;isalnum(ch = getchar())&& (lim > 0);lim--)
        {
            *p++ = ch;
        }
    }
    *p = '\0';
    return word[0];
}
int binsearch(char *word, struct key tab[], int n);
int main()
{
    int i;
    int no;
    char word[MAXWORD];
    while (getword(word,MAXWORD))
    {
        printf("%s\t",word);
        if ((no = binsearch(word,keytab,NKEYS)) != -1)
        {
            keytab[no].count++;
        }

    }
    for (i = 0 ; i < NKEYS; i++)
        printf("\t word:%s     count:%d",keytab[i].word,keytab[i].count);
    return 0;
}

/* binsearch:  find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
   int cond;
   int low, high, mid;

   low = 0;
   high = n - 1;
   while (low <= high) {
       mid = (low+high) / 2;
       if ((cond = strcmp(word, tab[mid].word)) < 0)
           high = mid - 1;
       else if (cond > 0)
           low = mid + 1;
       else
           return mid;}
    return -1;
}
