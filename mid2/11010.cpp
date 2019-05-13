#include <iostream>
#include <string>
//-------------------------------------------------
#include <iostream>
class ListNode
{
    friend class OWList; //make OWList a friend
    friend class TWList; //make TWList a friend

public:
    ListNode( const int &info ) //constructor
    : data( info ), nextPtr( NULL )
    {
    } //end ListNode constructor

private:
    int data; //data
    ListNode *nextPtr; // next node in list
}; //end class ListNode


class OWList
{
public:
    //default constructor
    OWList();
    //destructor
    ~OWList();
    //insert node at front of list
    void insertAtFront( const int &value );
    //remove node from front of list
    void removeFromFront();
    //is List empty?
    bool isEmpty() const;
    //display contents of List
    void print() const;

protected:
    ListNode *firstPtr; //pointer to first node
    ListNode *lastPtr;  //pointer to last node

}; // end class List

class TWList:public OWList
{
public:
    //default constructor
    TWList()
    :OWList()
    {
        /*It will still work correctly if you omit the constructor call of the base
          class in the above member initializer list. The compiler will invoke this
          default constructor of OWList implicitly.*/
    }
    //destructor
    ~TWList()
    {
        /*You don't need to delete the list again because the compiler
          will invoke the destructor of the base class OWList to do this.*/
    }
    //insert node at back of list
    void insertAtBack( const int &value );
    //delete node from back of list
    void removeFromBack();

};
//-------------------------------------------------
#include<iostream>
using namespace std;
OWList::OWList(){
    firstPtr = lastPtr = NULL;
}
//destructor
OWList::~OWList(){
    ListNode *i = firstPtr;
    ListNode *temp;
    while(i != NULL){
        temp = i;
        i = i->nextPtr;
        delete temp;
    }
}
//insert node at front of list
void OWList::insertAtFront( const int &value ){
    if(firstPtr == NULL){
        ListNode *dot = new ListNode(value);
        firstPtr = lastPtr = dot;
    }
    else{
        ListNode *dot = new ListNode(value);
        dot->nextPtr = this->firstPtr;
        firstPtr = dot;
    }
    return ;
}
//remove node from front of list
void OWList::removeFromFront(){
    if(firstPtr == lastPtr){
        delete firstPtr;
        firstPtr = lastPtr = NULL;
    }
    else if(firstPtr != NULL){
        ListNode *temp;
        temp = firstPtr->nextPtr;
        delete firstPtr;
        firstPtr = temp;
    }
    return ;
}
//is List empty?
bool OWList::isEmpty() const{
    if(firstPtr == NULL && lastPtr == NULL){
        return true;
    }
    return false;
}
//display contents of List
void OWList::print() const{
    for(ListNode *i=firstPtr; i!=lastPtr; i=i->nextPtr){
        cout<<i->data<<" ";
    }
    cout<<lastPtr->data;
}
void TWList::insertAtBack( const int &value ){
    if(lastPtr == NULL){
        ListNode *dot = new ListNode(value);
        firstPtr = lastPtr = dot;
    }
    else{
        ListNode *dot = new ListNode(value);
        this->lastPtr->nextPtr = dot;
        this->lastPtr = dot;
    }
    return ;
}
//delete node from back of list
void TWList::removeFromBack(){
    if(lastPtr == firstPtr){
        delete lastPtr;
        lastPtr = firstPtr = NULL;
    }
    else if(lastPtr != NULL){
        ListNode *i;
        for(i=firstPtr; i->nextPtr!=lastPtr; i=i->nextPtr);
        delete lastPtr;
        lastPtr = i;
        lastPtr->nextPtr = NULL;
    }
    return ;
}
//-------------------------------------------------
using namespace std;
int main()
{
    TWList integerList;
    int command;
    int value; // store node value

    while (cin >> command)
    {
        switch(command)
        {
        case 1: // insert at beginning
            cin >> value;
            integerList.insertAtFront(value);
            break;
        case 2: // insert at end
            cin >> value;
            integerList.insertAtBack(value);
            break;
        case 3: // remove from beginning
            integerList.removeFromFront();
            break;
        case 4: // remove from end
            integerList.removeFromBack();
            break;
        }
    }
    integerList.print();
    cout<<endl;
}
