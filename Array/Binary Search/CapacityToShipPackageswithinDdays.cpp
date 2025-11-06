#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int findDays(vector<int> &weights, int cap){
    int days=1, load=0;
    for(int i=0; i<weights.size(); i++){
        if(weights[i]+load>cap){
            days+=1;
            load=weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int low=*max_element(weights.begin(), weights.end());
    int high=accumulate(weights.begin(), weights.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int numberOfDays=findDays(weights, mid);
        if(numberOfDays<=d){
           high=mid-1;
        }
        else  
            low=mid+1;
    }
    return low;
}

int main(){
    int no=0;
    int days;
    cout<<"Enter size of array: ";
    cin>>no;
    cout<<"Enter array elements that is weight: "<<endl;
    vector<int> arr(no);
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter number of days: ";
    cin>>days;
    int ret=leastWeightCapacity(arr, days);
    cout<<"The least capacity of the ship is : "<<ret;
    return 0;
}