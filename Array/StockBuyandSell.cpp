#include<bits/stdc++.h>
using namespace std;

vector<int> BuyAndSell(vector<int> prices, int n){
    int miniPrice=prices[0];
    int maxProfit=0;
    int cost=0;
    int buyDay=0;
    int sellDay=0;
    for(int i=1; i<n; i++){
        if(prices[i]<miniPrice){
             buyDay=i+1;
        }
        cost=prices[i]-miniPrice;
        if(cost>maxProfit){
            sellDay=i+1;
        }
        maxProfit=max(maxProfit, cost );
        miniPrice=min(miniPrice, prices[i]);
    }
    return {buyDay, prices[buyDay-1], sellDay, prices[sellDay-1], maxProfit};

}

int main(){
    int no=0;
    cout<<"Enter number of days: ";
    cin>>no;
    cout<<"Enter stock prices for "<<no<<" days: "<<endl;
    vector<int> prices(no);
    for(int i=0; i<no; i++){
        cin>>prices[i];   
    }

    vector<int> ret=BuyAndSell(prices, no);
    cout<<"Buy on day: " <<ret[0]<<" at price "<<ret[1]<<endl;
    cout<<"Sell on day: "<<ret[2]<<" at price "<<ret[3]<<endl;
    cout<<"with max profit: "<<ret[4]<<endl;
    return 0;

}