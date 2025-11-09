#include<iostream>
#include<vector>
using namespace std;

//Brute
bool SearchIn2DMatrix1(vector<vector<int>> &mat, int n, int m, int target){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==target) return 1;
        }
    }
    return 0;
}

//Better
bool BS(vector<int> arr, int t){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==t) return 1;
        else if(arr[mid]<t) low=mid+1;
        else high=high-1;
    }
    return 0;
}

bool SearchIn2DMatrix2(vector<vector<int>> &mat, int n, int m, int target){

    for(int i=0; i<n; i++){
        if(mat[i][0]<=target && target<=mat[i][m-1]){
            int ind= BS(mat[i], target);
            if(ind!=-1){
                return 1;
            }
        }
    }
    return 0;
}

//Optimal
bool SearchIn2DMatrix3(vector<vector<int>> &mat, int n, int m, int target){
    int row=0;
    int col=m-1;
    while(row<n && col>=0){
    if(mat[row][col]==target) return 1;
    else if(mat[row][col]<target) row++;
    else col--;
    }
    return 0;
}



int main(){
    int n,  m, target;
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

    cout<<"Enter target: ";
    cin>>target;

    // int ret= SearchIn2DMatrix1(arr, n, m, target);
    int ret= SearchIn2DMatrix2(arr, n, m, target);
    // int ret= SearchIn2DMatrix3(arr, n, m, target);

    if(ret==1)
        cout<<"Target is found ";
    else
        cout<<"Target is not found";
    return 0;
}