// queue implementation using array
// simple approach implementation


#include<iostream>
using namespace std;

struct queue
{
    int size,cap;
    int *arr;

    queue(int c)
    {
        cap=c;
        size=0;
        arr= new int[cap];
    }
    void enqueue(int x)
    {
        if(isfull()) return;
        arr[size]=x;
        size++;
    }

    void dequeue(int x)
    {
        if(isempty()) return;
        for(int i=0;i<size-1;i++)
        arr[i]=arr[i+1];

        size--;
    }

    int getfront()
    {
        if(isempty())
        return -1;
        else
        return 0;
    }

    int getrear()
    {
       if(isempty())
       return -1;
       else
       return size-1;
    }

    bool isfull()
    {
       return (size==cap);
    }

    bool isempty()
    {
      return (size==0);
    }

    int size()
    {

    }
};


// efficient implementation(CIRCULAR ARRAY)


struct queue
{
    int *arr;
    int front,cap,size;
    queue(int c)
    {
        arr=new int[c];
        cap=c;
        front=0;
        size=0;
    }

    // isfull() and isempty are same...

    int getfront()
    {
        if(isempty())
        return -1;
        else
        return front;

    }
    int getrear()
    {
        if(isempty())
        return -1;
        else
        return (front+size-1)%cap; // something to learn only..(ratta)
                                   // rear is always this only front is maintained.
    }
    void enque(int x)
    {
        if(isfull()) return;
        int rear = getrear();
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++;
    }
    void deque(int x)
    {
        if(isempty()) return;
        front=(front+1)%cap;
        size--;
    }   

};
// time complexcity is O(1) for all operations.

// linked list implementation of queue

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x; next=NULL;
    }
};

struct queue
{
    Node *front,*rear; int size;
    queue()
    {
        front=NULL;rear=NULL;size=0;
    }

    void enque(int x)
    {
        Node *temp= new Node(x);
        if(front==NULL)   // corner case
        {
            front=rear=temp; return;
        }
        rear->next=temp;
        rear=temp;            // size++;
    }

    void deque()
    {
        if(front==NULL) return;
        Node *temp=front;
        front=front->next;
        if(front==NULL){rear=NULL;} // corner case
        delete(temp);
    }                           //size--;
};


// implementation of queue using stack

//1st solution
class MyQueue {
public:
stack<int>input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        
    }
    
    int pop() {
        if(input.empty())
        {
            return -1;
        }
        int val=input.top();
        input.pop();
        return val;
        
    }
    
    int peek() {
        if(input.empty())
        {
            return -1;
        }
        return input.top();  
    }
    
    bool empty() {
        return input.empty();
        
    }
};    // TAKE U FORWARD....

//2nd solution

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) { // push
    input.push(x);
    }

    int dequeue() {  //pop
        // when output is empty....
        while(!input.empty())
        {
            int el=input.top();
            output.push(el);
            input.pop();
        }
        int ans=output.top();
        output.pop();
        
        // when output is not empty
        while(!output.empty())
        {
        input.push(output.top());  // not understand
            output.pop();
        }
        return ans;
    }
};



