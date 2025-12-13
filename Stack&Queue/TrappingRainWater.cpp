#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int trap(vector<int> &height){
        int l=0;
        int r=height.size()-1;
        int lMax =0, rMax =0, total = 0;
        while(l<r){
            if(height[l]<=height[r]) {
                if(lMax > height[l]) total+=lMax-height[l];
                else lMax=height[l];
                l=l+1;
            }
            else{
                if(rMax>height[r]) total+=rMax-height[r];
                else rMax=height[r];
                r=r-1;
            }     
        }
        return total;
    }
};

int main(){
    Solution obj;
    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = obj.trap(arr);
    cout<<ans;
    return 0;
}