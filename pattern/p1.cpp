#include<iostream>
using namespace std;

void pattern1(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
                cout << "* ";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
                cout << j << " ";
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
                cout << i << " ";
        }
        cout<<endl;
    }
}

// void pattern5(int n){
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=(n-i+1);j++){
//                cout << "* ";
//       }
//       cout << endl;
//     }
// }

void pattern5(int n){
    for(int i=n; i>0; i--){
        for(int j=i; j>0; j--){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(n-i+1);j++){
               cout << j << " ";
      }
      cout << endl;
    }
}

void pattern7(int n){
    for(int i=1; i<=n; i++){
        //spaces
        for(int j=1; j<=(n-i); j++){
            cout << "  ";
        }

        //stars
        for(int j=1; j<=(2*i-1); j++){
            cout << "* ";
        }

        //spaces
        for(int j=1; j<=(n-1); j++){
            cout << "  ";
        }
        cout << endl;
    }
}

void pattern8(int n){
    for(int i=0; i<n; i++){
        //spaces
        for(int j=0; j<i; j++){
            cout << "  ";
        }
       

        //stars
        for(int j=0; j< 2*n-(2*i+1); j++){
            cout << "* ";
        }

        //spaces
         for(int j=0; j<=i; j++){
            cout << "  ";
        }
        cout << endl;
    }
}

void pattern9(int n)
{
    for(int i=1; i <= n; i++ ){
        //spaces
        for(int j=1;j<=(n-i);j++){
            cout<<" ";
        }
        //stars
        for(int j=1; j<=(2*i-1); j++){
            cout<<"*";
        }
        //spaces
        for(int j=1; j<=(n-1);j++){
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<n ; i++){
        for(int j=1;j<=i; j++){
            cout<<" ";
        }
        for(int j=1; j<(2*n-2*i); j++){
            cout<<"*";
        }
        for(int j=1; j<=i;j++ ){
            cout<<" ";
        }
        cout<< endl;
    }
    
}

void pattern10(int n){
    for(int i=1; i<=2*n-1; i++){
        int stars=i;
        if(i>n) stars =2*n-i;
        for(int j=1; j<=stars; j++){
            cout << "*";
        }
        cout<<endl;
    }
}

void pattern11(int n){
    int start = 1;
    for(int i=0; i<n; i++){
        if(i%2==0) start =1;
        else start=0;
        for(int j=0; j<=i; j++){
            cout <<start;
            start =1- start;
        } 
        cout << endl;
    }
}

void pattern12(int n){
    for(int i=1; i<=n; i++){
        //right angled triangle
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        //space
        for(int j=1; j<=(2*(n-i));j++){
            cout<<" ";
        }
        //mirrored right angled triangle
        for(int j=i; j>=1; j--){
            cout<<(j);
        }
        cout<<endl;
    }
}

void pattern13(int n){
    static int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
        
    }
}

void  pattern14(int n){
    for(int i=0; i<n;i++){
        char ch='A';
        for(int j=0; j<=i; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

void pattern15(int n){
    for(int i=0; i<n ; i++){
        char ch='A';
        for(int j=0;j<n-i;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

void pattern16(int n){
    char ch='A';
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<ch<<" ";
        }
        cout<<endl;
        ch++;

    }
}

void pattern17(int n){
    for(int i=1; i<=n; i++){
        //spaces
        for(int j=1; j<=(n-i); j++){
            cout << "  ";
        }
                //stars
        char ch='A';
        int breakpoint = (2*i+1)/2;
        for(int j=1; j<=(2*i-1); j++){
                cout<<ch<<" ";
            if(j >=breakpoint) ch--;
            else ch++;
        }

        //spaces
        for(int j=1; j<=(n-1); j++){
            cout << "  ";
        }
        cout << endl;
    }
}

void pattern18(int n){
    for(int i=1; i<=n; i++){
        char ch='A'+n-i;
        for(int j=0; j<i; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}


void pattern19(int n){
    //upper portion
    for(int i=0; i<n; i++){
       // inverted right angled triangle
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=1; j<=i*2; j++){
            cout<<" ";
        }
        //mirrored inverted right angled triangle
        for(int j=0; j<n-i;j++){
            cout<<"*";
        }
       cout<<endl;
    }
    //lower portion
    for(int i=1; i<=n; i++){
        //right angled trianle
        for(int j=0; j<i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=0;j<2*(n-i);j++ ){
            cout<<" ";
        }
        //mirrored right angled triangle
        for(int j=0; j<i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern20(int n){
    //upper portion
    for(int i=1; i<n; i++){
        //right angled trianle
        for(int j=0; j<i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=0;j<2*(n-i);j++ ){
            cout<<" ";
        }
        //mirrored right angled triangle
        for(int j=0; j<i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    //lower portion
    for(int i=0; i<n; i++){
       // inverted right angled triangle
        for(int j=0; j<n-i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=1; j<=i*2; j++){
            cout<<" ";
        }
        //mirrored inverted right angled triangle
        for(int j=0; j<n-i;j++){
            cout<<"*";
        }
       cout<<endl;
    }
}

void  pattern21(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 ||j==1||i==n||j==n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        //pattern1(n);
        //pattern2(n);
        //pattern3(n);
        //pattern4(n);
        //pattern5(n);
        //pattern6(n);
        //pattern7(n);
        //pattern8(n);
        //pattern9(n);
        //pattern10(n);
        //pattern11(n);
        //pattern12(n);
        // pattern13(n);
        // pattern14(n);
        // pattern15(n);
        // pattern16(n);
        // pattern17(n);
        // pattern18(n);
        // pattern19(n);
        // pattern20(n);
        pattern21(n);

        if(i!= t-1) cout << endl;
    }
    return 0;
}
