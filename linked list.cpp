// linked list --elements are not stored at contigeous location like arrays.
// each node of the lined list contains(store refrence to each other)
// the idea is to drop contigeous memory requirement  so that insertion and deletion can also happen at middle also.

// implementation
#include<iostream>
using namespace std; 

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    return 0;
}
// traversing a singly linked list in c++

#include<bits/stdc++.h> 
using namespace std;

void printlist(Node *head)
{
    Node *curr = head;
    while(curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr= curr->next; 
    }
}
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printlist(head);
    return 0;
}

// recursively ....
void rprint(Node* head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    rprint(head->next);
}

// love babar (true learning)...

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
   //new node create
   Node* temp =new Node(d);
   temp->next = head;
   head=temp; // new head is temp now(head is updated)
}

void print(Node* &head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        cout<< temp -> data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertattail(Node* &tail, int d) //
{
  //new node create
  Node* temp= new Node(d);
  tail ->next = temp;
  tail = tail ->next;
}

void insertatposition(Node* &head,Node* tail, int position, int d)
{   
    // insert at start
    if(position==1 )
    {
        insertathead(head,d);
        return;
    }
    Node* temp =head;
    int cnt=1;

    while(cnt< position-1)
    {
        temp=temp->next;
        cnt++;
    }
    // insert at last position 
    if(temp->next==NULL)
    {
        insertattail(tail,d);
        return;
    }

    // creating a node for d
    Node* nodetoinsert= new Node(d);

    nodetoinsert->next=temp->next;
    temp->next = nodetoinsert;
}


void deletenode(int position, Node* &head)
{
    // deleting first or start node(no prev thats why seperate case)
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        // memory free start node
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

        prev->next=curr->next;
        curr->next=NULL; // JUST BEFORE DELETE.like upper temp case
        delete curr;
    }
}



int main(int argc, char const *argv[])
{
    // created a new node
    Node* node1= new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    //head pointed to node1
    Node* head =node1;
    Node* tail =node1;
    print(head);

    //insertathead(head,12);
    insertattail(tail,12);

    print(head);

    insertattail(tail,15 );
    print(head);

    insertatposition(head,tail,3,22);
    print(head);

    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    deletenode(3,head);
    print(head);


    return 0;
}

// QUESTIONS...
// gfg

// linked list insertion
class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node* temp = new Node(x);
       temp->next=head;
       return temp;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
        if(head==NULL)
        {
            Node* temp= new Node(x);
            return temp;
        }
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new Node(x);
        return  head;

    }

    // SEARCHING..
    //1.iterative...
    class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        int pos=1;
        Node* curr=head;
        while(curr != NULL)
        {
            if(curr->data==key)
            return true;
            else
            curr=curr->next;
            pos++;
        }
        return false; 
    }
};

// recursively...
int search(Node* head,int x)
{
    if(head==NULL) return -1;
    if(head->next==x) return 1;

    else
    {
        int res=search(head->next,x);
        if(res==-1) return -1;
        else return (res+1); //+1 significance
    }
}
// bianry search is not possible in O(logn)time in case of ll. 

// middle of linked list (basic approach)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
        {
            return 0;
        }
        ListNode* curr;
        int count=0;
        for(curr=head;curr!=NULL;curr=curr->next)
        {
            count++;
        }
        curr=head;
        for(int i=0;i<count/2;i++)
        {
            curr=curr->next;
        }
        return curr;
    }
};

//2. slow and fast tortoise

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL and fast->next!=NULL) // fast reaches the last node or second last node
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};

// detect a cycle in linked list

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        return false;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next  && fast->next->next) // means while we have this condition
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }

       return false; 
    }
};

// detect starting of a cycle in linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(entry != slow)
                {
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }


        }
        return NULL;
        
    }
};

// REMOVE Nth NODE FROM THE END

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next=head;
        ListNode* slow=start;
        ListNode* fast=start;
        for(int i=1;i<=n;i++)
        {
            fast=fast->next;}
            while(fast->next!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        slow->next=slow->next->next;
        
        return start->next;
        
    }
};
//    we have to move fast (n times) so fast=start hence (start->next=head) that's why need of dummy node.  looks like for(int i=1;i<=n;i++)  
//    and 
//    we have to return start->next (especially for edge cases.)













