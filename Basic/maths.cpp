# include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int DigitCount(int num){
    int cnt=0;
    while(num>0){
        num=num/10;
        cnt++;
    }
    return cnt;
}

// int DigitCount(int num){
//     int cnt =(int)(log10(num)+1);
//     return cnt;
// }

int reverseNum(int num){
    int digit=0;
    int no=0;
    while(num>0){
        digit=num%10;
        no=no*10+digit;
        num=num/10;
    }
    return no;
}

bool palindrome(int num){    
   int rev=0;
    int digit=0;
    int no=num;
    while(no>0){
        digit=no%10;
        rev=rev*10+digit;
        no=no/10;   
    }
    return rev;
    if(num == rev) return true;
    else return false;
}

bool amstrongNum(int num){
    int sum=0;
    int digit=0;
    int no=num;
    int cnt= (num == 0) ? 1 : (int)(log10(num)+1);
    while(no>0){
        digit=no%10;
        sum=sum+pow(digit,cnt);
        no=no/10;   
    }

    if(num == sum) return true;
    else return false;
}

// void PrintAllDivisions(int num){
//     for(int i=1; i<=num; i++ ){
//         if(num%i==0) cout<<i<<" ";
//     }
// }

void PrintAllDivisions(int num){
    vector<int> ls;
    for(int i=1; i<=sqrt(num); i++ ){
        if(num%i==0){
            ls.push_back(i);
            if((num/i)!=i){
                ls.push_back(num/i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for(auto it : ls) cout << it << " ";
}

// bool checkPrime(int num){
//     for(int i=2; i<num; i++){
//         if(num%i==0) return 0;

//     }
//     return 1;
// }

bool checkPrime(int num){
    int cnt=0;
    for(int i=1; i*i<=num; i++){
        if(num%i==0) {
            cnt++;
            if((num/i)!=i)
              cnt++;
        }
        
    }
    if(cnt == 2) return true;
    else return false;

}

// int GCD(int n1, int n2){
//     int GCD=1;
//      for(int i=1; i<=(min(n1,n2));i++){
//         if(n1%i==0 && n2%i==0){
//             GCD = i;
//         }
//      }
//      return GCD;
// }

int GCD (int a, int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    return a;
}

// main function
int main(){
    int num=0;
    int no=0;
    int ret=0;
    cout<<"Enter number"<<endl;
    cin>>num;
    cin>>no;

    // ret=DigitCount(num);
    // cout<<"Number of digits are: "<<ret<<endl;

    // ret=reverseNum(num);
    // cout<<"Reverse number is: "<<ret<<endl;

    // ret = palindrome(num);
    // if(ret==1) cout<<" It is palindrome";
    // else cout<<" It is not palindrome";

    // ret=amstrongNum(num);
    // if(ret==1)cout <<"Number is amstrong";
    // else cout << "Number is not amstrong";

    //PrintAllDivisions(num);

    // ret = checkPrime(num);
    // if(ret ==1 ) cout << "It is prime";
    // else cout << "It is not prime";


    ret = GCD(num, no);
    cout<<"GCD is: "<< ret;

    return 0;
}
