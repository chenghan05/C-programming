#include <stdio.h>
#include <stdlib.h>
void reverse(char *arr, char *p){
    while(p!=arr){
        printf("%c", *p);
        p--;
    }
    printf("%c", *p);
}

int main(){
    char ch;
    char *charr = malloc(sizeof(char));
    int len=1;
    char *point = charr;
    scanf("%c", &ch);
    while((ch=getchar())!='\n'){
        charr = realloc(charr, ++len*sizeof(char));
        charr[len-1]=ch;
        point = charr+len-1;
    }
    reverse(charr, point);

    return 0;
}