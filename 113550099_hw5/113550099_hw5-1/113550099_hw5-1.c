#include <stdio.h>

int m, n;
int arr[100005];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverserow(int *a, int*b){
    if(a>=b)return;
    for(int i=0; i<n; i++){
        swap((a+i), (b+i));
    }
    reverserow((a+n), (b-n));
}

void reverseelement(int *a){
    int i=0, j=n-1;
    while(i<j){
        swap((a+i), (a+j));
        i++;
        j--;
    }
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i*n+j]);
        }
    }
    reverserow(arr, (arr+(m-1)*n));
    for(int i=0; i<m; i++){
        reverseelement(arr+i*n);
    }
    for(int i=0 ;i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i*n+j]);
        }
        printf("\n");
    }
    return 0;
}