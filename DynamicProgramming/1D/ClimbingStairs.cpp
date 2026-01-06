#include<iostream>
using namespace std;

class Solution{
    public:
    int climbStairs(int n){
        if(n<=1) return 1;
        int prev2=1;
        int prev1=2;
        for(int i=3; i<=n; i++){
            int curr = prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

int main(){
    int n=3;
    Solution obj;
    int ans = obj.climbStairs(n);
    cout<<ans;
    return 0;
}