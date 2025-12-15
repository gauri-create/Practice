#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int l=0, r=0, maxlen=0, k=2;
        unordered_map<int, int> mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size()<=k)  maxlen=max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};

int main(){
    Solution obj;
    vector<int> fruits={1,2,3, 2, 2};
    int ans = obj.totalFruits(fruits);
    cout<<ans;
    return 0;
}