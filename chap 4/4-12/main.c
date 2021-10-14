#include <stdio.h>
#include <stdlib.h>
/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by calling a recursive routine.
*/


/* printd:  print n in decimal */
void printd(int n)
{
   if (n < 0) {
       putchar('-');
       n = -n;
   }
   if (n / 10)
       printd(n / 10);
   putchar(n % 10 + '0');
}
void itoa2(int n,int i, char*buff);
void itoa1(int n,char* buff)
{
   static int i = 0;

    if (n < 0)
    {
        buff[i] = '-';
        n = -n;
        i++;
    }

    if (n/10)
        itoa1(n/10,buff);
    buff[i++] = n%10 + '0';


}
int main()
{
    char buff[20] = {0};
    //printd(1343);
    int n = -1345;
    itoa1(n,buff);
    printf("buff:%s",buff);
    return 0;
}
