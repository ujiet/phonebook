#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */

    if (((int64_t)e & 0x1f) != 0x00) {
        /* alignment */
        e->pNext = (entry *) malloc(sizeof(entry)+64);
        void *new_addr = (void *) (((int64_t)&(e->pNext)+64) & ~(int64_t)0x3f);
        void *old_addr = (void *) e->pNext;
        free(e->pNext);
        char *padding = (char *) malloc((int64_t)new_addr - (int64_t)old_addr);

        e->pNext = (entry *) malloc(sizeof(entry));
        e = e->pNext;
        strcpy(e->lastName, lastName);
        e->pNext = NULL;
        free(padding);
    }

    else {
        e->pNext = (entry *) malloc(sizeof(entry));
        e = e->pNext;
        strcpy(e->lastName, lastName);
        e->pNext = NULL;
    }

    return e;
}


