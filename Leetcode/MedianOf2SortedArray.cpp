#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int k = n + m;
        int i=0, j=0, prev=0, cur=0;

        for(int cnt=0; cnt<=k/2; cnt++){
            prev=cur;
            if(i<n && (j>=m || nums1[i]<=nums2[j])){
                cur=nums1[i++];
            }
            else{
                cur=nums2[j++];
            }
        }
        if(k%2==1) return cur;
        return (cur+prev)/2.0;
    }
};

int main()

{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3, 4};
    Solution obj;
    double ans = obj.findMedianSortedArrays(nums1, nums2);
    cout << ans;
    return 0;
}