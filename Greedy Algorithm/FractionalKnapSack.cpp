#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    long long value;
    long long weight;
};

class Solution {
public:
    bool static comp(Item a, Item b){
        double r1=(double)a.value/a.weight;
        double r2=(double)b.value/b.weight;
        return r1>r2;
    }
    double fractionalKnapsack(vector<long long>& val, 
                              vector<long long>& wt, 
                              long long capacity) {
        int n=val.size();
        vector<Item> items(n);
        for(int i=0; i<n; i++){
            items[i]={val[i], wt[i]};
        }
        sort(items.begin(), items.end(), comp);
        double totalval=0.0;
        for(int i=0; i<n && capacity>0;i++){
            if(items[i].weight<=capacity) {
                capacity-=items[i].weight;
                totalval+=items[i].value;
            }
            else{
                totalval += (double)items[i].value*((double)capacity/items[i].weight);
                break;
            }
        }
        return totalval;
    }
};

int main(){
    Solution obj;
    vector<long long>val={60, 100, 120};
    vector<long long>wt={10, 20, 30};
    int capacity=50;
    double ans = obj.fractionalKnapsack(val, wt, capacity);
    cout<<ans;
    return 0;
}