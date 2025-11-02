#include<iostream>

using namespace std;

// Print the name n times using recursion
void printName( int n){
    if (n==0) return;
    cout<< "Gauri"<<endl;
    printName( n-1);
}

//Print the number from 1 to n using recursion
void printNum(int i,int n){
    if(i>n) return;
    cout<<i<<endl;
    printNum(i+1, n);
}

//Print the number from n to 1 using recursion
void printRevNum(int n){
    if(n==0)return;
    cout<<n<<endl;
    printRevNum(n-1);
}

//Print the number from 1 to n using backtracking
void printBackNum(int i, int no){
    if(i<1) return;
    printBackNum(i-1, no);
    cout<<i<<endl;
}

//Print the number from n to 1 using backtracking
void printRevBackNum(int i, int no){
    if(i>no) return;
    printRevBackNum(i+1, no);
    cout<<i<<endl;
}

//Sum of first N numbers using parameterised way
void printFirstNSum(int i, int sum){
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    printFirstNSum(i-1, sum+i);
}

//Sum of first N numbers using functional way
int printFirstNSum(int n){
   if(n==0) return 0;
   return n + printFirstNSum(n-1);
}

//Factorial using functional way
int Factorial_1(int n){
    if(n==0) return 1;
    return n * Factorial_1(n-1);
}

//Factorial using parameterized way
void Factorial_2(int i, int fact){
    if(i<1){
        cout<<fact<<endl;
        return;
    }
    Factorial_2(i-1, fact*i);
}



int main(){
    int num=0;
    int ret=0;
    cout<<"Enter number: ";
    cin>>num;

    // printName( num);
    // printNum(1, num);
    // printRevNum(num);
    // printBackNum(num, num);
    // printRevBackNum(1, num);
    // printFirstNSum(num, 0);

    // ret = printFirstNSum(num);
    // cout<<ret<<endl;

    // ret = Factorial_1(num);
    // cout<<ret<<endl;

    Factorial_2(num, 1);

    return 0;
}