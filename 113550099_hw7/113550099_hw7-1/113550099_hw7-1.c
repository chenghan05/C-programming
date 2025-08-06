#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str1[500]="";
char str2[500]="";
char num1[500]="";
char num2[500]="";
char preans[500]="";
char preans2[500]="";
char ans[500]="";
int len1=0, len2=0, rep1=0, rep2=0, prelen=0, rep=0, len=0;

int read_line(char *c, char *n, int k){
    int i=0;
    int len=0;
    while(*(c+i) != '@'){
        if(*(c+i) != ','){
            *(n+len) = *(c+i);
            len++;
        }
        i++;
    }
    i++;
    char ch[5];
    int lench=0;
    while(*(c+i)!='\0'){
        ch[lench++] = *(c+i);
        i++;
    }
    lench--;
    if(k==1){ 
        if(lench==1){
            rep1=10;
        }else{
            rep1 = ch[0]-'0';
        }
    }else{
        if(lench==1){
            rep2=10;
        }else{
            rep2 = ch[0]-'0';
        }
    }
    return len;
}

void expend_num(char *c, int l, int n){
    if(n==0){
        for(int i=0; i<l; i++){
            *c = '0';
        }
    }else{
        for(int i=0; i<n; i++){
            for(int j=0; j<l; j++){
                *(c+i*l+j)=*(c+j);
            }
        }
    }
}

void reverse(char *c, int l){
    char *last;
    last = c+l-1;
    char temp;
    while(c<last){
        temp = *c;
        *c = *last;
        *last = temp;
        last--;
        c++;
    }
}

void add(char *c1, char *c2, int len){
    int carry = 0;  
    if(len>len1){
        for(int i=len1; i<len; i++){
            num1[i]='0';
        }
        num1[len]='\0';
    }else if(len>len2){
        for(int i=len2; i<len; i++){
            num2[i]='0';    
        }
        num2[len]='\0';
    }
    for(int i=0; i<len; i++){
        preans[i] = (((*(c1+i)-'0')+(*(c2+i)-'0'))+carry)%10+'0';
        carry = (((*(c1+i)-'0')+(*(c2+i)-'0'))+carry)/10;
    }
    if(carry!=0){
        preans[len] = carry+'0';
        prelen++;
    }
}

int compress(int len){
    int test = 0;
    int l=1;
    char *p = preans;
    while(test==0&&l<len){
        if(*p == *(p+l)){
            if(len%l!=0){
                l++;
                continue;
            }
            test=1;
            for(int i=1; i<(len/l); i++){
                for(int j=0; j<l; j++){
                    if(preans[i*l+j] != preans[j]){
                        test=0;
                    }
                }
                if(test == 0){
                    l++;
                    continue;
                }
            }
        }else{
            l++;
        }
    }
    return len/l;
}

int putcomma(int l){
    int k=1;
    ans[0] = preans[0];
    for(int i=1; i<l; k++){
        if(k%4 == 3){
            ans[k] = ',';
        }else{
            ans[k] = preans[i];
            i++;
        }
    }
    return k;
}

int reduced(){
    int i=0;
    while(ans[i]=='0'||ans[i]==','){
        i++;
    }
    return i;
}

int main(){
    scanf("%s\n%s", str1, str2);
    len1 = read_line(str1, num1, 1);
    len2 = read_line(str2, num2, 2);
//    printf("%s\n%s\n%s\n%s\n%d %d %d %d\n", str1, str2, num1, num2, len1, len2, rep1, rep2);
    expend_num(num1, len1, rep1);
    len1 *= rep1;
    expend_num(num2, len2, rep2);
    len2 *= rep2;
    reverse(num1, len1);
    reverse(num2, len2);
    if(len1>len2){
        prelen=len1;
    }else{
        prelen=len2;
    }
//        printf("%s\n%s\n", num1, num2);
    add(num1, num2, prelen);
//        printf("%s\n", preans);
    rep = compress(prelen);
    len = prelen/rep;
    int anslen = putcomma(len);
    reverse(ans, anslen);
    if(ans[0]=='0'&&anslen==1){
        printf("%s@%d\n", ans, rep);  
    }else{
        int b = reduced();
        char *p = ans+b;
        printf("%s@%d\n", p, rep); 
    }       

    return 0;
}