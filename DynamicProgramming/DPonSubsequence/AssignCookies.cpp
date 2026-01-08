#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    //     //memoization
    // private:
    //     int helper(int studentIndex, int cookieIndex, vector<int> &student, vector<int> &cookie, vector<vector<int>> &memo)
    //     {
    //         if (studentIndex >= student.size() || cookieIndex >= cookie.size())
    //             return 0;

    //         if (memo[studentIndex][cookieIndex] != -1)
    //         {
    //             return memo[studentIndex][cookieIndex];
    //         }
    //         int result = 0;
    //         if (cookie[cookieIndex] >= student[studentIndex])
    //         {
    //             result = max(result, 1 + helper(studentIndex + 1, cookieIndex + 1, student, cookie, memo));
    //         }
    //         result = max(result, helper(studentIndex, cookieIndex + 1, student, cookie, memo));

    //         return memo[studentIndex][cookieIndex] = result;
    //     }

    // public:
    //     int findMaximumCookieStudents(vector<int> &student, vector<int> &cookie)
    //     {
    //         sort(student.begin(), student.end());
    //         sort(cookie.begin(), cookie.end());
    //         vector<vector<int>> memo(student.size(), vector<int>(cookie.size(), -1));
    //         return helper(0, 0, student, cookie, memo);
    //     }

//     // Tabulation
// public:
    // int findMaximumCookieStudents(vector<int> &student, vector<int> &cookie)
    // {
    //     int n = student.size();
    //     int m = cookie.size();

    //     sort(student.begin(), student.end());
    //     sort(cookie.begin(), cookie.end());

    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         for (int j = m - 1; j >= 0; j--)
    //         {
    //             int skip = dp[i][j + 1];
    //             int take = 0;
    //             if (cookie[j] >= student[i])
    //             {
    //                 take = 1 + dp[i + 1][j + 1];
    //             }
    //             dp[i][j] = max(skip, take);
    //         }
    //     }
    //     return dp[0][0];
    // }

//Space optimization
    public:
    int findMaximumCookieStudents(vector<int>student, vector<int>cookie){
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        int studentIndex=0;
        int cookieIndex=0;

        while(studentIndex<student.size() && cookieIndex<cookie.size()){
            if(cookie[cookieIndex] >= student[studentIndex]){
                studentIndex++;
            }
            cookieIndex++;
        }
        return studentIndex;
    }
 
};

int main()
{
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};
    Solution obj;
    int ans = obj.findMaximumCookieStudents(student, cookie);
    cout << ans;
    return 0;
}