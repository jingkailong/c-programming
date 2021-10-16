#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 5
#define MAX_LINE_LEN 100
char lineptr[MAX_LINES][1000];
int getline(char* line, int lim)
{
    int ch;
    int i;
    for(i = 0;(i < lim-1) &&((ch = getchar()) != EOF) && (ch != '\n');i++)
        line[i] = ch;
    if (ch == '\n')
        line[i++] = ch;
    line[i] = '\0';
    return i;
}
void readlines1(int len,int* readlines)
{
    int curline = 0;
    int nline = 0;
    char line[MAX_LINE_LEN] = {0};
    while ((nline = getline(line,MAX_LINE_LEN))>0)
    {
        //lineptr[curline] = malloc(nline * sizeof(char));
        if (curline >= len)
            return;
        strcpy(lineptr[curline],line);
        curline++;
    }
    *readlines =  curline;
}
void writelines(int len)
{
    int i;
    for (i = 0; i < len; i++)
       puts(lineptr[i]);
}
int main()
{
    int nxline = 0;

    readlines1(MAX_LINES,&nxline);
    if (nxline > 0)
    {
        printf("total %d lines\n",nxline);
        writelines(nxline);
    }
    return 0;
}
