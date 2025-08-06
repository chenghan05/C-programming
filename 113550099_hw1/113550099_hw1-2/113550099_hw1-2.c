#include <stdio.h>

int main(){
    int n1,n2,la,lp;
    float ai;
    scanf("$%d,%d %f %d", &n1, &n2, &ai, &lp);
    la = 1000*n1+n2;
    int ans[6];
    int mon[6] = {2000,1000,500,100,10,1};
    for(int i=0; i<6; i++){
        ans[i] = la/mon[i];
        la -= mon[i]*ans[i];
    }
    printf("| $2000| $1000| $500| $100| $10| $1|\n");
    printf("|%6d|%6d|%5d|%5d|%4d|%3d|\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);
    printf("Monthly interest rate: %.2f%%\n", ai/12);
    float l = n1*1000+n2;
    printf("Total loan amount: %.1f", l*(1+lp*ai/1200));
    return 0;
}