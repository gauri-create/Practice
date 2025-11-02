#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>SetMatrixZeros(vector<vector<int>> &mat, int n, int m){
   //int col[m]={0};->matrix[0][....] 
   //int row[n]={0}; ->matrix[...][0]

   int col0=1;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
            if(mat[i][j]==0){
               // mark the i th row
                mat[i][0]=0;
                //mark j th col
                if(j!=0)
                    mat[0][j]=0;
                else  
                    col0=0;
            }
       }
   }

   for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j]!=0){
                //check for col and row
                if(mat[0][j] == 0 || mat[i][0]==0){
                    mat[i][j]=0;
                }
            }
        }
   }
   if(mat[0][0]==0){
       for(int j=0; j<m; j++) mat[0][j]=0;
   }
   if(col0==0){
        for(int i=0; i<n; i++){
             mat[i][0]=0;
        } 
   }
   return mat;

}

int main(){
int rows, cols;
cout<<"Enter number of rows: ";
cin>>rows;
cout<<"Enter number of columns: ";
cin>>cols;
vector<vector<int>> mat(rows, vector<int>(cols));
cout<<"Enter matrix Element"<<endl;
for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        cin>>mat[i][j];
    }
}
vector<vector<int>>ret = SetMatrixZeros(mat, rows, cols);
cout<<"After setting zero matrix is: "<<endl;
for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
}
return 0;

}