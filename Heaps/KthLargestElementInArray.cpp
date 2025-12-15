#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    int kthLargestElement(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<k;i++)pq.push(nums[i]);
        for(int i=k; i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();   
    }
};

int main(){
    Solution obj;
    vector<int> nums={1, 2, 3, 4, 5};
    int k=2;
    int ans=obj.kthLargestElement(nums, k);
    cout<<ans;
    return 0;
}