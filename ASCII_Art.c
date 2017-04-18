#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void my_print(char* mas, char sm, int l)
{
    int del = 0;
    int j = 0;
    int i = 0;
    int ok = 0;
        
        del = sm - 'a';
            if(del < 0) del = sm - 'A';    
         
        ok = ((sm >= 'a') && (sm <= 'z'));
        ok = (ok || ((sm >= 'A') && (sm <= 'Z')));
        if(!ok)  del = 'Z' - 'A' + 1;
           
        mas = mas+l*del;
        
        if(del >= 0) 
       {
           for(i = 0; i < l; i++)
                printf("%c",*(mas+i) ); 
       }
}
int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);
    int kk=0;
    char T[257];
    fgets(T, 257, stdin);
    //puts(T);
     
    for (int i = 0; i < H; i++) 
    {
        char ROW[1025];
        fgets(ROW, 1025, stdin);
       // printf("%s",ROW);
        for (kk = 0; T[kk] != '\n'; kk++)
         my_print(ROW,T[kk],L);
         printf("\n");
    }
    
    return 0;
}
