#include<iostream>
using namespace std;

void MoveZero(int arr[], int no){
    int temp[no]={0};
    for(int i=0, k=0; i<no; i++){
        if(arr[i]!=0){
            temp[k]=arr[i];
            k++;
        }
    }
    for(int i=0; i<no; i++){
        arr[i]=temp[i];
    }
}

void MoveZero1(int arr[],  int no){
    int j=-1;
    for(int i=0; i<no; i++ ){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1; i<no; i++){
        if(arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    int no=0;
    cout<<"Enter number of array elements: ";
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: ";
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    // MoveZero(arr, no);
    MoveZero1(arr, no);
    cout<<"Array after moving zero at end: ";
    for(int i=0; i<no; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}