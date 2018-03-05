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

    //if ((int64_t)e & 0x3f){
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    //}

    /*
    else {
        entry *align = (entry *) malloc(sizeof(entry)+32);
        e->pNext = (entry *)(((int64_t)align+64) & ~ (int64_t)0x3f);
        e = e->pNext;
        strcpy(e->lastName, lastName);
        e->pNext = NULL;
    }
    */

    return e;
}


