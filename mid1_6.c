#include<stdlib.h>
#include<stdio.h>

typedef struct _Node{
	long data;  //the value of coefficient
	int power; //the value of power
	struct _Node *next;
	struct _Node *prev;
}Node;
void printNode(Node* head);         //the function which will print the output
Node* create();                     //create polynomial linked list
void destroy(Node *node);           //destroy polynomial linked list
Node* multiple(Node* p1, Node* p2); //input two polynomial linked list and return the result
int cmp(const void *, const void *);
int main(void){
	Node *p1=create(); //polynomial linked list1
	Node *p2=create(); //polynomial linked list2
	Node *mul=multiple(p1,p2);
	printNode(mul);
	destroy(mul);
	destroy(p2);
	destroy(p1);
	return 0;
}
void printNode(Node* head){
    int i;
    Node *temp;
    temp = head;
    for(i=0; i<600; i++){
        if(temp[i].data == 0){
            continue;
        }
        else {
            printf(" %ld %d", temp[i].data, temp[i].power);
        }
    }
}
Node* create(void){
    Node *list = (Node* )malloc(sizeof(Node) * 600);
    long data;
    int i, power;

    for(i=0; i<600; i++){
        scanf("%ld %d", &data, &power);
        list[i].data = data;
        list[i].power = power;
        if(power == 0){
            break;
        }
    }
    return list;
}
void destroy(Node *node){
    int i;
    free(node);
    return ;
}
Node* multiple(Node* p1, Node* p2){
    Node *list = (Node* )malloc(sizeof(Node) * 360000);
    Node *clean_list = (Node* )malloc(sizeof(Node) * 600);
    int i, j;
    long sum;
    int now_power;
    for(i=0; i<600; i++){
        for(j=0; j<600; j++){
            list[i*600 + j].data = p1[i].data * p2[j].data;
            list[i*600 + j].power = p1[i].power + p2[j].power;
        }
    }
    qsort(list, 360000, sizeof(Node), cmp);
    now_power = list[0].power;
    sum = 0;
    for(i=0, j=0; i<360000; i++){
    //printf("%d %d %d %d\n", now_power, sum, j, i);
        if(i == 359999){
            clean_list[j].power = now_power;
            clean_list[j].data = sum;

        }
        else if(now_power == list[i].power){
            sum += list[i].data;

        }
        else{
            clean_list[j].power = now_power;
            clean_list[j].data = sum;
            now_power = list[i].power;
            sum = list[i].data;
            j++;
        }
    }
    destroy(list);
    return clean_list;
}
int cmp(const void *A, const void *B){
    const Node *a = (const Node *)A;
    const Node *b = (const Node *)B;
    if(a->power > b->power){
        return -1;
    }
    else if(a->power == b->power){
        return 0;
    }
    else {
        return 1;
    }
}