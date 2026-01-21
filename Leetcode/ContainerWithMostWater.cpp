#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int maxArea(vector<int> height){
        int n=height.size();
        int left=0;
        int right=n-1;
        int area=0;
        int maxArea=INT_MIN;
        while(left<right){
            int h=min(height[left], height[right]);
            int b=right-left;
            area=h*b;
            maxArea=max(maxArea, area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};

int main(){
    vector<int>heights={1,8,6,2,5,4,8,3,7};
    Solution obj;
    int ans=obj.maxArea(heights);
    cout<<ans;
    return 0;
}