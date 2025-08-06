#include <stdio.h>

int main(){
    int m,s;
    scanf("%d %d", &m, &s);
    int ans=s;
    if(m-s*9==0){
        printf("%d", s);
    }else if(m<s||(m==6)&&(s==1)){
        printf("Sad moon festival QQ");
    }else if(m-s*9>0){
        printf("%d", s-1);
    }else{
        while(ans>0&&((m-ans*9)<(s-ans))){
            ans--;
        }
        if((m-ans*9==6)&&(s-ans==1)){
            printf("%d", ans-1);
        }else{
            printf("%d", ans);
        }
    }
    return 0;
}