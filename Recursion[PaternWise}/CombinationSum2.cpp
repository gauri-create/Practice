 #include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(0,target, candidates, ans, ds);
        return ans;
    }

    private:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i= ind; i<arr.size(); i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombination(i+1, target-arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

};

int main(){
    Solution obj;
    vector<int> arr={1,1,1,2,2};
    int target=4;
    vector<vector<int>> ans=obj.combinationSum2(arr, target);
    for(const auto &row : ans){
        for(int x : row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}