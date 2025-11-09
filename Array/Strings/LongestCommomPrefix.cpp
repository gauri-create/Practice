#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    //brute
        string LongestCommonPrefix1(vector<string> & str){
            string ans=str[0];
            int n=str.size();
            for(int i=1; i<n; i++){
                int j=0;
                while(j<ans.size() && j<str[i].size() && ans[j]==str[i][j]){
                    j++;
                }
                ans=ans.substr(0,j); 
            }
            return ans;
        }
    //Optimal


       bool isCommonPrefix(vector<string>& strs, int len) {
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < len; j++) {
                if (strs[i][j] != strs[0][j])
                    return false;
            }
        }
        return true;
    }

    string LongestCommonPrefix2(vector<string>& strs) {
        if (strs.empty()) return "";

        // Find the minimum string length
        int minLen = strs[0].size();
        for (const auto& s : strs)
            if (s.size() < minLen) minLen = s.size();

        int low = 0, high = minLen;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid))
                low = mid + 1;  // try longer prefix
            else
                high = mid - 1; // try shorter prefix
        }

        // 'high' will have the maximum prefix length
        return strs[0].substr(0, high);
    }

};

int main(){
    int no;
    cout<<"Enter number of vector: ";
    cin>>no;

    vector<string> arr(no);
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }

    Solution obj;

    // string ans = obj.LongestCommonPrefix1(arr);
    string ans = obj.LongestCommonPrefix2(arr);

    cout<<"Longest common prefix is "<<ans;
    return 0;
}