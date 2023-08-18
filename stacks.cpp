// implementation of stack using arrays
struct mystack
{
    int *arr;
    int cap;
    int top;
    mystack(int c)
    {
        cap=c;
        arr=new int[cap];
        top=-1;
    }
    void push(int x)
    {
        // if(top==cap-1){....}
        top++;
        arr[top]=x;
    }
    int pop(int x)
    {
        // if(top==-1){...}
        int res=arr[top];
        top--;
        return res;
    }
    int peek()
    {
        // if(top==-1){...}
        return arr[top];
    }
    int size()
    {
        return(top+1);
    }
    bool isempty()
    {
        return(top==-1);
    }
};

int main()
{
    mystack s(5);
}

//1. gfg
void MyStack :: push(int x)
{
    top++;
    arr[top]=x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1)
    {return -1;}
    
    int res=arr[top];
    top--;
    return res;
}

// if you are adding from an end then you have to pop from same end
// nature of stack ds.
// means you have to choose one end

// generally TC of all these operations are O(1).



// to create dynamically sized array..

struct mystack
{
    vector<int>v;
    void push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int res=v.back();
        v.pop_back();
        return res;
    }

    int size()
    {
        return v.size();
    }

    bool isempty()
    {
        return v.empty();
    }

    int peek()
    {
        return v.front();
    }
}


// implementation of stack using linked list

struct Node
{
    int data;
Node* next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }


struct mystack
{
    Node *head;
    int s;

    mystack()
    {
        head==NULL; s=0;
    }

    void push(int x)
    {
        Node* temp =new Node(x);
        temp->next=head;
        head=temp;
        s++;
    }

    int pop()
    {
        if(head==NULL)
        {                   // overflow condition
            return INT_Max; // specifies something wrong(for user to understand)
        }

        int res= head->data;
        Node* temp=head;
        head=head->next;
        delete(temp);
        s--;
        return res;

    }

    int size() {return s};

    bool isempty()
    {
        return{(head==NULL)};
    }

    int peek()
    {
        if(head==NULL)
       {return INT_MAX;}   // underflow condition(stack is empty)

        return head->data;

    }



};
      // these are  just placed wrong.
};



// check for balanced paranthesis in a string using stack


bool isbalanced(string str)
{
    stack<int>s;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='('|| str[i]=='{' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else
        {
            if(s.empty()==true)
            return false;

            else if(matching(s.top(),str[i])==false)
            return false;

            else
            s.pop();
        }
    }
    return(s.empty()==true);
}


bool matching(char a, char b)
{
    return((a=='(' && b==')'))||
           (a=='{' && b=='}') ||
           (a=='[' && b==']') ;

}


// infix to postfix............


#include<iostream>
#include<stack>
using namespace std;

int prec(char c)
{
    if(c=='^')
    {return 3;}
    else if(c=='*'|| c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
}
// function to convert an infix expression to postfix expression

string infixtopostfix(string s)
{
    stack<int>st;
    string res;

    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {                   // due to here 1 test case failed GFG
                st.pop();//write only this and check
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]); // if empty then push(like two sum p.)
                           //(check notes).
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string str="A*(B+C)/D";
    cout<<infixtopostfix(str)<<" ";
    return 0;
}


// problems on stacks(placement series)


//1. reverse a string using stack
//it is the property of stack that anything we gives it it will reverse it and give back

#include<iostream>
#include<stack>
using namespace std;


int main(int argc, char const *argv[])
{
    string str="kishan";

    stack<int>st;

    for(int i=0;i<str.length();i++)
    {
       char ch=str[i];
       st.push(ch);
    }

    string ans="";

    while(!st.empty())
    {
        char ch= st.top();
        ans.push_back(ch);

        st.pop();

    }

    cout<<"answer is:"<< ans<<endl;
    return 0;
}

// TC-->> O(N) and O(N).


//implementation of stack using queue(single queue(LEETCODE))

#include<bits/stdc++.h>

using namespace std;

class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      for (int i= 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}

//NOTE-->> andar sare function me to tumko q ke respective se hi return karana h to .
























