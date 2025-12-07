#include<iostream>
using namespace std;

class Solution{
    public:
    int CountBitsToBeFlipped(int start, int goal){
        int ans=start^goal;
        int cnt=0;
        for(int i=-0;i<31; i++){
            if(ans&(1<<i)){
                cnt++;
            }
        }
        return cnt;
    }

};

int main(){
     int start=10, goal=7;
     Solution obj;
     int ans=obj.CountBitsToBeFlipped(start, goal);
     cout<<ans<<endl;
     return 0;
}