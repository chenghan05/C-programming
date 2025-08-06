//notice!!! hard recursion to me
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *c){
    int s = strlen(c);
    char *p;
    p = c+s-1;
    char temp;
    while(c<p){
        temp = *c;
        *c = *p;
        *p = temp;
        p--;
        c++;
    }
}

int duel(int left, int right, char **str){
    if(left == right){
        return left;
    }
    int m = (left+right)/2;
    if(left<right){
        return duel(duel(m+1, right, str), duel(left, m, str), str);
    }
//    printf("%d, %d, %d\n", left, right, strcmp(str[left], str[right]));
    //left > right
//    printf("%ld, %ld\n", strlen(str[left]), strlen(str[right]));
    if(strcmp(str[left], str[right])>0){
        str[left] = realloc(str[left],(strlen(str[left])+strlen(str[right])+1)*sizeof(char));
        str[left] = strcat(str[left], str[right]);
        reverse(str[left]);
        free(str[right]);
        return left;
    }else{
        str[right] = realloc(str[right],(strlen(str[left])+strlen(str[right])+1)*sizeof(char));
        str[right] = strcat(str[right], str[left]);
        reverse(str[right]);
        free(str[left]);
        return right;
    }
}



int main(){
    int N;
    char **str = malloc(1025*sizeof(char*));
    scanf("%d\n", &N);
    for(int i=0; i<N; i++){
        str[i] = malloc(12*sizeof(char));
        scanf("%s", str[i]);
    }
    int winner = duel(0, N-1, str);
    printf("%d %s", winner, str[winner]);
    return 0;
}