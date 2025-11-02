#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print(){
    cout << "Gauri";
}
int sum(int a, int b){
    return a+b;
}

void explainPair(){
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> q ={1, {3, 4}};
    cout << q.first << " "<< q.second.second << " " << q.second.first<< endl;

    pair<int, int> arr[]= {{1,2}, {3,4}, {5,6}};
    cout << arr[1].second << endl;
}

void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>>vec;
    v.push_back({1, 2});
    v.emplace_back(1, 2);

    vector<int>v(5, 100);

    vector<int>v(5);//size of vector is 5 and value is garbage

    vector<int> v1(5, 20);//size of vector is 5 and value is 20 {20,20, 20, 20, 20}
    vector<int> v2(v1);//copy v1 to v2

    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it)<< " ";

    it=it+2;
    cout<< *(it)<< " ";

    vector<int>::iterator it = v.end();
    vector<int>::iterator it = v.rend();//never use
    vector<int>::iterator it = v.rbegin();//never use

    cout << v[0]<< " " << v.at(0);//not use more for standard practice
    cout << v.back() << " ";
    
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout <<*(it) << " ";
    }

    for(auto it = v.begin(); it!=v.end();it++){
        cout << *(it)<< " ";
    }
    
    for(auto it : v){
        cout << it << "  ";
    }

    //Delete function

    //{10,20,12,23}
    v.erase(v.begin()+1);
    
    //{10, 20, 12, 23, 35}
    v.erase(v.begin()+2, v.begin()+4);//{10, 20, 35} (start, end)

    //insert Function

    vector<int> v(2,100);//{100, 100}
    v.insert(v.begin(), 300);//{300, 100, 100}
    v.insert(v.begin()+1, 2, 10);//{300, 10, 10, 100, 100}

    vector<int> copy(2, 50);//{50, 50}
    v.insert(v.begin(), copy.begin(), copy.end());//{50, 50, 300, 10, 10, 100, 100}

    //{10, 20}
    cout << v.size(); //2
    //{10, 20}
    v.pop_back();//{10}

    //v1 ->{10, 20}
    //v2 ->{30, 40}
    v1.swap(v2); //v1 -> {30, 40} and v2 ->{10, 20}

    v.clear();//delete all the elements inside the vector
    cout << v.empty();//1 if vector is empty
}

void explainList(){
    list<int>ls;

    ls.push_back(2);//{2}
    ls.emplace_back(4);//{2,4}

    ls.push_front(5);  //{5, 2, 4}

    ls.emplace_front();//{2,4}

    //rest functions are same as vector
    //begin, end, rbegin, rend, size, clear, insert, swap
    
}

void explainDeque(){
    deque<int>dq;
    dq.push_back(1);//{1}
    dq.emplace_back(2); //{1,2}
    dq.push_front(4);//{4, 1, 2}
    dq.emplace_front(3);//{3, 4, 1, 2}
    
    dq.poop_back();//{3, 4, 1}
    dq.pop_fron();//{4,1}

    dq.back();
    dq.front();

    //rest functions same as vector
    //begin, end, ebegin, rend, clear, insert, size, swap

}

void esplainStack(){
    //LIFO
    stack<int>st;
    st.push(1);//{1}
    st.push(2);//{2,1}
    st.push(3);//{3,2,1}
    st.push(4);//{4,3,2,1}
    st.push(5);//{5,4,3,2,1}
    st.emplace(6);//{6,5,4,3,2,1}

    cout << st.top();// prints 6 "** st[2] is invalid **"

    st.pop(); //{5,4,3,2,1}

    cout<< st.top(); //5
    cout << st.size();//5
    cout << st.empty();//false

    stack<int>st1, st2;
    st1.swap(st2);

}

void explainQueue(){
    //Max heap
    //FIFO
    queue<int>q;
    q.push(1);//{1}
    q.push(2);//{1,2}
    q.emplace(4);//{1,2,4}

    q.back()+=5;
    cout << q.back();// print 9

    //Q is {1,2,9}
    cout << q.front();//print 1

    q.pop();//{2,9}

    cout << q.front();//prints 2

    //size swap empty same as stack

}

