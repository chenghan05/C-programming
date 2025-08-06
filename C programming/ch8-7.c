#include <stdio.h>

int main(){
    int a[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Row totals:");
    for(int i=0; i<5; i++){
        int sum=0;
        for(int j=0; j<5; j++){
            sum+=a[i][j];
        }
        printf(" %d", sum);
    }
    printf("\nColumn totals:");
    for(int i=0; i<5; i++){
        int sum=0;
        for(int j=0; j<5; j++){
            sum+=a[j][i];
        }
        printf(" %d", sum);
    }    

    return 0;
}