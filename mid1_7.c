#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end);
void caculateLeafNodesSum(Node* root);
void freeTree(Node *root);
int sum(Node* root);
int main(void){

    int i,n;
    int *inorder,*preorder;
    scanf("%d",&n); // n : the size of binary tree
    /*------------Parse the input----------------*/
    inorder = (int *) malloc(n * sizeof(int));
    preorder = (int *) malloc(n * sizeof(int));
    for(i=0; i<n; i++) scanf("%d", &inorder[i]);
    for(i=0; i<n; i++) scanf("%d", &preorder[i]);
    /*------------Build the binary tree----------*/
    Node *root = buildTree(inorder, preorder,0,n-1);
    /*------------Print out the tree ------------*/
    caculateLeafNodesSum(root);
    freeTree(root);
    free(inorder);
    free(preorder);
    return 0;
}
Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
    if(inorder_start > inorder_end){
        return NULL;
    }
    else{
        int i, head_num = preorder[inorder_start];
        Node *head = (Node* )malloc(sizeof(Node));
        for(i=inorder_start; i<=inorder_end; i++){
            if(inorder[i] == head_num){
                break;
            }
        }
        head->data = head_num;
        head->left = buildTree(inorder, preorder+1, inorder_start, i-1);
        head->right = buildTree(inorder+1+i, preorder+1+i, 0, inorder_end-i-1);
        return head;
    }
}

void caculateLeafNodesSum(Node* root){
    printf("%d\n", sum(root));
}
int sum(Node* root){
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    else{
        int ans = 0;
        if(root->left != NULL){
            ans += sum(root->left);
        }
        if(root->right != NULL){
            ans += sum(root->right);
        }
        return ans;
    }
}
void freeTree(Node *root)
{
    if(root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}