#include<iostream>
using namespace std;

int Search(int arr[], int no, int num){
    for(int i=0; i<no; i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}

int main(){
    int no=0;
    int num=0;
    cout<<"Enter number of array elements:";
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: ";
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter number to be searched:";
    cin>>num;
    int ret=Search(arr, no, num);
    if(ret == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index: "<<ret;
    }
}