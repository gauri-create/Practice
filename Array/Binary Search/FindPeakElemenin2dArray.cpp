#include<iostream>
#include<vector>
using namespace std;


//Optimal

// Find peak index

int FindMaxIndex(vector<vector<int>> &mat ,int n, int col){
    int maxValue=INT_MIN;
    int index=-1;
    for(int i=0; i<n; i++){
        if(mat[i][col]>maxValue){
            maxValue=mat[i][col];
            index=i;
        }
    }
    return index;

}
vector<int> FindPeak(vector<vector<int>> &mat, int n, int m){
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int maxRowIndex=FindMaxIndex(mat, n, mid);
        int left= mid-1 >= 0 ? mat[maxRowIndex][mid-1]:-1;
        int right=mid+1 <m ? mat[maxRowIndex][mid+1]: -1;
        if(mat[maxRowIndex][mid] > left&& mat[maxRowIndex][mid]>right){
             return {maxRowIndex, mid};
        }
        else if(mat[maxRowIndex][mid]<left)  high = mid-1;
        else low=mid+1;

    }
    
    return {-1,-1};
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

    

    vector<int> ret= FindPeak(arr, n, m);
    cout<<"Peak element is found at "<<ret[0]<<" row and "<<ret[1]<<"column.";
    return 0;
}