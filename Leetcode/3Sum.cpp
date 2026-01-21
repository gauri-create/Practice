#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];
            while (j < k)
            {

                int sum = nums[j] + nums[k];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }

                else if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}