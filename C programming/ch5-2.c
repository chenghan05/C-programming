#include <stdio.h>

int main(){
    int hour,min;
    scanf("%d:%d", &hour, &min);
    if(hour>=12&&min!=0){
        printf("%2d:%02d PM", hour-12, min);
    }else{
        printf("%2d:%02d AM", hour, min);
    }

    return 0;
}