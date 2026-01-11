#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
    public:
    string lcs(string str1, string str2){
        int n=str1.size();
        int m=str2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i=n, j=m;
        string lcs="";

        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                lcs+=str1[i-1];
                i--;
                j--;
            }
            else if(str1[i-1]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

int main(){
    string str1="bdefg";
    string str2="bfg";
    Solution obj;
    string ans =obj.lcs(str1, str2);
    cout<<ans;
    return 0;
}