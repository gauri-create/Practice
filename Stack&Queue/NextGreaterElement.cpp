#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> findNGE(vector<int >arr){
        int n=arr.size();
        vector<int> nge(n);
        stack<int>st;
        // st.push(arr[n]);
        for(int i=n-1; i>=0; i--){
            while((!st.empty()) && (st.top()<arr[i])) st.pop();
            if(st.empty()) nge[i]=-1;
            else nge[i]=st.top();
            st.push(arr[i]);
        }
        return nge;
    }
};

int main(){
    Solution obj;
    vector<int> arr={4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> ans=obj.findNGE(arr);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}