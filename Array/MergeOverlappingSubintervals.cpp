#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals1(vector<vector<int>> &nums){
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    for(int i=0; i<n; i++){
        int start=nums[i][0];
        int end = nums[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1; j<n;j++){
            if(nums[j][0]<=end){
                 end = max(end, nums[j][1]);
            }
            else{
                break;
            }
        }
    ans.push_back({start, end});
    }
    return ans;  

}

vector<vector<int>> mergeOverlappingIntervals2(vector<vector<int>> &nums){
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    for(int i=0; i<n; i++){
        if(ans.empty()||nums[i][0]>ans.back()[1]){
             ans.push_back({nums[i]});
        }
        else{
             ans.back()[1]=max(ans.back()[1], nums[i][1]);
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    cout << "Enter each interval (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> ret = mergeOverlappingIntervals1(arr);
    vector<vector<int>> ret = mergeOverlappingIntervals2(arr);

    cout << "Merged intervals:\n";
    for (auto &interval : ret) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
