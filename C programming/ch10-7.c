#include <stdio.h>

int s[10][7]={{1,1,0,1,1,1,1},{0,0,0,1,0,0,1},{1,0,1,1,1,1,0},{1,0,1,1,0,1,1},{0,1,1,1,0,0,1},{1,1,1,0,0,1,1},{1,1,1,0,1,1,1},{1,1,0,1,0,0,1},{1,1,1,1,1,1,1},{1,1,1,1,0,0,1}};
char ch;
char ipt[100];
int len=0;

void printf_array(){
    for(int i=0; i<len; i++){
        if(ipt[i]>'9'||ipt[i]<'0')continue;
        printf(" ");
        if(s[ipt[i]-'0'][0]==1){
            printf(" _ ");
        }else{
            printf("   ");
        }
    }
    printf("\n");
    for(int i=0; i<len; i++){
        if(ipt[i]>'9'||ipt[i]<'0')continue;
        printf(" ");
        if(s[ipt[i]-'0'][1]==1){
            printf("|");
        }else{
            printf(" ");
        }
        if(s[ipt[i]-'0'][2]==1){
            printf("_");
        }else{
            printf(" ");
        }
        if(s[ipt[i]-'0'][3]==1){
            printf("|");
        }else{
            printf(" ");
        }
    }
    printf("\n");
    for(int i=0; i<len; i++){
        if(ipt[i]>'9'||ipt[i]<'0')continue;
        printf(" ");
        if(s[ipt[i]-'0'][4]==1){
            printf("|");
        }else{
            printf(" ");
        }
        if(s[ipt[i]-'0'][5]==1){
            printf("_");
        }else{
            printf(" ");
        }
        if(s[ipt[i]-'0'][6]==1){
            printf("|");
        }else{
            printf(" ");
        }
    }
}

int main(){
    while((ch=getchar())!='\n'){
        ipt[len]=ch;
        len++;
    }
    printf_array();
    return 0;
}