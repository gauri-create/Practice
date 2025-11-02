#include<iostream>
using namespace std;

bool CheckArray(int arr[], int no){
    for(int i=1; i<no; i++){
        if(arr[i]<arr[i-1]) 
        return 0;
    }
    
    return 1;
}

int main(){
    int no=0;
    cout<<"Enter Number of array elements: ";
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: ";
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    int ret= CheckArray(arr, no);
    if(ret==1)
    cout<<"Array is sorted";
    else
    cout<<"Array is not sorted";
}