#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void BubbleSort(vector<int>&nums){
        int n=nums.size();
        for(int i=0; i<n-1;i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]>nums[j]){
                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                }
            }
        }
    }

    void InsertionSort(vector<int>&nums){
        for(int i=1; i<nums.size();i++){
            int key=nums[i];
            int j=i-1;
            while(j>=0 && nums[j]>key){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }
    }

    void SelectionSort(vector<int>&nums){
        int minIndex;
        for(int i=0; i<nums.size()-1; i++){
            minIndex=i;
            for (int j=i+1; j<nums.size(); j++){
                if(nums[j]<nums[minIndex])
                minIndex=j;
            }
            if(minIndex!=i){
                swap(nums[i], nums[minIndex]);
            }
        }
    }

};

int main(){
    Solution obj;
    vector<int>nums={2,6,3,8,3,8,1,0,3};
    // obj.BubbleSort(nums);
    // obj.InsertionSort(nums);
    obj.SelectionSort(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

