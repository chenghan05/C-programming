#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int x;
    int y;
    int order;
    struct node* next;
} Node;

Node* head = NULL;

int m,n;
int map[12][12];
int check[12][12][4];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char dc[4]={'D','U','R','L'};
int found = 0;
char ch[105];

void pop_front();
void push_back(int,int,int);
void printList();

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &map[i][j]);
            check[i][j][0]=0;
            check[i][j][1]=0;
            check[i][j][2]=0;
            check[i][j][3]=0;
        }
    }
    push_back(1,1,0);
    while(head!=NULL){
        int x = head->x;
        int y = head->y;
        int p = head->order;
        if(x==n&&y==m){
            found=1;
            break;
        }
        pop_front();
        if(check[x][y][0]==1)continue;
        check[x][y][0]=1;
        for(int i=0; i<4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx>0 && xx<=n && yy>0 && yy<=m){
                if(check[xx][yy][0]==0 && map[xx][yy]!=0){
                    check[xx][yy][1] = x;
                    check[xx][yy][2] = y;
                    check[xx][yy][3] = p+1;
//                    printf("%d %d %d %d\n", xx, yy, i, p);
                    push_back(xx,yy,p);
                }
            }
        }
    }
    if(found == 1){
        int len=0;
        int p = head->order;
        printf("%d\n", p);
        int x = n;
        int y = m;
        int xx = check[x][y][1];
        int yy = check[x][y][2];
        while(x!=1||y!=1){
//            printf("%d %d %d %d\n", x ,y, xx, yy);
            for(int i=0; i<4; i++){
                if(x-xx==dx[i]&&y-yy==dy[i]){
                    ch[len]=dc[i];
                    len++;
                }
            }
            x = xx;
            y = yy;
            xx = check[x][y][1];
            yy = check[x][y][2];
        }
        for(int i=len-1; i>=0; i--){
            printf("%c", ch[i]);
        }
    }else{
        printf("-1");
    }
//    printList();
    return 0;
}

void pop_front(){
    Node*front=head;
    if(head != NULL){
        head = head->next; 
        free(front);
    }
    return;
}

void push_back(int x, int y, int k){
    Node*new = (Node*)malloc(sizeof(Node));
    new->x = x;
    new->y = y;
    new->order = k+1;
    new->next=NULL;
    if(head == NULL){
        head = new;
        return;
    }
    Node* last = head;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = new;
    return;
}

void printList(){
    Node* node = head;
    while(node != NULL){
        printf("%d %d \n", node->x, node->y);
        node = node->next;
    }
    printf("\n");
}

