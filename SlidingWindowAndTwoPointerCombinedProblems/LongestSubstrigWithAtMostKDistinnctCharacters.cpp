#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    int kDistinctChar(string &s, int k){
        int maxlen=0, l=0, r=0;
        unordered_map<char, int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l++;
            }
            if(mpp.size() <= k){
                maxlen=max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    Solution obj;
    string s="aababbcaacc";
    int k=2;
    int ans = obj.kDistinctChar(s, k);
    cout<<ans;
    return 0;
}