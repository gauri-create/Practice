#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

class Solution{
    public:
    int connectSticks(vector<int>& sticks){
        if(sticks.size() <= 1)return 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x : sticks) pq.push(x);

        int totalCost = 0;

        while(pq.size()>1){
            int a= pq.top(); 
            pq.pop();
            int b=pq.top();
            pq.pop();
            int cost = a+b;
            totalCost += cost;
            pq.push(cost);
        }
        return totalCost;
    }
};

int main(){
    Solution obj;
    vector<int>sticks = {2, 4, 3};
    int ans=obj.connectSticks(sticks);
    cout<<ans;
    return 0;
}

