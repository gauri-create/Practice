#include<iostream>
#include<vector>
using namespace std;

class Solution{
    vector<int> computeZArray(const string &s){
        int n=s.length();
        vector<int>z(n, 0);
        int left=0, right=0;

        for(int i=1; i<n; i++){
            if(i<=right) z[i]=min(right-i+1, z[i-left]);
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
            if(i+z[i]-1>right){
                left=i;
                right=i+z[i]-1;
            }
        }
        return z;
    }
    
    public:
    vector<int>search(string text, string pattern){
        string combined = pattern+"$"+text;
        vector<int>z=computeZArray(combined);
        vector<int>result;
        for(int i=pattern.length()+1; i<combined.length(); i++){
            if(z[i]==pattern.length()){
                result.push_back(i-pattern.length()-1);
            }
        }
        return result;
    }
};

int main(){
    string text="xyzabxyzabxyz";
    string pattern="xyz";
    Solution obj;
    vector<int>ans=obj.search(text, pattern);
    for(auto x: ans) cout<<x<<" ";
    return 0;
}