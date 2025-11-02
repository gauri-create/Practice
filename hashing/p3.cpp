#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int arr[n];
    unordered_map<int, int> mpp;

    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mpp[arr[i]]++;//precomputation

    }

//iterate in the map
for(auto it : mpp){
    cout << it.first <<"->" <<it.second << endl;
}

int q;
cout<<"Enter number: ";
cin>> q;
cout<<"Numbers are"<<endl;
while(q--){
    int number;
    cin >> number;
    //fetch
    
    cout<< mpp[number]<<endl;
}

return 0;
}