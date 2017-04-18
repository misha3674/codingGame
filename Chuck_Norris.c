#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int count1 = 1;
int count0 = 1;
int k = 0;

 void print_byte(char aSmb)
 {
    int i = 0;
    int byte = -1;
    
    int n = 7;
   /* if(aSmb > 2) n = 1;
    if(aSmb > 4) n = 2;
    if(aSmb > 8) n = 3;
    if(aSmb > 16) n = 4;
    if(aSmb > 32) n = 5;
    if(aSmb > 64) n = 6;
    if(aSmb > 128) n = 7;*/
    
     for(i = 6; i >=0; --i)
     {
        byte = (aSmb >> i) & 0x01;
        if(byte)
        {
          
           if(count0) //printf count number (zero) 
            {
              if(k) printf(" ");
              printf("0 ");
              k = 1;
            }
           count0 = 0;
           count1=1;
        }
        if(!byte)
        {
            if(count1) 
            {
               if(k) printf(" ");
               printf("00 ");
               k = 1;
            }
            count1 = 0;
            count0=1;
        }
        if(k)
            printf("0");
     }
   //  printf("\n");
 }
int main()
{
    char MESSAGE[101];
    fgets(MESSAGE, 101, stdin);
    //puts(MESSAGE);
    int i = 0;
    while(MESSAGE[i] != '\n')
    {
        print_byte(MESSAGE[i]);
        i++;
    }

    return 0;
}
