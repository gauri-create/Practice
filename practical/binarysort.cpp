#include<iostream>
#include<vector>
using namespace std;

class MergeS{
    public:
    void MergeSort(int low, int high, vector<int>&nums){
        if(low>=high)return;
        int mid=(low+high)/2;
        
        MergeSort(low,mid, nums);
        MergeSort(mid+1, high, nums);
        Merge(nums, low, mid, high);
    }
    void Merge(vector<int>&nums, int low, int mid, int high){
        int n1=mid-low+1;
        int n2=high-mid;
        vector<int> left(n1);
        vector<int>right(n2);

        for(int i=0; i<n1; i++){
            left[i]=nums[low+i];
        }

        for(int i=0; i<n2; i++){
            right[i]=nums[mid+1+i];
        }

        int i=0, j=0, k=low;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                nums[k]=left[i];
                i++;
                k++;
            }
            else {
                nums[k]=right[j];
                j++;
                k++;
            }
        }
        while(i<n1){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=right[j];
            k++;
            j++;
        }
    }
};

class QuickS{
    public:
    void QuickSort(vector<int> &nums, int low, int high){
        if(low>=high) return ;

        int i=low;
        int j=high;
        int pivot=nums[low];
        while(i<j){
            while(i<=high&&nums[i]<=pivot)i++;
            while(nums[j]>pivot)j--;
            if(i<j)swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        QuickSort(nums, low, j-1);
        QuickSort(nums, j+1, high);
    }
};

class Binary_Search{
    public:
    int BinarySearch(vector<int> &nums,int low, int high, int val ){
        int n=nums.size();
        if(low>high)return -1;
        int mid=(low+high)/2;
        if(nums[mid]==val)return mid;
        if(nums[mid]>val){
            return BinarySearch(nums, low, mid-1, val);
        }
        else if(nums[mid]<val){
            return BinarySearch(nums, mid+1, high, val);
        }
        return 0;
    }
};

int main(){
    MergeS obj;
    QuickS obj1;
    Binary_Search bs;
    vector<int> nums={1,5,7,8,35,45,67,78};
    // obj.MergeSort(0,nums.size()-1, nums);
    // obj1.QuickSort(nums, 0, nums.size()-1);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }

    int ans=bs.BinarySearch(nums,0, nums.size()-1, 45);
    cout<<"Find at index "<<ans;

    return 0;
}