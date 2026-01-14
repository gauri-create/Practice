#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        int maxLen=0, maxIndex=0;
        for(int i=0; i<n; i++){
            if(dp[i] > maxLen){
                maxLen = dp[i];
                maxIndex=i;
            }
        }
        vector<int>lisSeq;
        int curr = maxIndex;
        while(curr != -1){
            lisSeq.push_back(arr[curr]);
            curr=prev[curr];
        }
        reverse(lisSeq.begin(), lisSeq.end());
        return lisSeq;
    }
};

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    Solution obj;
    vector<int> ans = obj.longestIncreasingSubsequence(arr);
    for (int x : ans)
        cout << x << " ";
    return 0;
}