#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
    char data;
    struct node *left;
    struct node *right;
}Node;

Node* build_tree(void);
int calculate(int , int , int , int , Node* );


int main(void){
    int i, j;
    int A, B, C, D;
    Node *root = build_tree();
    for(i=0; i<16; i++){
        j = i;
        D = j%2; j/=2;
        C = j%2; j/=2;
        B = j%2; j/=2;
        A = j%2; 
        printf("%d %d %d %d %d\n", A, B, C, D, calculate(A, B, C, D, root));
    }
    return 0;

}
Node* build_tree(void){
    char c;
    Node *dot = (Node* )malloc(sizeof(Node));
    c = getchar();
    if(isalpha(c)){
        dot->data = c;
        dot->right = dot->left = NULL;
    }
    else{
        dot->data = c;
        dot->left = build_tree();
        dot->right = build_tree(); 
    }
    return dot;
}
int calculate(int A, int B, int C, int D, Node* root){
    if(isalpha(root->data)){
        if(root->data == 'A'){
            return A;
        }
        else if(root->data == 'B'){
            return B;
        }
        else if(root->data == 'C'){
            return C;
        }
        else {
            return D;
        }
    }
    else {
        if(root->data == '|'){
            return calculate(A, B, C, D, root->left) | calculate(A, B, C, D, root->right);
        }
        else {
            return calculate(A, B, C, D, root->left) & calculate(A, B, C, D, root->right);
        }
    }
}