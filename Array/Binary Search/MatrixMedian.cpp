#include<iostream>
#include<vector>
// #include<algorithm>
// #include<cmath>
using namespace std;


//Optimal
//Upper bound
int UpperBound(vector<int> arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low <= high){
       int mid=(low+high)/2;
       if(arr[mid]>target) {
           ans=mid;
           high=mid-1;
       }
       else{
           low=mid+1;
       }
    
    }
    return ans;
}
//BlackBox
int CountSmallEqual(vector<vector<int>> &matrix, int n, int m, int x){
    int cnt=0;
    for(int i=0; i<n; i++){
        cnt += UpperBound(matrix[i], m, x);
    }
    return cnt;
}

// Find median index
int Median (vector<vector<int>> &matrix, int n, int m){
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0; i<n;i++){
        low=min(low,matrix[i][0]);
        high=max(high, matrix[i][m-1]);
    }
    int req=(n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int smallEqual=CountSmallEqual(matrix, n, m, mid);
        if(smallEqual <= req) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main(){
    int n,  m;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;

    vector<vector<int>> arr(n,vector<int>(m));
    cout<<"Enter array element: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> arr[i][j];
        }
    }

    

    int ret= Median(arr, n, m);
    cout<<"Median is "<<ret;
    return 0;
}