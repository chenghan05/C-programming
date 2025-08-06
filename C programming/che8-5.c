#include <stdio.h>

int fab(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return fab(n-1)+fab(n-2);
}

int main(){ 
    printf("%d", fab(40));


    return 0;
}