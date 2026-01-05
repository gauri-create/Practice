#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int nonAdjacent(vector<int> & nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1; i<n; i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;
            int curi=max(take, notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }

    int houseRobber(vector<int>&valueInHouse){
        vector<int> temp1,temp2;
        int n=valueInHouse.size();
        if(n==1) return valueInHouse[0];
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(valueInHouse[i]);
            if(i != n-1) temp2.push_back(valueInHouse[i]);
        }
        return max(nonAdjacent(temp1), nonAdjacent(temp2));
    }
};

int main(){
    vector<int>money={2,1,4,9};
    Solution obj;
    int ans=obj.houseRobber(money);
    cout<<ans;
    return 0;
}