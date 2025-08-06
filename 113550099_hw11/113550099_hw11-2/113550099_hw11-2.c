# include <stdio.h>
# include <stdlib.h>
int po=1;
typedef struct node{
    int data;
    struct node* next;
} Node;

Node *last = NULL;
Node *now = NULL;

void delete(int p){
    //no node
    if(last == NULL){
        printf("Invalid deletion\n");
        return;
    }
    //delete only node
    if(last->next == last){
        Node*temp = last;
        free(temp);
        last = NULL;
        now = NULL;
        return;
    }
    if(p == 0){
        Node* temp = last->next;
        last->next = temp->next;
        now = last->next;
        free(temp);
        return;
    }
    Node* front = now;
    int i=po;
    while(front->next != last->next && i<p){
        front = front->next;
        i++;
    }
    if(front == last){
        printf("Invalid deletion\n");
        return;
    }
    Node* temp = front->next;
    front->next = temp->next;
    if(temp == last){
        last = front;
    }
    po = p;
    now = front;
    free(temp);
}

void insert(int p, int d){
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = d;
    //first insert
    if(last == NULL){
        if(p!=0){
            printf("Invalid insertion\n");
            free(new);
            return;
        }
        new->next = new;
        last = new;
        now = new;
        return;
    }
    //insert at beginning
    if(p == 0){
        new->next = last->next;
        last->next = new;
        now = new;
        return;
    }
    Node* front = now;
    int i=po;
    while(front->next != last->next && i<p){
        front = front->next;
        i++;
    }
    if(i!=p){
        printf("Invalid insertion\n");
        return;
    }
    Node* temp = front->next;
    new->next = temp;
    front->next = new;
    po = p;
    now = front;
    if(front == last){
        last = new;
    }
}

void printList() {
    Node* p;

    if (last == NULL) {
        return;
    }

    p = last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("\n");
}

void freeList(){
    Node* p;
    if (last == NULL) {
        return;
    }
    p=last;
    while (p->next != p){
        Node* temp;
        temp = p->next;
        p->next = temp->next;
        free(temp);
        p = p->next;
    } 
    free(p);
}

int main(){
    int nowp = 0;
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
            /*case 'C':
                printList();
                break;
*/
            default:
                printf("Wrong OP\n");
                break;
        }
    }
    printList();
    freeList();
    return 0;
}
