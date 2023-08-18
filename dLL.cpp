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

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlength(Node* &head)
{
    int count=0;
    Node* temp = head;
    while(temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void insertathead(Node* &tail,Node* &head, int d)
{
    //empty list
    if(head==NULL)
    {
        Node* temp= new Node(d);
        head= temp;
        tail = temp;
    }
    else{
    Node* temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertatTail(Node* &tail,Node* &head, int d)
{
    if(tail==NULL)
    {
      Node* temp = new Node(d); 
      tail=temp;
      head=temp;
    }
    else
    {
    Node* temp= new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void insertAtposition(Node* &tail, Node* &head, int position, int d)
{
    //insert at start
    if(position==1)
    {
        insertathead(tail,head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;

    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    // insert at last position
    if(temp->next==NULL)
    {
        insertatTail(tail,head,d);
        return; 
    }

    // creating a node for d
    Node* nodetoinsert= new  Node(d);

    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next= nodetoinsert;
    nodetoinsert->prev = temp; 
}

void deletenode(int position, Node* &head)
{
    // deleting first or start node(no prev thats why seperate case)
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev= NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        temp->next=NULL; // the node which have to be deleted should not be pointing to any m.location(only null)
        delete temp;
    }
    else
    {
        //deleting any middle or last node
        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while(cnt<position)  //<= also when 3delete 2.
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(int argc, char const *argv[])
{
    Node* node1= new Node(10);
    Node* head= node1;
    Node* tail=node1;

    print(head);
    //cout<< getlength(head) << endl;

    insertathead(tail,head,11);
    print(head);


    insertathead(tail,head,25);
    print(head);
    insertathead(tail,head,27);
    print(head);

    insertatTail(tail,head, 31);
    print(head);

    insertAtposition(tail,head,3,45);
    print(head);

    deletenode(4,head);
    print(head);


    return 0;
}












