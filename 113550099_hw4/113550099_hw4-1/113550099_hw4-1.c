#include <stdio.h>
typedef  unsigned long long ull; 

int n;
ull m;

ull power(ull a, int b){
    ull pow=1;
    if(b==0)return pow;
    for(int i=0; i<b; i++){
        pow *= a;
    }
    return pow;
}

ull cal(int t){
    if(t<=1)return 0;
    if(t==2)return 1;
    return m*cal(t-1)+ m*cal(t-2)+ power(m+1, t-2);
}

int main(){
    scanf("%d %llu", &n, &m);
    m--;//0<=m<=19
    if(n==1){
        printf("0");
    }else if(n==2||m==0){
        printf("1");
    }else{
        printf("%llu", cal(n));
    }
    return 0;
}
