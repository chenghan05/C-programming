#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int i=2;
    for(; i<=n; i+=2){
        printf("%d\n", i*i);
    }   
    return 0;
}