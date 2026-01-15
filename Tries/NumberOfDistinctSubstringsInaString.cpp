#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
    public:
    int countDistinctSubstring(string s){
        int n=s.length();
        unordered_set<string> st;
        int cnt=1;
        for(int i=0; i<n; i++){
            string str="";
            for(int j=i; j<n; j++){
                str += s[j];
                if(st.find(str)==st.end()){
                st.insert(str);
                cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    string s="banana";
    Solution obj;
    int ans=obj.countDistinctSubstring(s);
    cout<<ans;
    return 0;
}