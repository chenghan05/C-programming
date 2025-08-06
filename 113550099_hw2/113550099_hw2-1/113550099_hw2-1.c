#include <stdio.h>

int main(){
    int p,pm,r,n,ans=0,b=0,bc=0;
    scanf("%d %d %d %d", &p, &pm, &r, &n);
    while(pm>=p || b>=n){
        b+=pm/p;//money to bottle
        bc+=pm/p;//money to bottle cap
        pm= pm%p;//cost money
        if(b>=n){//bottle to bottle
            ans+=n*(b/n);//bottle to money
            bc+=b/n;//bottle to bottle cap
            b = b%n+b/n;
        }
        pm+=bc*r;//bottle cap to money
        bc=0;
    }
    ans+=b;
    printf("%d", ans);
    return 0;
}