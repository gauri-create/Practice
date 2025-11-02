#include<iostream>
#include<vector>
using namespace std;

int FindElement(int row, int col){
     int res= 1;
     for(int i=0; i<col; i++){
        res=res*(row-i);
        res=res/(i+1);
    }
    return res;
}

void PrintRow(int row){
    long long ans = 1;
    cout<<ans<<" ";
    for(int i=1; i<row; i++){
        ans = ans*(row-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
    cout<<endl;
}

void PrintTriangle(int row){
    for(int i=1; i<=row; i++){
        PrintRow(i);
    }
}

int main(){
    int n;
    cout<<"Enter type of problem to be slve: "<<endl;
    cout<<"1. find element at specific row and column. "<<endl;
    cout<<"2. print specific row. "<<endl;
    cout<<"3. Print entire pascal triagle upto specific row. "<<endl;
    cout<<"Enter choice: ";
    cin>>n;
    switch(n){
        case 1:
            {
                int row, col;
                cout<<"Entire no. of row and col:"<<endl;
                cin>>row;
                cin>>col;
                int ret= FindElement(row-1, col-1);
                cout<<"Element at "<<row<<" row and "<<col<<" col is "<<ret;
            }
           
           break;
        case 2: 
            {
                int row;
                cout<<"Enter the no. of row to be print: "<<endl;
                cin>>row;
                PrintRow(row);
            }
                    break;

        case 3:
            {
                int row;
                cout<<"Enter the no. of row upto which pascal traingle have to print: ";
                cin>>row;
                PrintTriangle(row);
            }
            break;
        default:
             cout<<"Thanks ";
             break;


    }
    return 0;


}