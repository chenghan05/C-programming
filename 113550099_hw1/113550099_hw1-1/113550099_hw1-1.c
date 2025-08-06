#include <stdio.h>

int main(){
    int y,m,d;
    scanf("%d/%d/%d", &y,&m, &d);
    y = y+1911;
    printf("Germany: %02d.%02d.%04d\n", d, m, y);
    printf("Belgium: %02d/%02d/%04d\n", d, m, y);
    printf("Taiwan: %04d/%02d/%02d\n", y, m, d);
    y = y%100;
    printf("US: %02d/%02d/%02d\n", m, d, y);
    printf("UK: %02d/%02d/%02d", d, m, y);
    return 0;
}