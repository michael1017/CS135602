//HW8
//12279 - Binary Search Tree With Iterator (Preorder)
#include <iostream>
struct Node
{
    int value;
    Node *right;
    Node *left;

    Node(int v)
        :value(v)
        ,right(nullptr)
        ,left(nullptr) {}
    
    ~Node()
    {
        delete right;
        delete left;
    }
};

class Iterator
{
public:
    void *data;

    Iterator(Node *);
    Iterator(const Iterator &other);
    ~Iterator();
    int operator*() const;
    bool operator!=(const Iterator &) const;
    void operator++(int);
};


class BST
{
public:
    BST():m_root(nullptr){}
    ~BST(){delete m_root;}

    void push_back(int val)
    {
        Node **pos = &m_root;

        while( *pos )
        {
            if( (*pos)->value < val ) pos = &(*pos)->right;
            else pos = &(*pos)->left;
        }
        
        *pos = new Node(val);
    }
    
    Iterator begin()
    {
        Iterator it(m_root);
        return it;
    }

    Iterator end()
    {
        Iterator end(nullptr);
        return end;
    }

private:
    Node *m_root;
};

using namespace std;
//-----------------------------------------
#include<iostream>
#include<stack>

typedef struct store_{
    stack <Node*> s;
}store;

Iterator::Iterator(Node *input){
    data = new store;
    ((store*)data)->s.push(input);
}

Iterator::Iterator(const Iterator &input){
    ((store*)data)->s = ((store*)input.data)->s;
}

Iterator::~Iterator(){
    while(!((store*)data)->s.empty()) ((store*)data)->s.pop();
}

int Iterator::operator*() const{
    return ((store*)data)->s.top()->value;
}

bool Iterator::operator!=(const Iterator &input) const{
    return ((store*)data)->s.top() != ((store*)input.data)->s.top();
}

void Iterator::operator++(int){
    stack <Node*> &copy = ((store*)data)->s;
    Node *temp = copy.top();
    if(copy.empty() || copy.top() == nullptr) return ;
    copy.pop();
    if(copy.empty()) copy.push(nullptr);
    if(temp->right != nullptr) copy.push(temp->right);
    if(temp->left != nullptr) copy.push(temp->left);
    return ;
}
//-----------------------------------------
int main()
{

    int G, N, tmp;
    
    BST bst;
    
    cin>>N>>G;
    
    for(int i=0;i<N;++i)
    {
        cin>>tmp;
        bst.push_back(tmp);
    }

    auto it = bst.begin();
    auto it2 = bst.begin();
    auto end = bst.end();
    while( it != end )
    {
        if( it2 != end ) it2++;
        if( it2 != end ) it2++;
        cout << *it + G << endl;
        it++;
    }
    
    return 0;
}

