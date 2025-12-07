#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    void backtrack(string num, int target, int pos, long long currVal, long long prevVal, string expr, vector<string>&result){
        if(pos==num.size()){
            if(currVal == target){
                result.push_back(expr);            
            }
            return;
        }

        for(int i= pos; i< num.size(); i++){
            if(i>pos &&  num[pos]=='0') break;

            string part = num.substr(pos, i-pos+1);
            long long val = stoll(part);

            if(pos==0){
                backtrack(num, target, i+1, val, val, part, result);
            }
            else{
                backtrack(num, target, i+1, currVal+val, val, expr+"+"+part, result);
                backtrack(num, target, i+1,currVal-val, -val, expr+"-"+part, result);
                backtrack(num, target, i+1, currVal-prevVal+prevVal*val, prevVal*val, expr+"*"+part, result);
            }
        }
    }

    public:
    vector<string> addOperators(string s, int target) {
        vector<string>result;
        backtrack(s, target, 0,0,0,"",result);
        return result;
    }

   
};

int main(){
    string num="123";
    int target=6;
    Solution obj;
    vector<string> ans= obj.addOperators( num, target);
    for(auto i: ans){
        cout<<i<<endl;
        
    }
    return 0;
}