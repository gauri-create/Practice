#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string ReverseWord2(string s) {
        int n = s.size();
        string cleaned = "";
        int i = 0;

        // Step 1: Clean the string (remove extra spaces)
        while (i < n) {
            // skip leading spaces
            while (i < n && s[i] == ' ') i++;

            // copy the word
            while (i < n && s[i] != ' ') {
                cleaned += s[i];
                i++;
            }

            // skip multiple spaces between words
            while (i < n && s[i] == ' ') i++;

            // add a single space if more words follow
            if (i < n) cleaned += ' ';
        }

        // Step 2: Reverse the entire string
        reverse(cleaned.begin(), cleaned.end());

        // Step 3: Reverse each word individually
        int start = 0, end = 0;
        n = cleaned.size();
        while (start < n) {
            end = start;
            while (end < n && cleaned[end] != ' ') end++;

            int left = start, right = end - 1;
            while (left < right) {
                swap(cleaned[left], cleaned[right]);
                left++;
                right--;
            }

            start = end + 1; // move to next word
        }

        return cleaned;
    }
};

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    Solution obj;
    string ans = obj.ReverseWord2(str);

    cout << "The reversed word string is: " << endl;
    cout << ans << endl;

    return 0;
}
