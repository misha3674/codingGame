#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 struct List{
    int v;
    struct List* pNext;
 };
 typedef struct List sList;
 sList* pHead = NULL;
 sList* init_list(int el)
 {
    sList* newNode = (sList*)malloc(sizeof(sList));
    newNode->v = el;
    newNode->pNext = NULL;
    pHead = newNode;
    return newNode;
 }
 sList* add_in_list(int el)
 {
    sList* newNode = (sList*)malloc(sizeof(sList));
    newNode->v = el;
    newNode->pNext = NULL;
    sList* crowler = pHead;
    sList* prev = NULL;
    while( crowler->pNext != NULL)
    {
        
        if(crowler->v > el)
              break;
        prev = crowler;
        crowler = crowler->pNext;
    }
    if(crowler->pNext == NULL)
    {
        // paste in end list
        crowler->pNext = newNode;
        return newNode; 
    }
    if(prev == NULL)
    {
       // paste in start list
       newNode->pNext = pHead;
       pHead = newNode;       
       return newNode;     
    }
    newNode->pNext = crowler;
    prev->pNext = newNode;
 }
 void print_closest()
 {
    int min = -1;
    int del = 0;
    sList* prev = NULL;
    sList* crowler = pHead;
    min = crowler->v;
    while( crowler->pNext != NULL)
    {
        prev = crowler;
        crowler = crowler->pNext;
        del = abs(prev->v - crowler->v);
        if(min == (-1))
        {
            min = del;
        }
        else
        {
            if(min > del)
                min = del;
        }
    } 
    printf("%i\n",min);
 }
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int Pi;
        scanf("%d", &Pi);
        if(i == 0)
             init_list(Pi);
        else
            add_in_list(Pi);
    }
    print_closest();
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    return 0;
}
