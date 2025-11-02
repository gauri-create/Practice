#include<iostream>

using namespace std;

// int arr[];
int hashh[1000000];
int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


//precomputation

for(int i=0; i<n; i++){
    hashh[arr[i]] +=1;
}

int q;
cout<<"Enter number: ";
cin>> q;
cout<<"Numbers are"<<endl;
while(q--){
    int number;
    cin >> number;
    //fetch
    
    cout<< hashh[number]<<endl;
}

return 0;
}