#include <iostream>
using namespace std;
class Node
{
   friend class Josephus;
   public:
        Node():next( NULL ){
        }
      	Node( const int &info ) //constructor
   	 :number( info ), next( NULL )
   	 {
   	 } //end ListNode constructor
   private:
      	Node *next;
        int number;
};//end class Node

class Josephus
{
    public:
         Josephus();
         ~Josephus();
         Josephus(const int &);
         int kill() ; // return the survival's position

    private:
        void generatecircularlinkedList(const int &); // generate circular linked-list
        void generateFib(const int &); // generate a Fibonacci sequence table
        int sequence[50]; // store Fibonacci number
        int noOfPeople;
        Node *head;
};
//------------------------------------------------------------------
Josephus::Josephus(){
    noOfPeople = 0;
    head = NULL;
    generateFib(48);
}
Josephus::~Josephus(){
    if(head != NULL){
        Node *temp, *todelete = head;
        for(int i=1; i<=noOfPeople; i++){
            temp = todelete->next;
            delete todelete;
            todelete = temp;
        }
    }
}
Josephus::Josephus(const int &total_people){
    noOfPeople = total_people;
    generatecircularlinkedList(total_people);
    generateFib(total_people);
}
int Josephus::kill(){
    int tokill = noOfPeople-1;
    int godown;
    Node *startkill = head;
    Node *prev = head;
    for(int i=1; i<noOfPeople; i++){
        prev = prev->next;
    }
    for(int i=1; i<=tokill; i++){
        godown = sequence[i]%noOfPeople;
        if(godown == 0){
            godown += noOfPeople;
        }
        
        for(int j=1; j<godown; j++){
            prev = prev->next;
        }
    
        startkill = prev->next;
        prev->next = startkill->next;
        //cout<<startkill->number<<" ";
        delete startkill;
        head = prev->next;
        startkill = head;
        noOfPeople--;
    }
    //cout<<"\n";
    return head->number;
} // return the survival's position
void Josephus::generatecircularlinkedList(const int &list_len){
    Node *temp = NULL;
    for(int i=1; i<=list_len; i++){
        if(i == 1){
            head = new Node(i);
            temp = head;
        }
        else{
            temp->next = new Node(i);
            temp = temp->next;
        }
        //cout<<temp->number<<" ";
    }
    //cout<<"\n";
    noOfPeople = list_len;
    temp->next = head;
    return ;
}// generate circular linked-list
void Josephus::generateFib(const int &sequence_len){
    sequence[0] = 0;
    sequence[1] = 1;
    for(int i=2; i<=sequence_len; i++){
        sequence[i] = sequence[i-1] + sequence[i-2];
        //cout<<sequence[i]<<" ";
    }
    //cout<<"\n";
    return ;
} // generate a Fibonacci sequence table
//------------------------------------------------------------------
using namespace std;
int main(){
	int numofpeople;

	while(cin>>numofpeople){
		Josephus Jose(numofpeople);
		int survival = Jose.kill();
		cout<<survival<<endl;
    }
}
