#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
//Brute force
    // vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    //     vector<int>ans(indices.size());
    //     for(int i=0; i<indices.size();i++){
    //         int cnt =0;
    //         for(int j=indices[i]; j<arr.size(); j++){
    //             if(arr[j]>arr[indices[i]]) cnt++;
    //         }
    //         ans[i]=cnt;
    //     }
    //     return ans;
    // }

// optimal not found
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            int currEle=arr[i];

            while((!st.empty()) && (st.top() <= currEle)){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else
                ans[i]=st.top();
            st.push(currEle);
        }
        
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> arr={3,4,2,7,5,8,10,6};
    vector<int> indices ={0,5};
    vector<int> ans = obj.count_NGE(arr, indices);
    for(auto i: ans) cout<<i<<" ";
    return 0;
}