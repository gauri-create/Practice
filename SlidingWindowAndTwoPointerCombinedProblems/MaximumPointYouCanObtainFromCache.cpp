#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxScore(vector<int> & cardScore, int k){
        int lsum=0, rsum=0, maxSum=0;
        for(int i=0; i<k; i++)lsum+=cardScore[i];
        maxSum=lsum;
        int rindex=cardScore.size()-1;
        for(int i=k-1; i>=0; i--){
            lsum-=cardScore[i];
            rsum+=cardScore[rindex];
            rindex--;
            maxSum=max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};

int main(){
    Solution obj;
    vector<int>cardScore={5,4,1,8,7,1,3};
    int k=3;
    int ans = obj.maxScore(cardScore, k);
    cout<<ans;
    return 0;
}