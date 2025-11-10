#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
    //brute
        bool RotateString1(string s, string goal){
        
            if(s.length()!=goal.length()) return false;
            int i=0;
            while(s[0]!=goal[i]){
                 i++;
            }
            int j=0, k=0;
            while(k<s.length()){
               if(j==s.length())j=0;
               if(i==goal.length())i=0;
               if(s[j]!=goal[i]) return false;
               i++;
               j++;
               k++;
            }
            return true;
        }
    //optimal
        bool RotateString2(string s, string goal){
            if(s.length()!=goal.length()) return false;

            string temp =s+s;
            if(temp.find(goal)!=string::npos) return true;
            return false;
        }

};

int main(){
    string s, goal;
    cout<<"Enter 1st string:"<<endl;
    cin>>s;
    cout<<"Enter 2nd string:"<<endl;
    cin>>goal;
    Solution obj;
    // bool ans = obj.RotateString1(s, goal);
    bool ans = obj.RotateString2(s, goal);
    if(ans==1) cout<<"One string is rotation of another";
    else cout<<"One string is not rotation of another";
    return 0;
}