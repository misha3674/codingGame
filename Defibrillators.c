#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 #define SMB 255
 typedef struct
 {
    char* id;
    char* name;
    char* address;
    char* phone;
    char* lon;
    char* lat;
 }sDef;

double g_vlon = 0.f;
double g_vlat = 0.f;
    
 void innit(sDef* d)
 {
    if(d->id == NULL)
        d->id      = (char*)calloc(SMB,sizeof(char));
    if(d->name == NULL)
        d->name  = (char*)calloc(SMB,sizeof(char));
    if(d->address == NULL)
        d->address = (char*)calloc(SMB,sizeof(char));
    if(d->phone == NULL)
        d->phone   = (char*)calloc(SMB,sizeof(char));
    if(d->lon == NULL)
        d->lon     = (char*)calloc(SMB,sizeof(char));
    if(d->lat == NULL)
        d->lat     = (char*)calloc(SMB,sizeof(char));
 }
 void clear(sDef* d)
 {
    free(d->id);
    free(d->name);
    free(d->address);
    free(d->phone);
    free(d->lon);
    free(d->lat);
    d->id      = NULL;
    d->name    = NULL;
    d->address = NULL;
    d->phone   = NULL;
    d->lon     = NULL;
    d->lat     = NULL;
 }
void fillInform(char* line_def,sDef* def)
{
    int i = 0;
    char ch = 0;
    char
    unsigned s = 0;
    for(i = 0; line_def[i] != 0; i++)
    {
        if(line_def[i] == ';')
        {
            if(ch != 0)
                s++;
            ch = 0;
        }
        else
        {
            switch(s)
            {
                case 0:
                    (def->id)[ch] = line_def[i];
                break;
                case 1:
                    (def->name)[ch] = line_def[i];
                break;
                case 2:
                    (def->address)[ch] = line_def[i];
                break;
                case 3:
                    (def->phone)[ch] = line_def[i];
                break;
                case 4:
                    (def->lon)[ch] = line_def[i];
                break;
                case 5:
                   (def->lat)[ch] = line_def[i];
                break;
                default: break;
            }
            //((char*)def + s)[ch] = line_def[i];
            ch++;
        }
    }
}
double calculateDistance(sDef* d)
{
    double distance = 0.f;
    double x = 0.f;
    double y = 0.f;
    double dlon = atof(d->lon);
    double dlat = atof(d->lat);
    // check work of atof
    x = (g_vlon -  dlon)*cos((g_vlat+dlat)/2.0);
    y = (g_vlat - dlat);
    distance = sqrt( (double)(x*x + y*y) )*6371.;
    return distance;
}
void turn_comma_into_dot(char* mas)
{
    for(int i = 0; mas[i] != 0; i++)
        if(mas[i] == ',')
            mas[i] = '.';
}
int main()
{
    double distance = 0.f;
    double distance_current = 0.f;
    sDef min    = {NULL,NULL,NULL, NULL,NULL,NULL};;
    sDef defibr = {NULL,NULL,NULL, NULL,NULL,NULL};
    char LON[51];
    scanf("%s", LON);
    char LAT[51];
    scanf("%s", LAT);
    // change input data
    turn_comma_into_dot(LON);
    turn_comma_into_dot(LAT);
    g_vlon = atof(&LON[0]);
    g_vlat = atof(&LAT[0]);
    int N;
    scanf("%d", &N); fgetc(stdin);
    for (int i = 0; i < N; i++) 
    {
        char DEFIB[257];
        innit(&defibr);
        fgets(DEFIB, 257, stdin);
        turn_comma_into_dot(&DEFIB[0]);
        fillInform(&DEFIB[0],&defibr);
        //is thought that first the nearest
        distance_current = calculateDistance(&defibr);
        //printf("%f %s\n",distance_current,defibr.name);
        if(i == 0)
        {
            innit(&min);
            strcpy(min.name,defibr.name);
            strcpy(min.lon,defibr.lon);
            strcpy(min.lat,defibr.lat);
            distance = distance_current;
        }
        else
        {
            if(distance > distance_current)
            {
                clear(&min);
                innit(&min);
                strcpy(min.name,defibr.name);
                strcpy(min.lon,defibr.lon);
                strcpy(min.lat,defibr.lat);
                distance = distance_current;
            }
        }
        clear(&defibr);
    }
    printf("%s\n",min.name);
    return 0;
}
