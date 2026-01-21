#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() &&
               prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);

        if (prefix.empty()) return "";
    }
    return prefix;
}

};
int main(){
    vector<string>strs={"car","cir"};
    Solution obj;
    string ans=obj.longestCommonPrefix(strs);
    cout<<ans;
    return 0;
}