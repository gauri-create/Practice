#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(m>n) return "";
        int minLen = INT_MAX, start = -1;

        int i = 0;
        while (i < n) {
            int j = 0;
            int r = i;

            // Forward match
            while (r < n && j < m) {
                if (s1[r] == s2[j])
                    j++;
                r++;
            }

            if (j < m) break;  // no more possible matches

            // Backward shrink
            int end = r - 1;
            j = m - 1;
            while (end >= i) {
                if (s1[end] == s2[j]) {
                    j--;
                    if (j < 0) break;
                }
                end--;
            }

            int len = r - end - 1;
            if (len < minLen) {
                minLen = len;
                start = end + 1;
            }

            i = end + 2; // move start forward
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};

int main() {
    Solution obj;
    string s1 = "abcdebdde";
    string s2 = "bde";
    cout << obj.minWindow(s1, s2);
    return 0;
}
