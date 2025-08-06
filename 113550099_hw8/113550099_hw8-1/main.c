#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rank.h"

#define MAX_SIZE 100
#define MAX_LEN 100
int N = 0;
Node *Table[MAX_SIZE];

int main()
{
    for (int i = 0; i < MAX_SIZE; i++)
        Table[i] = NULL;
    int t;
    scanf("%d", &t);

    char op[10];

    while (t--)
    {
        scanf("%s", op);
        if (strcmp(op, "A") == 0)
        {
            int score;
            char name[MAX_LEN + 1];
            scanf("%d %s", &score, name);

            Insert(Table, N, score, name);
            N++;
        }
        else if (strcmp(op, "B") == 0)
        {
            char name[MAX_LEN + 1];
            scanf("%s", name);

            Delete(Table, N, name);
            N--;
        }
        else if (strcmp(op, "C") == 0)
        {
            int x;
            scanf("%d", &x);

            int *idxs = Top(Table, N, x);
            printf("Top %d:\n", x);
            for (int i = 0; i < x; i++)
            {
                printf("%d %s\n", Table[idxs[i]]->score, Table[idxs[i]]->name);
            }
            free(idxs);
        }
    }
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (Table[i] != NULL)
        {
            free(Table[i]->name);
            free(Table[i]);
            Table[i] = NULL;
        }
    }

    return 0;
}