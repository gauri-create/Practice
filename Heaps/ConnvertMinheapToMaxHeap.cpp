#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void heapify(vector<int>& arr, int n, int i){
        while(true){
            int largest=i;
            int l=2*i+1;
            int r=2*i+2;
        
            if(l<n && arr[l]>arr[largest]) largest=l;
            if(r<n && arr[r]>arr[largest]) largest=r;

            if(largest==i) break;

            swap(arr[i], arr[largest]);
            i=largest;
        }
    }

public:
    vector<int> minToMaxHeap(vector<int> nums) {
        int n=nums.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(nums, n, i);
        }
        return nums;
    }
};

int main(){
    Solution obj;
    vector<int>nums={-5,-4,-3,-2,-1};
    vector<int> ans=obj.minToMaxHeap(nums);
    for(auto i: ans) cout<<i<<" ";
    return 0;
}