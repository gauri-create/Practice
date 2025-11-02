#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum1(vector<int> &nums, int target){
    int i=0, j=0;
    vector<int> val(2);
    for(i=0; i<=nums.size()-1; i++){
    for(j=i+1; j<=nums.size();i++){
        if(nums[i]+nums[j]==target){
            val[0]=i;
            val[1]=j;
            return val;
        }

    }
}
}

vector<int> twoSum2 (vector<int> &nums, int target){
    int no= nums.size();
    map<int, int> mpp;
    for(int i=0; i<no; i++){
        int a = nums[i];
        int b= target-a;
        if(mpp.find(b)!= mpp.end()){
            return {mpp[b], i};
        }
        mpp[a]=i;
    }
    return {-1, -1};
}
 
vector<int> twoSum3(vector<int> nums, int target){
    int left=0;
    int right=nums.size()-1;
    sort(nums.begin(), nums.end());
    while(left<right){
        if(nums[left]+nums[right] == target){
           return {left, right};
        }

        if (nums[left]+nums[right] > target){
            right--;
        }

        if(nums[left]+nums[right] < target){
            left++;
        }

    }
}

int main(){
    int no=0;
    int target=0;
    cout<<"Enter length of arry";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter arry element";
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"enter target: ";
    cin>>target;
    // vector<int> ret = twoSum1(arr, target);
    // vector<int> ret = twoSum2(arr, target); 
    vector<int> ret = twoSum3(arr, target);
    for(int val : ret ){
        cout<<val<<" ";
    }
    return 0;
}