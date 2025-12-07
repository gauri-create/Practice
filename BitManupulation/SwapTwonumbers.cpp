#include<iostream>
using namespace std;

class Solution{
    public:
    void swap(int &a, int &b) {
        a=a^b;
        b=a^b;
        a=a^b;
    }
};

int main(){
    Solution obj;
    int a=5, b=6;
    obj.swap(a, b);
    cout<<a<<" "<<b;
    return 0;
}