#include<iostream>
using namespace std;
// check if ith bit is set or not
class Solution{
    public:
    //brute force approach
    bool checkIthBit(int n, int i) {
        string result="";
        while(n>0){
            if(n%2==1) result+='1';
            else result+='0';
            n=n/2;
        }
        if(result[i]=='1') return true;
        return false;
    }

    //optimal approach
    bool checkIthBitOptimal(int n, int i){
        int mask = 1<<i;
        if((n & mask) !=0) return true;
        return false;
    }
};

class Solution2{
    public:
    int setithBit(int n, int  i){
        int mask=1<<i;
        return n|mask;
    }

    int clearIthBit(int n, int i){
        int mask = 1<<i;
        return (n& ~mask);
    }

    int toggleIthBit(int n, int i){
        int mask = 1<<i;
        return (n^mask);
    }

    int RemoveLastSetBit(int n){
        return n & (n-1);
    }

    bool CheckifPowerOf2(int n){
        if(n<=0) return false;
        return (n & (n-1))==0;
    }
//brute
    int CountSetBits(int n){
        int cnt=0;
        while(n>1){
            if(n%2==1) cnt++;
            n=n/2;
            if(n==1)cnt++;
        }
        return cnt;
    }

//optimal
    int CountSetBits1(int n){
        int cnt=0;
        while(n>1){
            cnt+=(n&1);
            n=n>>1;
            if(n==1)cnt++;
        }
        return cnt;
    }

    int CountSetBits2(int n){
        int cnt=0;
        while(n>1){
            n=n &(n-1);
            cnt++;
        }
        return cnt;
    }
};


int main(){
    int n=14, i=2;
    Solution obj;
    // bool ans= obj.checkIthBit(n, i);
    // if(ans==true) cout<<"True"<<endl;
    // else cout<<"False"<<endl;

    // bool ans2=obj.checkIthBitOptimal(n,i);
    // if(ans2==true) cout<<"True"<<endl;
    // else cout<<"False"<<endl;

    Solution2 obj2;

    // int ans3= obj2.setithBit(n, i);
    // cout<<ans3<<endl;

    // int ans4= obj2.clearIthBit(n, i);
    // cout<<ans4<<endl;

    // int ans5= obj2.toggleIthBit(n, i);
    // cout<<ans5<<endl; 

    // int ans6 = obj2.RemoveLastSetBit(n);
    // cout<<ans6<<endl;

    // bool ans7 = obj2.CheckifPowerOf2(n);
    // if(ans7==true) cout<<"Power of 2 "<<endl;
    // else cout<<"Not a power of 2"<<endl;

    // int ans8 = obj2.CountSetBits(n);
    // int ans8 = obj2.CountSetBits1(n);
    int ans8 = obj2.CountSetBits2(n);
    cout<<ans8<<endl;

    return 0;
}
