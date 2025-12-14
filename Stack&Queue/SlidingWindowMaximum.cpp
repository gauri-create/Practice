#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int>list;
        deque<int>dq;
        for(int i=0; i<n; i++){
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && arr[dq.back()]<=arr[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) list.push_back(arr[dq.front()]);
        }
        return list;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k=3;
    vector<int>ans = obj.maxSlidingWindow(arr, k);
    for(auto i : ans)cout<<i<<" ";
    return 0;
}