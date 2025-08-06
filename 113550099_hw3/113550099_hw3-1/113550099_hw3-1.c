#include <stdio.h>

int main(){
    int N[105];
    int n,t,ans=0,now;
    for(int i=0; i<105; i++){
        N[i]=0;
    }
    scanf("%d", &n);
    t=n;
    for(int i=0; i<n; i++){
        scanf("%d", &N[i]);
        if(N[i]==0)t--;
    }
    while(t){
        now=0;
        while(N[now]==0){
            now++;
            if(now==n)break;
        }
        while(N[now]!=0&&now<n){
            N[now]--;
            if(N[now]==0)t--;
            now++;
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}