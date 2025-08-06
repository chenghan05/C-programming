#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a = n%10;
    int b = n/10;
    printf("%d%d", a, b);
    return 0;
}