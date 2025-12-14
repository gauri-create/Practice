#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
    vector<int>findNSE(vector<int>&arr, int n){
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while((!st.empty()) && (arr[st.top()]>=arr[i])) st.pop();
            nse[i]=st.empty()? n: st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int>findPSEE(vector<int>&arr, int n){
        vector<int>psee(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            psee[i]=st.empty()? -1:st.top();
            st.push(i);
        }
        return psee;
    }

    public:
    int sum(vector<int>&arr){
        int n=arr.size();
        vector<int> nse=findNSE(arr, n);
        vector<int> pse=findPSEE(arr, n);
        int total=0;
        int mod=(1e9+7);
        for(int i=0; i<n; i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(right*left*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};

int main(){
    Solution obj;
    vector<int> arr={3,1,2,4};
    int ans= obj.sum(arr);
    cout<<ans;
    return 0;
}