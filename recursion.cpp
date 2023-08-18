//solution of sub problem to solve bigger problem......
// decimal to binary equivalent......
void fn(int n)
{
   if(n==0)
   return;
   
   fn(n/2);
   cout<<n%2;
}
 // sum of natural numbers using recursion.......

 int fun(int n)
 {
    if(n==0)
    return 0;
    else
     return n+fun(n-1);

 }

// fibonacci.......

int fun1(int n)
{
    if(n<=1)
    return n;
    else
    return fun1(n-2)+fun1(n-1);
}
// palindrome check....
#include<iostream>
#include<string.h>
using namespace std;

bool ispalindrome(string &str, int start, int end)
{
   if(start>=end)  // it means reached midddle means it is palindrome.
   return true;
   else
   return (str[start]==str[end])&&  // for palindrome start ==end
   ispalindrome(str,start+1,end-1);  
}

// recursive function to find sum of digits of number..
#include<iostream>
using namespace std;

int fun(int n)
{
   if(n<10)
   return n;
   else
   return fun(n/10)+(n%10);
}
int main(int argc, char const *argv[])
{
   int n;
   cout<<"n";
   cin>>n;
   int res=fun(n);
   cout<<res<<endl;
   return 0;
}

// recursive function to print subset of strings....

void printsub(string str,string curr="",int index=0)
{
  if(index==str.length())
  cout<<curr<<" "; return;  // need ot print leaves of the recursion tree{when reached the base case}

  printsub(str,curr,index+1);// do not append character....that's why only curr
  printsub(str,curr+str[index],index+1);//curr+str[index]means included the character(append character)
}

// we begins with a empty string and we have two choices each time (we___append Character or not append Character)
// one by one consider 2 choices for every character..._______________|




// TOWER OF HANOI.....


// RULES...
//1. only one disc moves at a time.
//2. no larger disc above smaller.
//3. only the top disc of the tower can be moved.

void TOH(int n, char A, char B, char C)
{
   if(n==1)
   {
      cout<<"move 1 from"<<A<<"to"<<C<<endl;
      return;
   }
   TOH(n-1,A,C,B);
   cout<<"move"<<n<<"from"<<A<<"to"<<C<<endl;
   TOH(n-1,B,A,C);
}


// number of movements for a given n....
// T(1)=1;
// T(n)=2T(n-1)+1
// 1+2+4.....2^(n-1)

// =========2^(n-1)...movements for a given n.
























