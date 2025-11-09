#include<iostream>
#include<vector>
using namespace std;

int LowerBound(vector<int> arr, int n, int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        //may be a answer
        if(arr[mid]>=target){
            ans=mid;
            //look for more small indes on left
            high=mid-1;
        }
        else{
            low=mid+1;//look for right
        }
    }
    return ans;
}

int RowWithMax1s(vector<vector<int>> &mat, int n, int m){
    int cnt_max=0;
    int index=-1;
    for(int i=0; i<n; i++){
        int cnt_ones = m-LowerBound(mat[i], m, 1);
        if(cnt_ones>cnt_max){
            cnt_max=cnt_ones;
            index=i;
        }
    }
    return index;
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

    int ret= RowWithMax1s(arr, n, m);
    cout<<"Index of array or row which have maximum number of 1: "<<ret;
    return 0;
}