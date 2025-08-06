#include <stdio.h>

int power(int a, int b){
    if(b==0)return 1;
    return a*power(a,b-1);
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d", 3*power(x,5)+2*power(x,4)-5*power(x,3)-power(x,2)+7*x-6);
    return 0;
}