#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string> ans;
        string temp;
        help(0,digits,temp,ans,m);
        return ans;

    }

    private:
    void help(int i, string &s, string &temp, vector<string> &ans, unordered_map<char,string> &m){
        if(i==s.size()){
            ans.push_back(temp);
        }
        string str = m[s[i]];
        for(int j=0; j<str.size();j++){
            temp.push_back(str[j]);
            help(i+1, s, temp, ans, m);
            temp.pop_back();
        }
    }
};

int main(){
    Solution obj;
    string s="34";
    vector<string> ans= obj.letterCombinations(s);
    for(auto x: ans){
        cout<<x<<endl;
    }
    return 0;
}