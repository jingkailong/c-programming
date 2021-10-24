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
student* hashtab[HASH_TABLE_SIZE] = {NULL};

char* strdup1(char* src)
{
    char* p = malloc(strlen(src)+1);
    if (!p)
    {
        return NULL;
    }
    strcpy(p,src);
    return p;

}
unsigned int hash(char* name)
{
    int idx = 0;
    for (;*name != '\0';name++)
    {
        idx += *name + idx *31;
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
        if (!item || !(item->name = strdup1(name)))
        {
            return NULL;
        }

        item->addr = strdup1(addr);
        item->next = hashtab[hashval];
        hashtab[hashval] = item;



    }
    else /* if found, replace legacy addr with newer one */
    {
        free(item->addr);
        item->addr = strdup1(addr);
    }
    return item;
}
void traverseHash(void)
{
    int i;
    student * pstu = NULL;
    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        pstu = hashtab[i];
        while (pstu)
        {
            printf("name:%s   addr:%s\n",pstu->name,pstu->addr);
            pstu = pstu->next;
        }
    }
}
void undef(char*name)
{
    int hashval = hash(name);
    student* p = hashtab[hashval];
    student* q = NULL;
    if (strcmp(p->name,name) == 0) //delete head pointer.
    {
        hashtab[hashval] = p->next;

    }
    else
    {
        while (p) // can add more judge into while to clean logic.
        {
            q = p;
            p = p->next;
            if (strcmp(p->name,name) == 0)
            {
                q->next = p->next;
                free(p->name);
                free(p->addr);
                free(p);
                break;
            }
        }

    }

}
int main()
{
    install("lucy","new york");
    install("johnson","chengdu");
    traverseHash();
    undef("lucy");
    traverseHash();
    return 0;
}
