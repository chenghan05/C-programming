#include <stdio.h>

int main(){
    int a[4];
    scanf("%d", &a[0]);
    int maxx = a[0];
    int minn = a[0];
    for(int i=1; i<4; i++){
        scanf("%d", &a[i]);
        if(maxx<a[i]){
            maxx = a[i];
        }
        if(minn>a[i]){
            minn = a[i];
        }
    }
    printf("Largest: %d\nSmallest: %d", maxx, minn);
    
    return 0;
}