#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
    public:
    vector<int> findNGE(vector<int> arr){
        int n= arr.size();
        vector<int> nge(n);
        stack<int>st;
        for(int i= 2*n-1; i>=0; i--){
            while(!st.empty() && st.top()<=arr[i%n]) st.pop();
            if(i<n) nge[i]=st.empty()? -1 : st.top();
            st.push(arr[i%n]);
        }
        return nge;
    }
};

int main(){
    Solution obj;
    vector<int> arr={2, 10, 12, 1, 11};
    vector<int> ans= obj.findNGE(arr);
    for(auto i: ans)cout<<i<<" ";
    return 0;
}