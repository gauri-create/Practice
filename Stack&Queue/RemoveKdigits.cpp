#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution{
    public:
    string removeKdigits(string nums, int k){
        int n=nums.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(nums[i]-'0')){
                st.pop();
                k=k-1;
            }
            st.push(nums[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res="";
        while(!st.empty()){
            res=res+st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0')res.pop_back();
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";
        return res;
    }
};

int main(){
    Solution obj;
    string s="541892";
    int k=3;
    string ans = obj.removeKdigits(s, k);
    cout<<ans;
    return 0;
}