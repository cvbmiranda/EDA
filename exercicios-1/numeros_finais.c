#include<stdio.h>
#include<string.h>

int encaixa(int a, int b){
    char str1[20], str2[20];

    sprintf(str1, "%d", a);
    sprintf(str2, "%d", b);

    int tam1 = strlen(str1);
    int tam2 = strlen(str2);

    if(tam2 > tam1){ 
        return 0;
    }


    if(strcmp(str1 + tam1 - tam2, str2) == 0){
        return 1;
    } else{
        return 0;
    }
}
