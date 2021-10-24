#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HASH_TABLE_SIZE 101
typedef struct tagStudent
{
    char* name;
    int   age;
    char* addr;
    struct tagStudent* next;
}student;
student* hashtab[HASH_TABLE_SIZE];
int compare(char* src1, char* src2)
{
    while (*src1 == *src2)
    {
        src1++;
        src2++;
    }

    if (isalpha(*src1)&&(isalpha(*src2)) && (*src1 - *src2 > 0))
    {
        return 1;
    }

    return 0;

}
unsigned int hash(char* name)
{
    int idx = 0;
    for (;*name != '\0';name++)
    {
        idx = (idx + *name) * (*name);
    }
    return idx % HASH_TABLE_SIZE;
}
student* lookup(char* name)
{
    student* entry = hashtab[hash(name)];

    for (;entry != NULL; entry = entry->next)
    {
        if (strcmp(entry->name,name) == 0)
        {
            return entry;
        }
    }
    return NULL;
}

student* install(char*name, char*addr)
{
    student* item;
    int hashval;
    if (!(item = lookup(name))) /* insert at head, otherwise,not use lookup here */
    {
        hashval = hash(name);
        item = (student*)malloc(sizeof(student));
        if (!item || !(item->addr = strdup(name)))
        {
            return NULL;
        }

        item->addr = strdup(addr);
        item->next = hashtab[hashval];
        hashtab[hashval] = item;



    }
    else /* if found, replace legacy addr with newer one */
    {
        free(item->addr);
        item->addr = strdup(addr);
    }
    return item;
}
int main()
{
    char* src1 = "abcF";
    char* src2 = "abce";
    int ret = compare(src1,src2);
    printf("%d\n",ret);
    return 0;
}
