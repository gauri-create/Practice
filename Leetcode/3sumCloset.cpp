#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int threeSumCloset(vector<int> nums, int target)
    {
        int n = nums.size();
        int maxSum = 0;
        int remain = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2 ; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum =  nums[i] + nums[j] + nums[k];
                if (sum==target) return sum;
                int x = abs(target - sum);
                if (x < remain )
                {
                    remain = x;
                    maxSum = sum;
                }    
                if(sum<target && j<n)j++;
                if(sum>target && k>j)k--;
            }
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2};
    int target = 3;
    Solution obj;
    int ans = obj.threeSumCloset(nums, target);
    cout << ans;
    return 0;
}