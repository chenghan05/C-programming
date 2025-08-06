#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DRAW 5

int numCards = 0;

int main(int argc, char *argv[]) {
    // set seed
    int seed = atoi(argv[1]);
    srand(seed);

    // 1. Read own cards
    FILE *f = fopen("OwnCards.txt", "r");
    // Your code here
    char str[40];
    char owncards[200][50];
    int num[200] = {0};
    int typenum = 0;
    while((fscanf(f, "%s %d", str, &num[typenum]))  != EOF){
        numCards += num[typenum];
        strcpy(owncards[typenum], str);
        typenum++;
    }
    fclose(f);

    printf("You have %d cards\n", numCards);

    // 2. Select pool
    printf("Select pool: \n");
    char poolName[100];
    scanf("%s", poolName);

    // 3. Read pool cards and percentages
    f = fopen(poolName, "r");
    // Your code here
    int p[100] = {0};
    int n, card = 1;
    char cards[100][50];
    p[0] = 0;
    while((fscanf(f, "%s %d", str, &n)) != EOF){
        strcpy(cards[card], str);
        p[card] = p[card-1] + n;
        card++;
    }
    fclose(f);
    // 4. Draw new cards
    char draw[5][50];
    printf("\nYour new cards are: \n");
    for(int i=0; i<5; i++){
        int proba = rand()%100;
        for(int j=1; j < card; j++){
            if( p[j-1] <= proba  && proba < p[j]){
                strcpy(draw[i], cards[j]);
                printf("%s\n", draw[i]);
            }
        }
    }
    // Your code here

    char result[40];
    if(strcmp(poolName, "poolCharizard.txt") == 0) {
        strcpy(result, "CharizardDraw.txt");
    } else if (strcmp(poolName, "poolMewtwo.txt") == 0) {
        strcpy(result, "MewtwoDraw.txt");
    } else if (strcmp(poolName, "poolPikachu.txt") == 0) {
        strcpy(result, "PikachuDraw.txt");
    } 
    
    int check[5] = {0};
    for(int i=0; i<typenum; i++){
        for(int j=0; j<5; j++){
            if(strcmp(draw[j], owncards[i]) == 0){
                num[i]++;
                check[j] = 1;
            }
        }
    }
    int k=0;
    while(k<5){
        if(check[k] == 0){
            for(int i=typenum-5; i<typenum; i++){
                if(strcmp(owncards[i], draw[k]) == 0){
                    num[i]++;
                    check[k] = 1;
                }
            }
            if(check[k] == 0){
                strcpy(owncards[typenum], draw[k]);
                num[typenum]++;
                typenum++;
                check[k] = 1;
            }
        }
        k++;
    }
    
    // 5. Write new own cards
    f = fopen(result, "w");
    // Your code here
    for(int i=0; i<typenum; i++){
        fprintf(f, "%s %d\n", owncards[i], num[i]);
    }
    fclose(f);
    return 0;
}