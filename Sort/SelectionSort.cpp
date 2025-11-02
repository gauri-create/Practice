#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    int mini, temp;
    for(int i=0; i<n-1; i++ ){
        mini=i;
        for(int j=i;j<=n-1; j++){
            if(arr[j]<arr[mini]) mini = j;
        }
        temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int no;
    cout<<"Enter size of array"<<endl;
    cin>>no;
    int arr[no];
    cout<<"Enter the array element"<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    selectionSort(arr, no);
    cout<<"Sorted array elements by Selection Sort"<<endl;
    for(int i=0; i<no; i++){
        cout<<arr[i]<<endl;
    }

}
