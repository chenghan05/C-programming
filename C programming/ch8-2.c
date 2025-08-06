#include <stdio.h>

void print_digit(int a){
    int t[10]={0};
    while(a!=0){
        int num= a%10;
        t[num]++;
        a/=10;
    } 
    printf("DIGIT      : 0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:");
    for(int i=0; i<10; i++){
        printf(" %d", t[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    print_digit(n);
    return 0;
}