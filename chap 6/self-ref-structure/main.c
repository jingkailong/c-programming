#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 100

struct tnode
{
    char *word;
    int count;
    struct tnode*  left;
    struct tnode*  right;
};

char* strdup1(char* src);
char *strdup2(char *s);

int getword(char word[],int lim);
struct tnode* addtree(struct tnode* root,char* src);
void treeprint(struct tnode* leaf);

int getch(void);
void ungetch(int);

int main()
{
    char word[MAXWORD];
    struct tnode* root = NULL;
    while (getword(word,MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root,word);

        }
    }
    treeprint(root);
    return 0;
}

/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
   int c, getch(void);
   void ungetch(int);
   char *w = word;

   while (isspace(c = getch()))
       ;
   if (c != EOF)
       *w++ = c;
   if (!isalpha(c)) {
       *w = '\0';
       return c;
   }
   for ( ; --lim > 0; w++)
       if (!isalnum(*w = getch())) {
           ungetch(*w);
           break;
       }
   *w = '\0';
   return word[0];
}
/* talloc:  make a tnode */
struct tnode *talloc(void)
{
   return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode* addtree(struct tnode* p,char* src)
{
    int cond = 0;
    if (p == NULL)
    {
        p = talloc();
        p->count = 1;
        p->word = strdup2(src);
        p->left = NULL;
        p->right = NULL;
    }
    else if ((cond = strcmp(p->word,src)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left,src);
    }
    else
    {
        p->right = addtree(p->right,src);
    }
    return p;
}
void treeprint(struct tnode* leaf)
{
    if (leaf)
    {
        treeprint(leaf->left);
        printf("word:%s   count:%4d\n",leaf->word,leaf->count);
        treeprint(leaf->right);
    }

}
char* strdup1(char* src)
{
    char*p = malloc(strlen(src)+ 1);
    if (!p)
        return NULL;
    while((*p++ = *src++))
        ;
    *p = '\0';
    return p;
}
char *strdup2(char *s)   /* make a duplicate of s */
{
   char *p;

   p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
   if (p != NULL)
       strcpy(p, s);
   return p;
}
/////////////////////////////////////////////////////////////////////////////////
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
}
