#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        int data;
        struct node *next;
} Node;
Node* create(int n);
void josephus(int m,Node *head);

int main(void){
	int n,m;
	scanf("%u %u",&n, &m);
	josephus(m,create(n));
}
Node* create(int n){
    Node *start = (Node* )malloc(sizeof(Node));
    Node *temp;
    int i;

    start->data = 1;
    temp = start;

    for(i=2; i<=n; i++){
        Node *dot = (Node* )malloc(sizeof(Node));
        dot->data = i;
        temp->next = dot;
        temp = dot;
    }

    temp->next = start;
    return temp;
}
void josephus(int m, Node *head){
    if(head->next == head){
        printf("%d\n", head->data);
        free(head);
        return ;
    }
    else{
        Node *now, *prev;
        int k;
        prev = head;
        for(k=0; k<m-1; k++){
            prev = prev->next;
        }
        now = prev->next;

        prev->next = now->next;
        printf("%d ", now->data);
        free(now);
        josephus(m, prev);
    }
}