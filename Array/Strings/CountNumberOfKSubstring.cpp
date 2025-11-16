#include<iostream>
#include<map>
using namespace std;

class Solution{
    public:
    int CountAtMost(string s, int k){
        map<char, int> mpp;
        int left=0;
        int distinct=0;
        int ans=0;
        for(int right=0; right<s.length(); right++){
            mpp[s[right]]++;
            if(mpp[s[right]]==1) distinct++;
            while(distinct >k){
                mpp[s[left]]--;
                if(mpp[s[left]]==0)
                    distinct--;
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
    int CountString(string s,int k){
        if(k<=0) return 0;
        int ret1 = CountAtMost(s, k);
        int ret2 = CountAtMost(s, k-1);
        int ans=ret1-ret2;
        return ans;
    }
};

int main(){
    string s;
    int k;

    cout<<"Enter string: ";
    getline(cin, s);

    cout<<"Enter value of k: ";
    cin>>k;
    
    Solution obj;
    int ans = obj.CountString(s, k);
    
    cout<<"Number of k substring in string is "<<ans;
    return 0;
}