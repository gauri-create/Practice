#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n=coins.size();
        int cnt=0;
        for(int i=n-1; i>=0; i--){
            while(amount>=coins[i]){
                amount-=coins[i];
                cnt++;
            }
        }
        return amount==0?cnt:-1;
    }
};

int main(){
    Solution obj;
    vector<int>coins={1,2,5};
    int amount=11;
    int mincoin=obj.MinimumCoins(coins, amount);
    cout<<mincoin;
    return 0;
}