#include <stdio.h>

int main(){
    char ch;
    while((ch=getchar())!='\n'){
        if(ch-65>=0&&ch-65<26){
            int n=(ch-65)/3;
            printf("%d", 2+n);
        }else{
            printf("%c", ch);
        }
    }
    return 0;
}