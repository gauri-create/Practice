#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

class KthLargest{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int num:nums){
            minHeap.push(num);
            if(minHeap.size()>k) minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()> size)minHeap.pop();
        return minHeap.top();
    }
    
};

int main(){
    vector<int> nums = {4, 5, 8, 2};
    KthLargest obj(3,nums);
    cout<<obj.add(3)<<endl;
    cout<<obj.add(5)<<endl;
    cout<<obj.add(10)<<endl;
    cout<<obj.add(9)<<endl;
    cout<<obj.add(4)<<endl;
    return 0;
}