#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<int> primesInRange(vector<vector<int>>& queries){
            vector<int>result;
            for(auto &it: queries){
                result.push_back(func(it[1])-func(it[0]-1));
            }
            return result;
        }
        int func(int n){
            vector<int> prime(n+1);
            for(int i=2; i<=n; i++){
                prime[i]=1;
            }
            for(int i=2; i*i<=n; i++){
                if(prime[i]==1){
                    for(int j=i*i ; j<=n; j+=i){
                        prime[j]=0;
                    }
                }
            }
            int  cnt=0;
            for(int i=2; i<=n; i++){
                if(prime[i]==1){
                     cnt++;
                }
            }
            return cnt;
        }
};

int main(){
    vector<vector<int>> nums={{1,7},{3,7}};
    Solution obj;
    vector<int> ans=obj.primesInRange(nums);
    for(auto i: ans){
        cout<<i<<" ";
    } 
    return 0;
}


