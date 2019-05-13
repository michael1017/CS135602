#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int data;
	struct node *next;
}Node;

Node* setup(int );
void get_and_do_oper(int , Node* );
Node* do_oper_on(Node* , int, int);
Node* do_oper_under(Node* , int, int);
Node* do_oper_rm(Node* , int);
int can_do_move(Node* ,int , int);
int can_do_rm(Node* ,int );
void show_list(Node* );
int main(void){
	int t;
	Node *head;

	scanf("%d", &t);
	head = setup(t);
	get_and_do_oper(t, head);

}
Node* setup(int len){
	Node* head = (Node* )malloc(sizeof(Node));
	Node* temp;
	int i;
	temp = head;
	head->data = 0;
	head->next = NULL;
	for(i=1; i<len; i++){
		Node *dot = (Node* )malloc(sizeof(Node));
		dot->data = i;
		dot->next = NULL;
		temp->next = dot;
		temp = dot;
	}
	return head;
}
void get_and_do_oper(int len, Node *head){
	char act[10], oper[10];
	int a, b;
	while(1){
		scanf("%s", act);
		if(!strcmp(act, "move")){
			scanf("%d %s %d", &a, oper, &b);
			if(a>=len || b>=len || a<0 || b<0 || !can_do_move(head, a, b)){
				continue;
			}
			else if(!strcmp(oper, "on")){
				head = do_oper_on(head, a, b);
			}
			else if(!strcmp(oper, "under")){
				head = do_oper_under(head, a, b);
			}
		}
		else if(!strcmp(act, "remove")){
			scanf("%d", &a);
			if(a>=len || a<0 || !can_do_rm(head, a)){
				continue;
			}
			else{
				head = do_oper_rm(head, a);
			}
		}
		else if(!strcmp(act, "exit")){
			show_list(head);
			break;
		}
		//show_list(head);
	}
}
Node* do_oper_on(Node *head, int a, int b){
	Node *temp = NULL, *i;
	Node *aptr = NULL, *bptr = NULL, *a_prev, *b_prev;
	for(i=head; i!=NULL && aptr==NULL; i=i->next){
		if(i->data == a){
			aptr = i;
			a_prev = temp;
		}  
		temp = i;
	}
	if(a_prev == NULL){
		head = aptr->next;
	}
	else{
		a_prev->next = aptr->next;
	}
	for(i=head; i!=NULL && bptr==NULL; i=i->next){
		if(i->data == b){
			bptr = i;
		}  
	}
	aptr->next = bptr->next;
	bptr->next = aptr;
	return head;

}
Node* do_oper_under(Node *head, int a, int b){
	Node *temp = NULL, *i;
	Node *aptr = NULL, *bptr = NULL, *a_prev, *b_prev;
	for(i=head; i!=NULL && aptr == NULL; i=i->next){
		if(i->data == a){
			aptr = i;
			a_prev = temp;
		}  
		temp = i;
	}
	if(a_prev == NULL){
		head = aptr->next;
	}
	else{
		a_prev->next = aptr->next;
	}
	for(i=head, temp=NULL; i!=NULL && bptr == NULL; i=i->next){
		if(i->data == b){
			bptr = i;
			b_prev = temp;
		}  
		temp = i;
	}
	if(b_prev == NULL){
		head = aptr;
		aptr->next = bptr;
	}
	else{
		b_prev->next = aptr;
		aptr->next = bptr;
	}
	return head;
}
Node* do_oper_rm(Node* head, int a){
	Node *i, *temp = NULL, *a_prev, *aptr=NULL;
	int flag = 0;
	for(i=head; flag==0; i=i->next){
		if(a == i->data){
			flag = 1;
			a_prev = temp;
			aptr = i;
		}
		temp = i;
	}
	if(a_prev == NULL){
		head = aptr->next;
		free(aptr);
	}
	else{
		a_prev->next = aptr->next;
		free(aptr);
	}
	return head;
}
int can_do_move(Node *head, int a, int b){
	Node *i;
	int flag = 0;
	for(i=head; i!=NULL; i=i->next){
		if(i->data == a){
			flag++;
		}
		if(i->data == b){
			flag++;
		}
	}
	return flag == 2;
}
int can_do_rm(Node *head, int a){
	Node *i;
	for(i=head; i!=NULL; i=i->next){
		if(i->data == a){
			return 1;
		}
	}
	return 0;
}
void show_list(Node *head){
	Node *i;
	for(i=head; i!= NULL; i=i->next){
		printf("%d ", i->data);
	}
	printf("\n");
	return ;
}
