#include <stdio.h>

int main(){
    int N,M,temp,t=0;
    int n[1005]={0};
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%d", &n[i]);
    }
    for(int i=0; i<N;i++){
        for(int j=0; j<N-i-1; j++){
            if(n[j]>n[j+1]){
                temp=n[j];
                n[j]=n[j+1];
                n[j+1]=temp;
            }
        }
    }
    for(int i=0; i<N;){
        if((i<(N-1)) && ((n[i+1]-n[i]) <= M)){
            i+=2;
        }else{
            t++;
            i++;
            if(t>1){
                break;
            }
        }
    }
    if(t>1){
        printf("No");
    }else{
        printf("Yes");
    }

    return 0;
}