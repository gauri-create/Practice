#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n=arr.size();
        vector<int> nums(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while((!st.empty()) && (st.top()>arr[i])) st.pop();
            if(st.empty()) nums[i]=-1;
            else nums[i]=st.top();
            st.push(arr[i]);
        }
        return nums;
    }
};

int main(){
    Solution obj;
    vector<int> arr={4, 8, 5, 2, 25};
    vector<int>ans = obj.nextSmallerElements(arr);
    for(auto i: ans) cout<<i<<" ";
    return 0;
}