#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int l=0, r=0, minlen=INT_MAX, sIndex=-1, cnt=0;
        int n=s.size();
        int m=t.size();
        for(int i=0; i<m; i++) hash[t[i]]++;
        while(r<n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minlen) {
                    minlen=r-l+1;
                    sIndex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        return sIndex==-1?"":s.substr(sIndex, minlen);
    }
};

int main(){
    Solution obj;
    string s="ADOBECODEBANC";
    string t="ABC";
    string ans = obj.minWindow(s, t);
    cout<<ans;
    return 0;
}