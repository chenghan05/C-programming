#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rank.h"

void Insert(Node **Table, int N, int score, char *name){
    Table[N] = malloc((strlen(name)+1)*sizeof(char) + sizeof(int));
    Table[N]->score = score;
    Table[N]->name = malloc((strlen(name)+1)*sizeof(char));
    strcpy(Table[N]->name, name);
}

void Delete(Node **Table, int N, char *name){
    for(int i=0; i<N; i++){
        if(strcmp(Table[i]->name, name) == 0){
            for(int j=i; j<N-1; j++){
                strcpy(Table[j]->name, Table[j+1]->name);
                Table[j]->score = Table[j+1]->score;
            }
            Table[N-1]  =NULL;
            break;
        }
    }
}

int *Top(Node **Table, int N, int x){
    for(int i=0; i<N; i++){
        for(int j=0; j<N-i-1; j++){
            if(Table[j]->score > Table[j+1]->score){
                Node *temp = Table[j];
                Table[j] = Table[j+1];
                Table[j+1] = temp;
                /*
                char *name = malloc(101*sizeof(char));
                strcpy(name, Table[j]->name);
                int score = Table[j]->score;
                strcpy(Table[j]->name, Table[j+1]->name);
                Table[j]->score = Table[j+1]->score;
                strcpy(Table[j+1]->name, name);
                Table[j+1]->score = score;
                free(name);
                */
            }else if(Table[j]->score == Table[j+1]->score){
                if(strcmp(Table[j]->name, Table[j+1]->name) < 0){
                    Node *temp = Table[j];
                    Table[j] = Table[j+1];
                    Table[j+1] = temp;
                    /*
                    char *name = malloc(101*sizeof(char));
                    strcpy(name, Table[j]->name);
                    int score = Table[j]->score;
                    strcpy(Table[j]->name, Table[j+1]->name);
                    Table[j]->score = Table[j+1]->score;
                    strcpy(Table[j+1]->name, name);
                    Table[j+1]->score = score;
                    free(name);
                    */
                }
            }
        }
    }
    int *top = malloc((x+1)*sizeof(int));
    for(int i=0; i<x; i++){
        *(top+i) = N-i-1;
    }
    return top;
}

// TODO