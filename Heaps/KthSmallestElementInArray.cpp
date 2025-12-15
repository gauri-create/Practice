#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
   /* //BruteForce
    int kthSmallestElement(vector<int>& nums, int k){
        priority_queue<int>pq;
        for(int i=0; i<k;i++)pq.push(nums[i]);
        for(int i=k; i<nums.size();i++){
            if(nums[i]<pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();   
    }
    //BruteForce  */

    //optimal

    int kthSmallestElement(vector<int>&nums, int k){
        if(k>nums.size()) return -1;
        int left=0, right=nums.size()-1;

        while(true){
            int pivotIndex = randomIndex(left, right);
            pivotIndex=partitionAndReturnIndex(nums, pivotIndex, left, right);
            if(pivotIndex==k-1) return nums[pivotIndex];
            else if(pivotIndex>k-1)right=pivotIndex-1;
            else left=pivotIndex+1;
        }
        return -1;
    }
    private:
    int randomIndex(int &left, int &right){
        int len=right-left+1;
        return (rand()% len)+left;
    }
    int partitionAndReturnIndex(vector<int>&nums, int pivotIndex, int left, int right){
        int pivot=nums[pivotIndex];
        swap(nums[left], nums[pivotIndex]);
        int ind=left+1;
        for(int i=left+1; i<=right; i++){
            if(nums[i]<pivot){
                swap(nums[ind], nums[i]);
                ind++;
            }
        }
        swap(nums[left], nums[ind-1]);
        return ind-1;
    }
};

int main(){
    Solution obj;
    vector<int> nums={1, 2, 3, 4, 5};
    int k=2;
    int ans=obj.kthSmallestElement(nums, k);
    cout<<ans;
    return 0;
}