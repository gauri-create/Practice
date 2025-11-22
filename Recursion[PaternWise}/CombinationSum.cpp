#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(0,target, candidates, ans, ds);
        return ans;
    }

    private:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //pick up the element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind, target-arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombination(ind+1, target, arr, ans, ds);
    }

};

int main(){
    Solution obj;
    vector<int> arr={2,3,5,4};
    int target=7;
    vector<vector<int>> ans=obj.combinationSum(arr, target);
    for(const auto &row : ans){
        for(int x : row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}