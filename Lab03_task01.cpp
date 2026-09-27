#include<iostream>
using namespace std;

void adjacentSwapper(int arr[], int size){
    int passes = 0;
    int cmp = 0;
    int swp = 0;
    for(int i=0; i<size-1; i++){
        bool isSwapped = false;
        for(int j=0 ; j<size-i-1; j++){
            cmp++;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swp++;
                isSwapped=true;
            }
        }
        passes++;
        if(isSwapped == false){
            break;
        }
    }

    cout<<"Total swaps made: "<<swp<<endl;
    cout<<"Total Comparisons made: "<<cmp<<" (Actual comparisons for worst case: "<<(size*(size-1))/2<<")"<<endl;
    cout<<"Number of passes saved: "<<(size-1-passes)<<endl<<endl;
}

void display(int arr[], int n){
    for(int i =0 ; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    int numofItems;
    cin>>numofItems;
    int trackingNums[numofItems];
    for(int i=0; i<numofItems; i++){
        cin>>trackingNums[i];
    }
    display(trackingNums,numofItems);
    adjacentSwapper(trackingNums,numofItems);
    display(trackingNums,numofItems);

    return 0;
}