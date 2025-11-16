#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    int beautySum(string s){
        int n=s.length();
        int sum=0;

        for(int i = 0; i<n; i++){
            unordered_map<char,int> freq;
            for(int j=i; j<n; j++){
                freq[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto it : freq){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                sum+=(maxi - mini);
            }
        }
        return sum;
    }
};

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    Solution obj;
    int ret=obj.beautySum(s);
    cout<<"The sum of beauty is: "<<ret;
    return 0;
}