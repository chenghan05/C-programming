#include <stdio.h>

int main(){
    int grade;
    scanf("%d", &grade);
    int g = grade/10;
    switch(g){
        case 10: 
            if(grade>100){
                printf("error");
            }else{
                printf("A");
            }
            break;
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");break;
        case 7:
            printf("C");break;
        case 6:
            printf("D");break;
        case 0:
            if(grade<0){
                printf("error");
            } else{
                printf("F");
            }
            break;
        default:
            printf("F");
            break;
    }


    return 0;
}