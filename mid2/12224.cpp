#include <iostream>
#include <string.h>

using namespace std;
using Node = struct _node {
    int data;
    struct _node* next;
    struct _node* prev;
};
int mid, cnt, now_place;
Node *mid_node;
void maintain_mid(Node* &head){
    int i;
    Node *temp;
    if(cnt > 3){
        if(mid != cnt/2){
            if(mid > cnt/2){
                for(i=mid, temp=mid_node; i>cnt/2; i--){
                    temp = temp->prev;
                }
            }   
            else if(mid < cnt/2){
                for(i=mid, temp=mid_node; i<cnt/2; i++){
                    temp = temp->next;
                }
            }
            mid_node = temp;
            mid = cnt/2;
        }
    }
    else{
        mid = 1;
        mid_node = head;
    }
    return ;
}
void InsertHead(Node* &head, Node* &tail){
    cnt++;
    mid++;
    int data;
    cin>>data;
    if (head == nullptr) {
        head = new Node;
        head->data = data;
        head->next = head->prev = nullptr;
        tail = head;
    } else {
        if(head == tail){
            head = new Node;
            head->data = data;
            head->next = tail;
            head->prev = nullptr;
            tail->prev = head;
        }
        else{
            Node *dot = new Node;
            dot->data = data;
            dot->next = head;
            dot->prev = nullptr;
            head->prev = dot;
            head = dot;
        }
    }
    maintain_mid(head);
    return ;
}

void RemoveHead(Node* &head, Node* &tail){
    if(cnt != 0){
        cnt--;
        mid--;
    }
    Node* temp;
    if (head == nullptr){
        cout << endl;
    } else {
        cout<<head->data<<endl;
        Node *temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        
        delete temp;
    }
    maintain_mid(head);
    return ;
}

void InsertTail(Node* &head, Node* &tail){
    cnt++;
    int data;
    cin>>data;
    if (tail == nullptr) {
        head = new Node;
        tail = head;
        head->data = data;
        head->next = head->prev = nullptr;
    } else {
        if(head == tail){
            tail = new Node;
            tail->data = data;
            tail->next = nullptr;
            tail->prev = head;
            head->next = tail;
        }
        else{
            Node *dot = new Node;
            dot->data = data;
            dot->next = nullptr;
            dot->prev = tail;
            tail->next = dot;
            tail = dot;
        }
    }
    maintain_mid(head);
    return ;
}

void RemoveTail(Node* &head, Node* &tail){
    if(cnt != 0){
        cnt--;
    }
    Node* temp;
    if (tail == nullptr){
        cout << endl;
    } else {
        cout << tail->data <<endl;
        temp = tail;
        tail = tail->prev;
        if(tail != nullptr){
            tail->next = nullptr;
        }
        else{
            head = nullptr;
        }
        delete temp;
    }
    maintain_mid(head);
    return ;
}

void Swap(Node* &head, Node* &tail){
    Node* temp;
    if(cnt>1){
        tail->next = head;
        head->prev = tail;
        head = mid_node->next;
        head->prev = nullptr;
        temp = tail;
        tail = mid_node;
        tail->next = nullptr;
        if(cnt%2 == 0){
            mid_node = temp;
        }
        else{
            mid_node = temp->prev;
        }
    }
    return ;
}
void Show(Node *head){
    Node *i;
    for(i=head; i!= nullptr; i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
    cout<<"cnt: "<<cnt<<endl;
    cout<<"mid: "<<mid<<endl;
    if(mid_node != nullptr)
        cout<<"mid_node: "<<mid_node->data<<endl;
    return ;
}

int main(){
    Node *head=nullptr, *tail=nullptr;
    char cmd[4];
    int data;
    while(cin >> cmd){
        if(strcmp(cmd, "IH")==0){ // insert an integer to the head
            InsertHead(head, tail);
        } else if (strcmp(cmd, "IT")==0){ // insert an integer to the end
            InsertTail(head, tail);
        } else if (strcmp(cmd,"RH")==0){   // print and remove a node from head
            RemoveHead(head, tail);
        } else if (strcmp(cmd, "RT") == 0) {// print and remove a node from tail
            RemoveTail(head, tail);
        } else if (strcmp(cmd, "S")==0){
            Swap(head, tail);
        }
        //Show(head);
    }
}