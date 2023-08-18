#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this ->data = data;
        this ->next = NULL;
    } 

    // destructor
    ~Node()
    {
        int value= this->data;
        //memory free
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl; 
    }
};

void insertathead(Node* &head, int d)
{
    Node* temp= new Node(d);
    temp->next=head;
    head=temp;
}
void print(Node* &head, int d)
{
    Node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insertattail(Node* &tail, int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;

}

void insertatposition(Node* &tail, Node* &head, int pos, int d)
{

    if(pos==1)
    {
        insertathead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt< pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    // create new node
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

    while(temp->next==NULL)
    {
        insertattail(tail,d);
        return;
    }


}

void deletenode(Node* &head,int pos)
{
    if(pos==1)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
// doubly linked list

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"memory is free for node with data"<< value<<endl;
    }

};

 
void print(Node* &head, int d)
{
    Node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insertathead(Node*&head, int d)
{
    if(head->next=NULL)
    {
        Node* temp=new Node(d);
        head=temp;

    }
    else{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertattail(Node*&tail, int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

// insertion at middle

nodetoinsert->next=temp->next;
temp->next->prev=nodetoinsert;
nodetoinsert->prev=temp;
temp->next=nodetoinsert;   //order matters

//questions.......

//search an element in a linked list
























