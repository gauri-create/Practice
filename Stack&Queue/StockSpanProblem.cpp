#include<iostream>
#include<stack>
#include<vector>
using namespace std;;

class Solution{
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
       vector<int>span(n);
       stack<int>st;

        for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i])st.pop();
        span[i]=st.empty()?(i+1):(i-st.top());
        st.push(i);
        }
    return span;
    }
};

int main(){
    Solution obj;
    int n=7;
    vector<int> arr={120, 100, 60, 80, 90, 110, 115};
    vector<int> ans=obj.stockSpan(arr, n);
    for(auto i: ans) cout<<i<<" ";
    return 0;
}