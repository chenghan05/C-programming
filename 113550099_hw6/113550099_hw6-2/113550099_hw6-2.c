#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int po = 1;
typedef struct node{
    int data;
    struct node* next;
} Node;

Node* head = NULL;
Node* nowpos;

void insert(int p, int d){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = d;
    if(p==0){
        new->next = head;
        head = new;
        nowpos=new;
        return;
    }else if(head==NULL){
        free(new);
        printf("Invalid insertion\n");
        return;
    }
    int i=po;
    if(i>p){
        printf("Invalid insertion\n");
        free(new);
        return;
    }
    Node* front = nowpos;
    while(front!=NULL && front->next!=NULL && i!=p){
        i++;
        front = front->next;
    }
    if(i==p){
        po=p;
        nowpos=front;
        new->next = front->next;
        front->next = new;
        return;
    }else{
        free(new);
        printf("Invalid insertion\n");
        return;
    }
}

void delete(int p){
    if(head==NULL){
        printf("Invalid deletion\n");
        return;
    }
    Node* front = nowpos;
    if(p==0){
        nowpos=head->next;
        head = head->next;
        free(front);
        return;
    }
    int i=po;
    if(i>p){
        printf("Invalid deletion\n");
        return;
    }
    while(i<p){
        if(front!=NULL&&front->next!=NULL){
            front = front->next;
            i++;
        }else{
            printf("Invalid deletion\n");
            return;
        }
    }
    Node* mid = front->next;
    if(mid==NULL){
        printf("Invalid deletion\n");
        return;
    }else{
        mid = mid->next;
        free(front->next);
        front->next = mid;
    }

}

void printList(){
    Node* node = head;
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(){
    Node *cur = head, *tmp;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = NULL;
}

int main(){
    nowpos=head;
    int position, data;
    char op;
    while(scanf(" %c", &op) != EOF){
        switch(op){
            case 'A':
                scanf("%d%d", &position, &data);
                insert(position, data);
                break;
            case 'B':
                scanf("%d", &position);
                delete(position);
                break;
            default:
                printf("Wrong OP\n");
                break;
        }
        if(op=='i')break;
    }
    printList();
    freeList();
    return 0;
}
