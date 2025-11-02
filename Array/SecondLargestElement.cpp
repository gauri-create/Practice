#include<iostream>
#include<climits>
using namespace std;

int SecondLargest(int arr[], int n){
    int largest=arr[0];
    int secondLargest=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]<largest){
            secondLargest= arr[i];
        }
    }
    return secondLargest;
}

int SecondSmallest(int arr[], int n){
    int smallest=arr[0];
    int secondSmallest= INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }  
        else if(arr[i]<secondSmallest && arr[i] != smallest){
            secondSmallest=arr[i];
        }
    }
    return secondSmallest;
}
int main(){
    int no=0;
    int ret=0;
    cout<<"Enter number of array elements: "<<endl;
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    ret= SecondLargest(arr, no);
    cout<<"Second largest element is: "<<ret<<endl;

    ret= SecondSmallest(arr, no);
    cout<<"Second Largest Element is: "<<ret<<endl;
    return 0;
}