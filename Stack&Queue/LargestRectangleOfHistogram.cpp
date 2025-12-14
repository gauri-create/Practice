#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int>st;
        int maxArea=0;
        int n=heights.size();
        int pse, nse, element;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                element=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxArea = max(heights[element] * (nse-pse-1), maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            element =st.top();
            st.pop();
            pse=st.empty()?-1:st.top();
            maxArea = max(maxArea, ((nse-pse-1)*heights[element]));
        }
        return maxArea;
    }
};

int main(){
    Solution obj;
    vector<int> heights = {3, 5, 1, 7, 5, 9};
    int area= obj.largestRectangleArea(heights);
    cout<<area;
    return 0;
}