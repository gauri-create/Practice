#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;

class Solution{
    public:
    bool IsomorphicString1(string &s, string &t){
        if(s.length()!=t.length()){
            return false;
        }
        //create a hashmap to store character mappings
        unordered_map<char,char> s_to_t;
        unordered_map<char,char>t_to_s;

        for(int i=0; i<s.length(); i++){
            char cs =s[i] ;
            char ct =t[i];

            //check mapping s->t
            if(s_to_t.count(cs)){
                if(s_to_t[cs]!=ct) return false;
            }
            else{
                s_to_t[cs]=ct;
            }

            //check mapping t->s
            if(t_to_s.count(ct)){
                if(t_to_s[ct]!=cs) return false;
            }
            else{
                t_to_s[ct]=cs;
            }
            
        }
        return true;
    }

    bool IsomorphicString2(string s, string t){
        if(s.length()!=t.length()) return false;

        int s_map[256] = {0};
        int t_map[256] = {0};

        for(int i=0; i<s.length(); i++){
            char cs=s[i], ct=t[i];

            if(s_map[cs] == 0 && t_map[ct] == 0){
                s_map[cs]= ct;
                t_map[ct] = cs;
            }
            else if(s_map[cs] != ct || t_map[ct]!= cs){
                return false;
            }
        }
        return true;
        
    }

};

int main(){

    string s, t;
    cout<<"Enter first string"<<endl;
    cin>>s;
    cout<<"Enter second string"<<endl;
    cin>>t;

    Solution obj;
    // bool ans = obj.IsomorphicString1(s, t);
    bool ans = obj.IsomorphicString2(s, t);

    if(ans==1) cout<<"String is isomorphic";
    else cout<<"String is not isomorphic";
    return 0;
}