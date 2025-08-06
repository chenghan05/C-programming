#include <stdio.h>

int main(){
    int n;
    int o[10];
    int i=0;
    scanf("%d", &n);
    printf("%05o\n", n);
    while(n%8!=0){
        o[i]=n%8;
        n/=8;
        i++;
    }
    for(int j=--i; j>=0; j--){
        printf("%5d", o[j]);
    }
    return 0;
}