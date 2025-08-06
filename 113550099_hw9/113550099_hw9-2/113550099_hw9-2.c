#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Rhythm {
    QUARTER_NOTE=1, HALF_NOTE=2, WHOLE_NOTE=4
};
enum Note {
    C = 1, D,E,F,G,A,B 
};

int main() {
    int n;
    scanf("%d", &n);
    char de[10];
    int conti = 1;
    int beat = 0;
    int sec = 0;
    while(n-- && conti){
        sec = 0;
        beat = 0;            
        scanf("%s", de);
        printf("%s", de);
        if(strcmp(de, "||") == 0){
            conti = 0;
            break;
        }
        while(sec < 4 && conti){
            beat = 0;
            while(beat < 4 && conti){
                char num[5];
                char last[20];
                scanf("%s%s", num, last);
                enum Note notevalue;
                if(strcmp("C", num)==0){
                    notevalue = C;
                }else if(strcmp("D", num)==0){
                    notevalue = D;
                }else if(strcmp("E", num)==0){
                    notevalue = E;
                }else if(strcmp("F", num)==0){
                    notevalue = F;
                }else if(strcmp("G", num)==0){
                    notevalue = G;
                }else if(strcmp("A", num)==0){
                    notevalue = A;
                }else if(strcmp("B", num)==0){
                    notevalue = B;
                }
                printf(" %d", notevalue);
                enum Rhythm rhythmvalue;
                if(strcmp("QUARTER_NOTE", last) == 0){
                    rhythmvalue = QUARTER_NOTE;
                }else if(strcmp("HALF_NOTE", last) == 0){
                    rhythmvalue = HALF_NOTE;
                }else if(strcmp("WHOLE_NOTE", last) == 0){
                    rhythmvalue = WHOLE_NOTE;
                }
                beat += rhythmvalue;
                for (int i = 1; i < rhythmvalue; i++) {
                    printf(" -");
                }            
            }
            sec++;
            scanf("%s", de);
            printf(" %s", de);
            if(strcmp(de, "||") == 0){
                conti = 0;
                break;
            }
        }
        
        printf("\n");
    }

    return 0;
}