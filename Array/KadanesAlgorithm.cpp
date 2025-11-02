//Kadane's algorithm or Maximum Subarray problem
#include <bits/stdc++.h>
using namespace std;

long long MaxSubArraySum1(vector<int> arr, int n){
    long long maxi = LONG_MIN;
    for(int i=0; i<n; i++){
       for(int j=i; j<n; j++){
    
            long long sum=0;
            for(int k=i; k<j; k++){
                sum+=arr[k];
                maxi=max(maxi, sum);
            }
        }    
    }
    return maxi;
}

long long MaxSubArraySum2(vector<int> arr, int n){
    long long maxi = LONG_MIN;
    for(int i=0; i<n; i++){
        long long sum=0;

        for(int j=i; j<n; j++){
            sum+=arr[j];
            maxi=max(maxi, sum);
            
        }    
    }
    return maxi;
}

long long MaxSubArraySum3(vector<int> arr, int n){
   long long sum = 0, maxi = LONG_MIN;
   for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

vector<int> MaxSubArraySum4(vector<int> arr, int n){
   long long sum = 0, maxi = LONG_MIN;
   int arrStart=-1, arrEnd=-1, start;
   for(int i=0; i<n; i++){
       if(sum==0)start=i;
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            arrStart=start;
            arrEnd=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    vector<int> result;
         for(int i=arrStart; i<=arrEnd; i++){
         result.push_back(arr[i]);
        }
    
    return result;
}

int main(){

    int no=0;
    cout<<"Enter size of array: ";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }

    // long long ret=MaxSubArraySum1(arr, no);
    long long ret=MaxSubArraySum2(arr, no);
    // long long ret=MaxSubArraySum3(arr, no);
    cout<<"Maximum subarray sum is "<<ret<<endl;

    // vector<int> ret=MaxSubArraySum4(arr, no);
    // cout<<"Maximum subarray elements are; ";
    // for(auto it: ret){
    //     cout<<it<<" ";
    // }

    return 0;
}