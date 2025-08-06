#include <stdio.h>
#include <stdlib.h>
int n, m, op, a, v;

int main(){
    scanf("%d %d", &n, &m);
    int **ptr = malloc((n+1)*sizeof(int*));
    int len[1000005]={0};
    while(m--){
        scanf("%d %d", &op, &a);
        if(op == 1){
            scanf("%d", &v);
            if(len[a]==0){
                ptr[a] = malloc(sizeof(int));
            }else{
                ptr[a] = realloc(ptr[a], (len[a]+1)*sizeof(int));
            }
            ptr[a][len[a]]=v;
            len[a]++;

        }else{
            if(len[a]==0){
                continue;
            }else{
                len[a]--;
                if(len[a]==0){
                    free(ptr[a]);
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(len[i] == 0){
            printf("\n");
        }else{
            for(int j=0; j<len[i]-1; j++){
                printf("%d ", ptr[i][j]);
            }
            printf("%d\n", ptr[i][len[i]-1]);
        }
    }
    return 0;
}