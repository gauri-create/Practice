#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int>search(string pat, string txt){
        const int d=256;
        const int q=101;

        int m=pat.length();
        int n=txt.length();

        vector<int>result;

        if(m>n) return result;

        int pHash=0;
        int tHash=0;
        int h=1;

        for(int i=0; i<m-1; i++){
            h=(h*d)%q;
        }
        for(int i=0; i<m; i++){
            pHash=(d*pHash+pat[i])%q;
            tHash=(d*tHash+txt[i])%q;
        }
        for(int i=0; i<n-m+1; i++){
            if(pHash == tHash){
                bool match=true;
                for(int j=0; j<m; j++){
                    if(txt[i+j] != pat[j]){
                        match=false;
                        break;
                    }
                }
                if(match) result.push_back(i);
            }
            if(i<n-m){
                tHash=(d*(tHash-txt[i]*h)+txt[i+m])%q;
                if(tHash<0) tHash+=q;
            }
        }
        return result;
    }
};

int main(){
    string text="ababcabcababc";
    string pattern="abc";
    Solution obj;
    vector<int>ans=obj.search(pattern, text);
    for(auto x: ans) cout<<x<<" ";
    return 0;
}