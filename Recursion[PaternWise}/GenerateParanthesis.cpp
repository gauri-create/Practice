#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    vector<string>GenerateParanthesis(int n){
       vector<string> ans;
       generate("",0,0,n,ans);
       return ans;
    }
    private:
    void generate(string current,int open, int close, int n, vector<string>&ans){
        if(current.size()==n*2){
            ans.push_back(current);
            return;
        }
        //Always allowed to add '0'
        if(open<n){
            generate(current+"(",open+1,close, n, ans);
        }

        //Add '1' only if last char isn't '1'
        if(close<open){
            generate(current+")", open, close+1, n, ans);
        }
    }

    
        
};

int main(){
    int n=2;
    Solution obj;
    vector<string>arr=obj.GenerateParanthesis(n);
    for( auto x: arr){
        cout<<x<<endl;
    }
    return 0;
}