#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    vector<string>GeneratePowerSet(string s){
       vector<string> ans;
       generate(0, "", s, ans);
       return ans;
    }

    private:
    void generate(int i, string current, string &s, vector<string>&ans){
        if(i==s.size()){
            ans.push_back(current);
            return;
        }
        //include s[i]
        generate(i+1, current+s[i], s, ans);

        //excludes[i]
        generate(i+1, current, s, ans);
    }
    
        
};

int main(){
    string s="abc";
    Solution obj;
    vector<string>arr=obj.GeneratePowerSet(s);
    for( auto x: arr){
        cout<<x<<endl;
    }
    return 0;
}