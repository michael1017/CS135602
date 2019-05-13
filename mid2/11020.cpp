#include<iostream>
#include<string>
#include"function.h"
using namespace std;
Array_BST::Array_BST(){
    for(int i=0; i<1025; i++){
        array[i] = 0;
    }
    Height = 0;
}
 void Array_BST::insert(const int &data) {
    int i,j, depth = 1;
    if(array[1] == 0){
        array[1] = data;
        Height = 1;
        return ;
    }
    else{
        for(i=1; ;){
            depth++;
            if(array[i] == data){
                break;
            }
            else if(array[i] < data){
                i=i*2 +1;
                if(array[i] == 0){
                    array[i] = data;
                    break;
                }
            }
            else{
                i=i*2;
                if(array[i] == 0){
                    array[i] = data;
                    break;
                }
            }
        }
        if(depth > Height){
            Height = depth;
        }
    }
    
    return ;
}
 bool Array_BST::search(const int &data) const {
    int i;
    for(i=1; ;){
        if(array[i] == data){
            return true;
        }
        else if(array[i] < data){
            i=i*2 +1;
            if(array[i] == 0){
                return false;
            }
        }
        else{
            i=i*2;
            if(array[i] == 0){
                return false;
            }
        }
    }
}
List_BST::List_BST(){
    root = nullptr;
    Height = 0;
}
 void List_BST::insert(const int &data) {
    //cout<<"here";
    int depth = 1;
    if(this->root == nullptr){
        this->root = createLeaf(data);
        Height = 1;
    }
    else{
        for(ListNode *i=this->root;;){
            depth++;
            if(i->key == data){
                break;
            }
            else if(i->key < data){
                if(i->right == nullptr){
                    i->right = createLeaf(data);
                    break;
                }
                else{
                    i=i->right;
                }
                
            }
            else{
                if(i->left == nullptr){
                    i->left = createLeaf(data);
                    break;
                }
                else{
                    i=i->left;
                }
            }
        }
        if(depth > Height){
            Height = depth;
        }
    }
    return ;
}
 bool List_BST::search(const int &data) const {
    for(ListNode *i=this->root;;){
        if(i->key == data){
            return true;
        }
        else if(i->key < data){
            if(i->right == nullptr){
                return false;
            }
            else{
                i=i->right;
            }
            
        }
        else{
            if(i->left == nullptr){
                return false;
            }
            else{
                i=i->left;
            }
        }
    }

}
ListNode* List_BST::createLeaf(int key) const{
    ListNode *node = new ListNode(key);
    node->left = node->right = nullptr;
    return node;
} //new a ListNode and return its address
/* clean a tree.*/
void List_BST::deleteTree(ListNode *root){
    if(root == nullptr){
        return ;
    }
    else{
        deleteTree(root->right);
        deleteTree(root->left);
        delete root;
    }
}