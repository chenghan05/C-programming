//輾轉相除法
#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    if(b>a){
        int temp=a;
        a=b;
        b=temp;
    }
    while(a!=0 && b!=0){
        if(a>=b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a>=b){
        printf("%d", a);
    }else{
        printf("%d", b);
    }
    return 0;
}