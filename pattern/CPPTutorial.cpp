#include<iostream>
#include<typeinfo>
using namespace std;
int main(){
    //int
    int num=3;
    cout << num <<endl;

    //float
    int no=23.332;
    cout << no <<endl;

    //double
    double n=232.33;
    cout << n << endl;

    //char
    char ch='a';
    cout << ch << endl;

    //bool
    bool isTrue = true;
    cout << isTrue << endl;

    //array
    int arr[5]={12,43,23,34,53};
    for(int i=0; i<5; i++){
        cout << arr[i] <<" ";
    }
    cout <<endl;

    //pointer
    int* ptr =&num;
    cout <<"num is: "<<num<< "   ptr is: "<< ptr << "   *ptr is: "<<*ptr<<endl;

    //


    return 0;
}