#include<iostream>
#include<set>
using namespace  std;
void RemoveDuplicateB(int arr[], int no){
    set<int> st;
    int index = 0;
    for(int i=0; i<no; i++){
        st.insert(arr[i]);
        arr[i]=0;
    }
    for(auto it : st){
        arr[index]=it;
        index++;
    }
    cout<<"Array after removing duplicates:"<<endl;
    for(int i=0; i<no; i++){
        cout<<arr[i];
    }

}

void RemoveDuplicateO(int arr[],int no){
    int  i=0;
    for(int j=1; j<no; j++ ){
        if(arr[i]!=arr[i]){
            arr[i+1]=arr[j];
        }
    }
    cout<<"Array after removing di=uplicates: ";
    for(int i=0; i<no; i++){
        cout<<arr[i]<<endl;
    }
}
main(){
    int no=0;
    cout<<"Enter Number of array elements: ";
    cin>>no;
    int arr[no]={0};
    cout<<"Enter array elements: ";
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    RemoveDuplicateB(arr, no);
    RemoveDuplicateO(arr, no);
    return 0;
} 