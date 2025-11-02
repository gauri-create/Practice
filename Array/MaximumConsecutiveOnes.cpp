#include<iostream>
using namespace std;

int MaxCons(int arr[], int no){
    int maxi=0;
    int cnt= 0;
    for(int i=0; i<no; i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi, cnt);
        }
        else
        cnt=0;
    }
    return maxi;
}

int main(){
    int no;
    cout<<"Enter number of array elements: ";
    cin>>no;
    int arr[no];
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    int ret = MaxCons(arr, no);
    cout<<"Maximum consecutive ones is: "<<ret;
    return 0;
}