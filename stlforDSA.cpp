#include<bits/stdc++.h>
using namespace std;

// pairs....

void explainpair()
{
    pair<int,int>p={3,4};
    cout<<p.first<<" "<<p.second;
    
    pair<int, pair<int,int>>p={1,{3,4}};
    cout<<p.first<<" "<<p.second.second<<" "<<p.second.first;

    pair<int,int>arr[]={{1,2},{2,5},{5,1}};  // {1,2} is 0th index and so on...
    cout<<arr[1].second;

}


// vectors-- dynamic size containers.......

void vectorexplained()
{
    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);  // increases vector size and add the element at the end. {1,2}.

    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int>v(5,100); // creates 5 instances with value of 100 each.

    vector<int>v(5);  // same but garbage value

    vector<int>v1(5,20);
    vector<int>v2(v1);  // copying of vector v1 in v2.

}


// declaring,itetrating and printing a vector.

#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int>::iterator it = v.begin();
it++;
cout<<*(it)<<" ";

it =it+2;
cout<< *(it)<< " ";

vector<int>::iterator it = v.end();  //points towards after the last location of element.
vector<int>::iterator it = v.read();
vector<int>::iterator it = v.rbegin();

cout<<v[0]<<" "<<v.at(0);
cout<< v.back()<<" ";  // last element ex 30 --{10,20,30}.


for(vector<int>::iterator it = v.begin();it !=v.end();it++)
{
    cout<<*(it)<<" ";
}

for(auto it = v.begin();it!= v.end();it++)  // automatically asssigns the data types itself..
{
    cout<<*(it)<<" ";
}

for(auto it : v)
{
    cout<<it<<" ";
}


v.erase(v.begin()+1); // {10,20,30}-- 20 will be earased
//{10,20,12,23,35}
v.erase(v.begin()+2,v.begin()+4); //{10,20,35} will remain..[start,end)

// insert function
vector<int>v(2,100); // {100,100}
v.insert(v.begin(),300); //{300,100,100}
v.insert(v.begin()+1,2,10); //{300,10,10,100,100}  ..(place,no of element,element);

vector<int>copy(2,50); // {50,50}
v.insert(v.begin(),copy.begin(),copy.end()); // {50,50,300,10,10,100,100 }

//{10,20}
cout<<v.size(); //2
// {10,20}
v.pop_back();  // {10};

//v1 -->{10,20}
// v2-->{30,40}
vector<int>v1,v2;
v1.swap(v2); // v1={30,40} and v2={10,20}

v.clear(); // erases the entire vector.
cout<< v.empty();

return 0;
}


// list

void explained()
{
    list<int>ls;
    ls.push_back(2); //{2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); //{5,2,4}

    ls.emplace_front();//{2,4}
}


// rest function same as vector
// begin,end,rbegin,rend,clear,insert,size and swap.

// insert function in a vector is very costly (time complexicity)..so ls(push and emplace front)is preferred.


//deque

void explained()
{
    deque<int>dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4);  //{4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back(); // {3,4,1}
    dq.pop_front() // {4,1}

    dq.back();
    dq.front();
}

// rest is same as vector and list.


// STACK (LAST IN FIRST OUT)
// three important functions 1.push,2.pop,3.top

void expainstack()
{
    stack<int>st;
    st.push(1); // {1}
    st.push(2); // {2,1}
    st.push(3); // {3,2,1}
    st.push(3); // {3,3,2,1}
    st.push(5); // {5,3,3,2,1}

    cout<< st.top(); // 3

    cout<< st.size(); // 4

    cout<< st.empty();  // false

    stack<int>st1, st2;
    st1.swap(st2);
}
// ALL THE OPERATIONS ARE HAPPENING IN CONSTANT ITME


// queue (FIRST IN FIRST OUT)
// operations are happening in constant time

void explainqueue()
{
    queue<int>q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5; 
    cout << q.back(); // prints 9

    // Q is {1,2,9}
    cout<< q.front(); // prints 1
    q.pop(); // {2,9}

    cout << q.front(); // prints 2

    // size swap empty same as stack
}



// priority queue (lexographically large value comes first)


