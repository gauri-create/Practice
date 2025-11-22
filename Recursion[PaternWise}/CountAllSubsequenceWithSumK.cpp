#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int CountAllSubsequence(vector<int> &nums, int k){
        int n=nums.size();
        int ans=Count(0, 0, k, nums, n);
        return ans;
    }
    private:
    int Count(int ind, int s, int sum, vector<int> arr, int n){
        if(ind==n){
        //condition satisfiedd
            if(s==sum) return 1;
            else 
                return 0;
        }
        s+=arr[ind];
        int l= Count(ind+1, s, sum,arr, n);
        s-=arr[ind];
        int r= Count(ind+1,s, sum,arr, n);
        return l+r;
    }
};

int main(){
    Solution obj;
    vector<int> arr={4,2,10,5,1,3};
    int sum=5;
    int ans=obj.CountAllSubsequence(arr, sum);
    cout<<ans;
    return 0;
}