#include<iostream>
using namespace std;

int main(){
    string s;
    cout<<"Enter string";
    cin >> s;

    //precompute
    int hash[256]={0};
    for(int i=0; i<s.size(); i++){
         hash[s[i]]++;
    }
    int q;
    cout<<"Enter number of elements checking: ";
    cin >> q;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<< hash[c]<<endl;
    }
    return 0;
}