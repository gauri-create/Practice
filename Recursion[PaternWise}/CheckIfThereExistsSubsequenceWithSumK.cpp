#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int n=nums.size();
        return Check(0,0,k,nums,n);
    }

    bool Check(int ind,  int s,int sum, vector<int>&arr, int n){
        if(ind==n){
            return s==sum;
            
        }
        s+=arr[ind];
        if(Check(ind+1,s,sum,arr,n)==true) return true;
        s-=arr[ind];
        if(Check(ind+1, s, sum, arr, n)==true) return true;
        return false;
    }
};

int main(){
    Solution obj;
    vector<int>arr={1,2,3,4,5};
    int sum=8;
    bool ans=obj.checkSubsequenceSum(arr, sum);
    if(ans==true) cout<<"Yes";
    else cout<<"No";
    return 0;
}