#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
    int lhist(vector<int> &heights) {
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
public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m));
        int sum=0;
        int maxArea=0;
        for(int j=0; j<m; j++){
            sum=0;
            for(int i=0; i<n; i++){
                sum+=matrix[i][j];
                if(matrix[i][j] == 0){ 
                    prefixSum[i][j]=sum;
                    sum=0;
                }
                prefixSum[i][j]=sum;
            }
        }
        for(int i=0; i<n; i++){
            maxArea=max(maxArea, lhist(prefixSum[i]));
        }
        return maxArea;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> matrix={
        {1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };
    int ans= obj.maximalAreaOfSubMatrixOfAll1(matrix);
    cout<<ans;
    return 0;
}