#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
    public:
    bool isNStraightHand(vector<int>& hand, int groupSize){
        if(hand.size() % groupSize != 0) return false;
        map<int, int> freq;
        for(int card: hand) freq[card]++;
        auto it = freq.begin();
        while(it != freq.end()){
            if(it->second == 0){
                it++;
                continue;
            }
            int start = it->first;
            int count = it->second;

            for(int i=0; i<groupSize; i++){
                if(freq[start+i]<count) return false;
                freq[start+i] -= count;
            }
            ++it;
        }
        return true;
    }
};

int main(){
    Solution obj;
    vector<int> hand1 = {1,2,3,6,2,3,4,7,8};
    int groupSize1=3;
    bool ans = obj.isNStraightHand(hand1, groupSize1);
    if(ans==true) cout<<"true";
    else cout<<"false";
    return 0;
}