void explainPQ(){
    //min heap
    //store like tree
    priority_queue<int>pq;

pq.push(5); //{5}
pq.push(2);//{5,2}
pq.push(8);//{8,5,2}
pq.emplace(10);//{10,8,5,2}

cout << pq.top(); //prints 10

pq.pop(); // {8,5,2}

cout << pq.top(); //prints 8

//size, swap, empty functions same as others

//Minimum Heap
priority_queue<int, vector<int>, greater<int>>pq;
pq.push(5);//{5}
pq.push(2); //{2,5}
pq.push(8);//{2,5,8}
pq.emplace(10);//{2,5,8,10}

cout << pq.top();// prints 2
}

void explainSet()
{
//maintain internally in the form of tree
//unique and sorted

    set<int>st;
    st.insert(1);//{1}
    st.emplace(2);//{1,2}
    st.insert(2);//{1,2}
    st.insert(4);//{1,2,4}
    st.insert(3);//{1,2,3,4}

    //Functionality of insert in vector
    //can be used alse, that only increases
    //efficiency

    //begin, end, rbegin,, rend, size, clear, empty, swap are same as those of above

    //{1, 2, 3, 4, 5}
    auto it = st.find(3);//return iterator points to the 3

    //{1,2,3,4,5}
    auto it =st.find(6);// if element is not in the set it always return st.end()

    //{1,4,5}
    st.erase(5);//erase 5 //takes logarithmic time

    int cnt = st.count(1);

    auto it =st.find(3);
    st.erase(it);// it takes constant time

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);// after erase (1,4,5) [first, last]

    //lower_bound() and upper_bound()  function works in the same way
    //as in vector it does

    //This is the syntax
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);

}

void explainMultiSset(){
    //Everything is same as set
    //only stores duplicates elements also

    multiset<int>ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}

    ms.erase(1);//all 1's erasedd

    int cnt = ms.count(1);

    //only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1)+2);
    //rest all function same as set
}

void explainSet(){
    unordered_set<int> st;
    /*lower_bound, upper_bound functiondoes noot works ,
     rest all functions are same as above, 
     it does not stores in any particular order it has a better complexity
     than set in most cases, esccept some when collision happens
    */
}

void explainMap(){
    map<int , int> mpp;

    map<int, pair<int, int>> mpp;

    map< pair<int, int>, int> mpp;

    mpp[1] =2;

    mpp.emplace({3,1});

    mpp.insert({2,4});

    mpp[{2,3}] = 10;
    {
        {1,2}
        {2,4}
        {3,1}
        
    }
    
    for(auto it : mpp){
        cout << it.first << " "<< it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(3);
    cout<< *(it).second ;

    auto it = mpp.find(5);

    //This is the syntax
    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);
    
    //erase, swap, size, empty, are same as above

}

void explainMultiMap(){
    //everything same a map, only it can store multiple keys
    //only mpp[key] cannot be used here
}

void explainUnorderedMap(){
    //same as set unorderd_set difference 
}

//Algorithms

bool comp(pair<int,int>p1, pair<int, int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    //if they are same
    if(p1.first>p2.first) return true;
    return false;
}

void explainExtra(){
    sort(a, a+n);

    sort(a+2, a+4);

    sort(a, a+n, greater<int>);
    pair<int ,int> a[] {{1,2},{2,1},{4,1}};

    //sort it according to second element
    //if second element is same, then sort
    //it according to first element but in descending

    sort(a, a+n, comp);

    //{{4,1}, {2,1},{1,2}}

    int num = 7;
    int cnt = __builtin_popcount();

    long long num =1666884475662122;
    int cnt__builtin_popcountll();

    string s="123";

    do{
        cout << s ='123';
    }while(next_permutation(s.begin(, s.end())));

    int maxi = *max_element(a, a+n);

}
int main(){
// print();
// int d =sum(1,5);
// cout << d;
//explainPair();
explainVector();
return 0;

}