#include <stdio.h>

int main(){
    char ch;
    double sum=0;
    double n=1;
    while((ch=getchar())!='\n'){
        if(ch==' '){
            n++;
        }else{
            sum++;
        }
    }
    printf("%.1f", sum/n);
    
    return 0;
}