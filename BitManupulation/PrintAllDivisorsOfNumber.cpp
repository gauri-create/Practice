#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<int> divisors(int n) {
        vector<int> result;
        for(int i=1; i*i<n; i++){
            if(n%i==0){
                result.push_back(i);
                if(n/i!=i)
                    result.push_back(n/i);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
    
};

int main(){
    Solution obj;
    int n=8;
    vector<int>ans=obj.divisors(n);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
