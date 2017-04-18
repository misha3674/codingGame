#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 char **mas_ext = 0;
 char **mas_mt  = 0;
 int n = 0;
 
 void low_case(char *mas)
 {
   int i = 0;
   char c = 0;
    while(mas[i] != 0) 
   {
        c = mas[i];
        if ( ('A' <= c) && (c <= 'Z') ) 
        {
            c += ('a' - 'A');
            mas[i] = c;
        }
        i++;
    };
}
 
 void print_mmia_type(char *aType)
 {
   int i = 0;
   char c = 0;
   low_case(aType);
   i = 0;
    while(aType[i] != '\n') i++;
    aType[i] = 0;
    
   for(i = 0; i < n; i++)
   { // printf("%s\n",*(mas_ext + i)); 
       if(strcmp(aType,*(mas_ext + i)) == 0)
       {
          printf("%s\n",*(mas_mt + i));
           return;
       }
    }
    printf("UNKNOWN\n");
 }
 void print_type(char *aName)
 {
    int i = 0;
    int j = 0;
    
    char type[100] = {0};
    while(aName[i] != 0) 
     {   if(aName[i] == '.')
            j = i;
        i++;
     }
    strcpy(type,(aName + j+1));
    //printf("type %s\n",type);
    print_mmia_type(type);
}

int main()
{
    int N; // Number of elements which make up the association table.
    scanf("%d", &N);
    n = N;
    mas_ext = (char**)calloc(N,sizeof(char*));
    mas_mt = (char**)calloc(N,sizeof(char*));
    for (int i = 0; i < N; i++) 
    {
        *(mas_ext+i) = (char*)calloc(101,sizeof(char));
        *(mas_mt+i) = (char*)calloc(501,sizeof(char));
    }
    int Q; // Number Q of file names to be analyzed.
    scanf("%d", &Q);
    for (int i = 0; i < N; i++) {
        char EXT[101]; // file extension
        char MT[501]; // MIME type.
        scanf("%s%s", EXT, MT); fgetc(stdin);
       //puts(EXT);
      // puts(MT);
        strcpy(*(mas_ext+i),EXT);
        strcpy(*(mas_mt+i),MT);
        low_case(*(mas_ext+i)); 
    }
    //printf("Hello\n");
    for (int i = 0; i < Q; i++) {
        char FNAME[501]; // One file name per line.
        fgets(FNAME, 501, stdin); // One file name per line.
       // printf("name %s",FNAME);
         print_type(FNAME);    
    }

    free(mas_ext);
    free(mas_mt);
   
    return 0;
}
