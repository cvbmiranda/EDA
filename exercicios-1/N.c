#include<stdio.h>
#include<string.h>

int encaixa(int a, int b){
    char str1[20], str2[20];

    sprintf(str1, "%d", a);
    sprintf(str2, "%d", b);

    if(strstr(str1,str2) != NULL){ 
        return 1;
    } else{
        return 0;
    }
}

int segmento(int a, int b){
    if(a<b){
        return encaixa(b,a); 
    }
    if(a>=b){
        return encaixa(a,b);
    }
}
