#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    string shortestPalindrome(string s){
        string rev=s;
        reverse(rev.begin(), rev.end());

        string combined=s+"#"+rev;
        int n=combined.size();

        vector<int>lps(n, 0);
        for(int i=1; i<n; i++){
            int j=lps[i-1];
            while(j>0 && combined[i] != combined[j]){
                j=lps[j-1];
            }
            if(combined[i] == combined[j])j++;
            lps[i]=j;
        }
        int longestPalPrefix=lps[n-1];
        string add=s.substr(longestPalPrefix);
        reverse(add.begin(), add.end());
        return add+s;
    }
};

int main(){
    string s="aacecaaa";
    Solution obj;
    string ans=obj.shortestPalindrome(s);
    cout<<ans;
    return 0;
}