void explainpqueue()
{
    priority_queue<int>pq;

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout<< pq.top(); // prints 10

    pq.pop(); // {8,5,2}
    cout<< pq.top(); // prints 8

    //size swap empty function same as others

    // minimum heap
    priority_queue<int, vector<int>, greater<int>>pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top(); // prints 2
    
}


// set (sorted arrangement and unique)

void explainset()
{
    set<int>st;
    st.insert(1);  // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1,2}
    st.insert(4); // {1,2,4}
    st.insert(3); // {1,2,3,4}

    // funcitionality of insert in vector can be used also increase efficiency.
    // vector functions like swap begin....etc can also be used.

//   {1,2,3,4,5}
    auto it = st.find(3);  // returns an iterator to 3.
    auto it = st.find(6);  // st.end()

    // {1,4,5}
    st.erase(5); // erases 5 // takes logarithmic time and maintains sorted order

    int cnt = st.count(1); // if present returns 1 or else 0;

    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); // left-- {1,4,5} [first,last)


 // watch lower bound and upper bound video___take U forward
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

}


// multiset (sorted fashion and stores multiple occurences)

void explainmultiset()
{
    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1); // all 1's are erased.

    int cnt = ms.count(1);

    // only a single one erased
    ms.erase(ms.find(1));  // findinf first occurance of 1

    ms.erase(ms.find(1), ms.find(1)+2);  // erase(st,end(right a t end..)) // erases iterator.
                                         // find 1 go till 2 ..erase ...left--{1}.

    // rest all functions are same as set

}

// Uset

void expainUset()
{
    unordered set<int> st;
    // not stores in sorted order. // UNIQUE (stores only)
    // lower bound and upper bound functions not works
    // it has a better complexity than set in most cases,
    // except some when collison happens

    // rest all functions are as same as set

}

 // MAP

 void explainmap()
 {
    // consists of keys and values (ex-key=1,2,3(and can be of any data types), value= raj)// roll no, name.
    // map stores unique keys in sorted order.

    map<int,int>mpp;
    map<int, pair<int,int>>mpp;

    map<pair<int,int>,int>mpp;

    mpp[1] = 2;  // key =1 and value = 2.                                      {1,2}
    mpp.emplace({3,1});  // key = 3 go and stores value = 1.                   {2,4}  -- STORES IN THIS FASHION.
    mpp.insert({2,4});      //                                                 {3,1}

    mpp[{2,3}] = 10;  // key = {2,3} and the corresponding value is 10.

    for(auto x : mpp)  // for iterating
    {
        cout<< x.first << " " << x.second <<endl;  // this means iterarting and printing keys and corr.values.
    }

    cout << mpp[1];  // it gives value 2.
    cout << mpp[5]; // gives 0 or null.


    auto it = mpp.find(3);
    cout << *(it).second;   // prints 1 of {3,1}.

    auto it = mpp.find(5);  // not present so points towards mpp.end() {after the map}.

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);  // see video

    // erase,size,swap,empty are same as above.

 }

 // OTHER PART

 void explainMultimap()
 {
    // everything same as map but it can stores multiple keys.
    // only mpp[key] is not used here

    // can stores duplicate keys but in sorted order.
 }

void explainUnorderedMap()
{
    // everything is similar but not stores in order(UNSORTED).
}


// map works in logerethmic of time
// and unordered in (0)1 constant time ...(a;most all the cases.)// due to hahsing




// ALGORITHMS

bool comp(pair<int,int>p1, pair<int,int>p2)
{
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // they are same

    if(p1.first > p2.first) return true;
    return false;
}

void explainextra()
{
    sort(a, a+n);
    sort(v.begin(), v.end());

    sort(a+2, a+4);

    sort(a, a+n, greater<int>);  // sorted in ascending order

    pair<int,int>a[] = {{1,2}, {2,1}, {4,1}};

    // sort it ac to second element
    // if second element is same, then sort
    // if ac to first element but in descending

    sort(a, a+n, comp);

    // {4,1}, {2,1}, {1,2};

    int num = 7;
    int cnt = __builtin_popcount();

    long long num = 165786578687;
    int cnt = __builtin_popcountll();

    string s = "123";
    sort(s.begin(), s.end());

    do{
        cout<< s << endl;
    } while(next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a,a+n);
}

int main()
{
    return 0;
}















