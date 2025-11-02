#include<iostream>
using namespace std;

//Brute
int OccurOnes(int arr[], int no){
    for(int i=0; i<no; i++){
        int num=arr[i];
        int cnt=0;
        for(int j=0; j<no; j++){
            if(arr[j]==num){
                cnt++;
            }
        }
        if(cnt==1) return num;
    }
}

//better
int OccurOnes1(int arr[], int no){
    int n=arr[no-1];
    int maxi =arr[0];
    for(int i=0; i<no; i++){
        maxi=max(maxi, arr[i]);
    }
    int hash[maxi]={0};
    for(int i=0; i<no; i++){
        hash[arr[i]]++;
    }
    for(int i=0; i<no; i++){
        if(hash[arr[i]]==1) return arr[i];
    }
}

//optimal
int OccurOnes2(int arr[], int no){
    int XOR=0;
    for(int i=0; i<no;i++){
        XOR = XOR^arr[i];
    }
    return XOR;
}

int main(){ 
    int no=0;
    cout<<"Enter number of arry elements: ";
    cin>>no;
    int arr[no];
    cout<<"Enter arry elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    // int ret = OccurOnes(arr, no);
    // int ret = OccurOnes1(arr, no);
    int ret = OccurOnes2(arr, no);
    cout<<"The number occurs 1's while other occurs twice in array: "<< ret<<endl;
    return 0;
}