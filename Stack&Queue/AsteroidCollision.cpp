#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<int>aestoroidCollision(vector<int> &aestoroids){
        int n = aestoroids.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(aestoroids[i]>0) st.push(aestoroids[i]);
            else{
                while(!st.empty() && st.top()>0 && st.top()< abs(aestoroids[i])) st.pop();
                if(!st.empty() && st.top()==abs(aestoroids[i])) st.pop();
                else if(st.empty() || st.top()<0) st.push(aestoroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> aestoroids={1,2,3,-4,-2};
    vector<int> ans = obj.aestoroidCollision(aestoroids);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}