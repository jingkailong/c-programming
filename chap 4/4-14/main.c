#include <stdio.h>
#include <stdlib.h>
/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
 (Block structure will help.)  */

#define _swap(t,x,y) \
do {                  \
    t temp;          \
    temp  = x;       \
    x = y;            \
    y = temp;        \
}while (0)


int main()
{
    int x = 5;
    int y = 6;
    _swap(int,x,y);
    printf("x = %d, y = %d\n",x,y);
    return 0;
}
