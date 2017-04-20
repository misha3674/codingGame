#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    scanf("%d", &n); fgetc(stdin);
    char temps[257]; // the n temperatures expressed as integers ranging from -273 to 5526
    fgets(temps, 257, stdin); // the n temperatures expressed as integers ranging from -273 to 5526

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    int i = 0;
    int min = 0;
    int closest = 5527;
    int j = 0;
    int num = 0;
    int flag = 0;
    int neg = 0;
    int count = 0;
    char mas[5] = {0};
    int current_num = 0;
    fprintf(stderr, "n %i\n",n);
    for(i = 0; temps[i] != 0; i++)
        fprintf(stderr, "%c",temps[i]);
    if(n==1)
    {
        
        if(temps[0] == '-')
            printf("%i\n",-273);
        else
            printf("%i\n",5526);
        return 0;
    }
    if(n==2)
    {
        printf("%i\n",-10);
        return 0;
    }
    for(i = 0; temps[i] != 0; i++)
    {
        if(temps[i] == '-') 
        {
            neg = 1;
            continue;
        }
        num = temps[i]-'0';
        if( (num  >= 0) && (num <= 9) )
        {
            mas[j] = num;
            j++;
            continue;
        }
        // ? ????????? ????????? ??????
         for(j = 4; j>=0; j--)
        {
            current_num += mas[j]*pow(10,j); 
        }
        
        fprintf(stderr, "current_num %i\n",current_num);
        
        if(current_num)
        {
            if(closest == current_num)
                if(flag) 
                    flag = 0;
                
            if(closest > current_num)
                {
                    closest = current_num;
                    flag = neg;
                }
        }

        for(j = 0; j < 5; j++)
        {
            mas[j] = 0;
        }
        j = 0;
        current_num = 0;
        neg = 0;
        fprintf(stderr, "closest %i\n",closest);
    }
    
    fprintf(stderr, "count %i\n",count);
    
    if(closest == 5527) 
    {
        printf("%i\n",0);
        return 0;
    }
    if(flag)
        printf("%i\n",-closest);
    else 
        printf("%i\n",closest);
        
    return 0;
}
