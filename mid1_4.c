#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void rotateList(Node**,int);

void freeList(Node *head);
Node* createList();
void printList(Node *head);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;
	int k;

    	head = createList();
	scanf("%d",&k);	
	rotateList(&head,k);
	printList(head);
	freeList(head);
	return 0;
}



void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

Node* createList(){
    Node* head = NULL;
    Node* temp = NULL;
    int data;

    while(1){
        scanf("%d",&data);
        if(data>-1){
            if (temp==NULL) {
                temp = (Node*) malloc(sizeof(Node));
                head = temp;
            } else {
                temp->next = (Node*) malloc(sizeof(Node));
                temp = temp->next;
            }
            temp->data = data;
            temp->next = NULL;
        } else break;
    }
    return head;
}

void printList(Node *head)
{
	Node *temp=head;
	printf("%d", temp->data);
	temp=temp->next;
	
	for(; temp!=NULL; temp=temp->next)
	{
		printf(" %d", temp->data);
	}
	printf("\n");
}
void rotateList(Node** root,int k){
    Node *head = *root;
    Node *pre_head;
    Node *org_head = *root;
    int i;
    while(1){
        if(head->next == NULL){
            head->next = org_head;
            break;
        }
        head = head->next;
    }
    //printf("heallo");
    head = org_head;
    for(i=0; i<k-1; i++){
        head = head->next;
    }
    pre_head = head;
    head = head->next;
    *root = head;
    pre_head->next = NULL;
    return ;
}