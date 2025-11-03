#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Approach 1 nested loop
vector<int> MissedRepeat1(vector<int> arr){
    int n=arr.size();
    int repeat=-1, missed=-1;

    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[j]==i){
                cnt++;
            }
            
        }
        if(cnt==2) repeat=i;
        else if(cnt==0) missed=i;
        if(repeat!=-1 && missed!=-1) break;
    }
    return {repeat, missed};

}


//Approach 2 Hashmap
vector<int> MissedRepeat2(vector<int> arr){
    int n=arr.size();
    int hash[n+1]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    int repeat=-1, missed=-1;
    for(int i=1; i<=n; i++){
        if(hash[i]==2) repeat=i;
        else if(hash[i]==0) missed=i;

        if(repeat !=-1 && missed !=-1){
            break;
        }
    }
            return { repeat, missed};

}

//Approach 3  Math
vector<int> MissedRepeat3(vector<int> arr){
    long long n=arr.size();
    //s-sn=x-y
    //s2-s2n
    long long SN=(n*(n+1)/2);
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0, S2=0;
    for(int i=0; i<n;i++){
        S += arr[i];
        S2 += (long long)arr[i]*(long long)arr[i];
    }
    long long val1=S-SN;//x-y
    long long val2=S2-S2N;//x^2-y^2
    val2=val2/val1;//x+y
    long long x= (val1 + val2)/2;//repeated number
    long long y=x-val1;//missing number
    return {(int)x, (int)y};
}

//Approach 4  XOX
vector<int> MissedRepeat4(vector<int>arr){
    long long n=arr.size();
    int xr=0;
    //Step1: XOR all elements and all numbers 1...n
    for(int i=0; i<n; i++){
        xr=xr^arr[i];
        xr= xr ^(i+1);
    }
    //Step2: Get rightmost set bit mask
    int number=xr & ~(xr-1);

    int zero = 0;
    int one=0;
    for(int i=0; i<n; i++){
        //part of 1 club
        if((arr[i]&(number))){
            one=one^arr[i];
        }
        //zero  th club
        else{
        zero= zero^arr[i];
        }
    }

    for(int i=1; i<=n; i++){
        //part of 1 club
        if((i & (number))!=0){
           one=one^i;
        }
        //eroth club
        else{
            zero=zero^i; 
        }
    
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        if(arr[i]==zero) cnt++;
    }
    if(cnt == 2) return {zero, one};
    return {one, zero};


}

int main(){
    int no=0;
    cout<<"Enter array size: ";
    cin>> no;
    cout<<"Enter array element: "<<endl;
    vector<int> arr(no);
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }

    // vector<int> ret=MissedRepeat1(arr);
    // vector<int> ret=MissedRepeat2(arr);
    // vector<int> ret=MissedRepeat3(arr);
    vector<int> ret=MissedRepeat4(arr);

    cout<<"The repeatedvaule is "<<ret[0]<<" and missed value is "<<ret[1];
    return 0;
}