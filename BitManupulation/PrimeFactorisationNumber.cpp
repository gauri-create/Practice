#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<vector<int>> primeFactors(vector<int>& queries){
            vector<vector<int>> result(queries.size());
            vector<int> spf(100001);
            for (int i=1; i<=100000; i++){
                spf[i]=1;
            }
            for(int i=2; i*i<=100000;i++){
                if(spf[i]==1){
                    for(int j=i*i; j<=100000; j+=i){
                        if(spf[j]==1)
                            spf[j]=i;
                    }
                }
            }

            for(int i=0; i<queries.size();i++){
                int num=queries[i];
                vector<int>factors;
                while(num){
                    if(spf[num]==1){
                        factors.push_back(num);
                        break;
                    }
                    factors.push_back(spf[num]);
                    num=num/spf[num];
                }
                result.push_back(factors);
            }
            return result;
        }
};

int main(){
    vector<int> nums={7,12,18};
    Solution obj;
    vector<vector<int>> ans=obj.primeFactors(nums);
    for(auto i: ans){
        if(i.empty()) continue;
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
}


