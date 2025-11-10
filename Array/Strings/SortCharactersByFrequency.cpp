#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<char> SortByFrequency(string s){
        unordered_map<char,int>mpp;
        for(int i=0; i<s.length();i++){
             mpp[s[i]]++;
        }
        vector<pair<char,int>> arr;
        for(auto &it : mpp) arr.push_back(it);
        sort(arr.begin(), arr.end(), [](pair<char,int> &a, pair<char,int>&b){
             return a.second>b.second;
        });    
        vector<char>result;
        for( auto &i: arr){
            result.push_back(i.first);
        }

        return result;
    }
};

int main(){
    string s;
    cout<<"enter string: "<<endl;
    cin>>s;

    Solution obj;

    vector<char> ans=obj.SortByFrequency(s);
    cout<<"Output is:"<<endl;
    for(auto i:ans) cout<<i<<" ";
    return 0;
}