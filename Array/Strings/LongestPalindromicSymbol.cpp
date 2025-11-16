#include<iostream>
using namespace std;

class Solution{
    public:
      bool isPalindrome(const string& str){
        int left = 0;
        int right = str.length() -1;

        while(left<right){
            if(str[left]!= str[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    string LongPalSubString1(string s){
        //Bruteforce
        if(s.length()<=1){
            return s;
        }

        int max_len = 1;
        string max_str = s.substr(0,1);

        for(int i=0; i<s.length(); ++i){
            for(int j=i+max_len; j<=s.length();++j ){
                if(j-i > max_len && isPalindrome(s.substr(i, j-i)) ){
                    max_len=j-i;
                    max_str = s.substr(i, j-i);
                }
            }
        }
        return max_str;

    }


    //Better + optimal
    string LongestPalindrome(string str){
        int start =0;
        int end = 0;

        //Iterate through each character as center
        for(int center = 0; center <str.length(); center++){
            //Expand around odd length palindrome
            int lenOdd = expandFromCenter(str, center, center);
            //Expand around even length palindrome 
            int lenEven = expandFromCenter(str, center, center+1);
            //Get the max of both lengths
            int maxLen = max(lenOdd, lenEven);

            //Update the longest palindrome boundaries
            if(maxLen >end - start){
                start = center-(maxLen-1)/2;
                end = center + maxLen/2;
            }
        }
        //return the longest palindromic substring
        return str.substr(start, end - start+1);
    }

private:
    int expandFromCenter(const string& str, int left, int right){
        //Expand while characters match and within bounds
        while(left >= 0 && right < str.length() && str[left]==str[right]){
            left--;
            right++;
        }
        //Return the length of the palindrome
        return right-left-1;
    }  
};

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    Solution obj;
    // string ans = obj.LongPalSubString1(s);
    string ans = obj.LongestPalindrome(s);
    cout<<"Longest Palindromic Substring is: "<<ans;
    return 0;
}