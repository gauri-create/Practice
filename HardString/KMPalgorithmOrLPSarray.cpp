#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    private:
    vector<int>computeLPS(string pattern){
        vector<int>lps(pattern.length(), 0);
        int len=0;
        int i=1;
        while(i<pattern.length()){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }

    public:
    vector<int>search(string pat, string txt){
        vector<int>lps=computeLPS(pat);
        vector<int>result;
        int i=0;
        int j=0; 
        while(i<txt.length()){
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            if(j==pat.length()){
                result.push_back(i-j);
                j=lps[j-1];
            }
            else if(i<txt.length() && txt[i]!=pat[j]){
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        return result;
    }
};

int main(){
    string text="abracadabra";
    string pattern="abra";
    Solution obj;
    vector<int>ans=obj.search(pattern, text);
    for(auto x: ans) cout<<x<<" ";
    return 0;
}