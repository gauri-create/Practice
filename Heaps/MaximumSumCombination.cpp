#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

class Solution{
    public:
    /*
    //brute
    vector<int>maxCombinations(vector<int>& nums1, vector<int>nums2, int k){
        vector<int>allSums;
        for(int i=0;i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                allSums.push_back(nums1[i]+nums2[j]);
            }
        }
        sort(allSums.begin(), allSums.end(), greater<int>());
        vector<int> result(allSums.begin(), allSums.begin()+k);
        return result;
    }
*/
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());

    priority_queue<tuple<int,int,int>> pq;
    set<pair<int,int>> visited;

    pq.push({nums1[0] + nums2[0], 0, 0});
    visited.insert({0, 0});

    vector<int> result;

    while (k-- && !pq.empty()) {
        auto [sum, i, j] = pq.top();
        pq.pop();
        result.push_back(sum);

        if (i + 1 < nums1.size() && !visited.count({i + 1, j})) {
            pq.push({nums1[i + 1] + nums2[j], i + 1, j});
            visited.insert({i + 1, j});
        }

        if (j + 1 < nums2.size() && !visited.count({i, j + 1})) {
            pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }

    return result;
}

};

int main(){
    Solution obj; 
    vector<int> nums1={7,3};
    vector<int> nums2={1,6};
    int k=2;
    vector<int> result=obj.maxCombinations(nums1, nums2, k);
    for(int val : result) cout<<val<<" ";
    cout<<endl;
    return 0;
}