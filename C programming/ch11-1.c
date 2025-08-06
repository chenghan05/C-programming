#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
    *twenties = dollars/20;
    dollars %= 20;
    *tens = dollars/10;
    dollars %= 10;
    *fives = dollars/5;
    dollars %= 5;
    *ones = dollars;
}

int main(){
    int n;
    int a[4]={0};
    scanf("%d", &n);
    pay_amount(n, &a[0], &a[1], &a[2], &a[3]); 
    printf("%d %d %d %d", a[0], a[1], a[2], a[3]);
    return 0;
}