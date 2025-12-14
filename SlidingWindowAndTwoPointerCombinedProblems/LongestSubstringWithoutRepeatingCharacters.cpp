#include<iostream>
// #include<unordered_map>
using namespace std;

class Solution{
    public:
    int longestNonRepeatingSubstring(string &s){
        int n=s.size();
        int Hashlen=256;
        int hash[Hashlen];

        for(int i=0; i<Hashlen; i++){
            hash[i]=-1;
        }

        int l=0, r=0, maxLen=0;
        while(r<n){
            if(hash[s[r]] != -1){
                l=max(hash[s[r]]+1, l);
            }
            int len = r-l+1;
            maxLen=max(maxLen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};

int main(){
    Solution obj;
    string s="abcddabac";
    int ans = obj.longestNonRepeatingSubstring(s);
    cout<<ans;
    return 0;
}