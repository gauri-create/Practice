#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    vector<string>GenerateBinaryString(int n){
       vector<string> ans;
       generate("",n,ans);
       return ans;
    }
    private:
    void generate(string current, int n, vector<string>&ans){
        if(current.size()==n){
            ans.push_back(current);
            return;
        }
        //Always allowed to add '0'
        generate(current+"0", n, ans);

        //Add '1' only if last char isn't '1'
        if(current.empty()||current.back()!='1'){
            generate(current+"1", n, ans);
        }
    }

    
        
};

int main(){
    int n=2;
    Solution obj;
    vector<string>arr=obj.GenerateBinaryString(n);
    for( auto x: arr){
        cout<<x<<" ";
    }
    return 0;
}