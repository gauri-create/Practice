#include<iostream>

using namespace std;

int fibonaccie(int n){
    if(n<=1) return n;
    int last =fibonaccie(n-1);
    int secondLast = fibonaccie(n-2);
    return last+secondLast;
}

int main(){
    int no=0;
    cout<<"Enter number:  ";
    cin >> no;
    int ret = fibonaccie(no);
    cout<<ret;
}