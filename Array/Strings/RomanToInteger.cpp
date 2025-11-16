#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int RomanToInt(string s){
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int ans = 0;

        for(int i=0; i<s.length(); i++){
            if(mpp[s[i]]<mpp[s[i+1]]){
                ans -= mpp[s[i]];
            }
            else{
                ans += mpp[s[i]];
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cout<<"Enter roman number: ";
    cin>>s;

    Solution obj;
    int ret=obj.RomanToInt(s);
    cout<<s<<" roman to integer is "<<ret;
    return 0;
}