#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    sum = nums[i] + nums[j];
                    sum = sum + nums[k] + nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < n && nums[k] == nums[k - 1])
                            k++;
                        while (l > k && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;
                } 
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution obj;
    vector<vector<int>> ans = obj.fourSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
