#include <stdio.h>
int N;
int n[1028];

int duel(int l, int r){
    if(l<r){
        return duel(duel((r+l)/2+1, r), duel(l, (l+r)/2));
    }
    if(l==r)return l;
    //r<l
    if(n[r] >= n[l]){
        n[r] = n[r] - n[l];
        return r;
    }else{
        n[l] = n[l] - n[r];
        return l;
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &n[i]);
    }
    int winner = duel(0, N-1);
    printf("%d %d", winner, n[winner]);
    return 0;
}