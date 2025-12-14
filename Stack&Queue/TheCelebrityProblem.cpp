#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n=M.size();
        int top=0;
        int down=n-1;
        while(top<down){
            if(M[top][down]==1) top++;
            else{
                down--;
            }
        }
        for(int i=0; i<n; i++){
            if(i==top) continue;
            if(M[top][i]==1 || M[i][top]==0) return -1;
        }
        return top;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> M={
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };
    int ans = obj.celebrity(M);
    cout<<ans;
    return 0;
}