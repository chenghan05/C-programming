    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    int main(){
        char str[50];
        char cardtype[5005][30];
        int types = 0;
        int type[5005] = {0}; 
        while((scanf("%s", str)) != EOF){
            if(strcmp(str, "c") == 0)break;
            char temp[50];
            int templen = 0;
            for(int i=0; i<strlen(str); i++){
                if(isalpha(str[i])){
                    temp[templen] = str[i];
                    templen++;
                }
            }
            temp[templen] = '\0';
            if(templen > 0){
                int put = 0;
                for(int i=0; i< types; i++){
                    if(strcmp(cardtype[i], temp) == 0){
                        put = 1;
                        type[i]++;
                        break;
                    }
                }
                if(put == 0){
                    strcpy(cardtype[types], temp);
                    type[types]++;
                    types++;
                }
            }
        }
        
        int out[5005] = {0};
        int n=5;
        while(n--){
            int m = -1;
            int pos = 0;
            int len = 0;
            for(int i=0; i<types; i++){
                if(type[i] > m && out[i] == 0){
                    len = strlen(cardtype[i]);
                    m = type[i];
                    pos = i;
                }else if(type[i] == m && out[i] == 0 && strlen(cardtype[i]) > len){
                    len = strlen(cardtype[i]);
                    m = type[i];
                    pos = i;
                }
            }
            printf("%s %d\n", cardtype[pos], type[pos]);
            out[pos] = 1;
        }
        return 0;
    }