#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i =0 ; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void minimalSwapCrane(int arr[], int size){
    int actualswaps = 0;
    int skippedswaps = 0;
    int cmp = 0;
    for(int i = 0; i<size-1; i++){
        int smallestIdx = i;
        for(int j = i+1 ; j<size; j++){
            cmp++;
            if(arr[smallestIdx]>arr[j]){
                smallestIdx = j;
            }
        }
        swap(arr[smallestIdx],arr[i]);
        if(smallestIdx == i){
            skippedswaps++;
        }
        else
        actualswaps++;
    }

    cout<<"Total swaps: "<<actualswaps<<endl;
    cout<<"Skipped swaps: "<<skippedswaps<<endl;
    cout<<"Swap to Comparison Ratio: "<<(double)actualswaps/cmp *100<<"%"<<endl;
    cout<<"Total Comparisons: "<<(size*(size-1))/2<<endl;
}


int main(){
    int numofItems;
    cin>>numofItems;
    int trackingNums[numofItems];
    for(int i=0; i<numofItems; i++){
        cin>>trackingNums[i];
    }
    cout<<"Before Sorting: "<<endl;
    display(trackingNums,numofItems);
    minimalSwapCrane(trackingNums,numofItems);
    cout<<"After Sorting: "<<endl;
    display(trackingNums,numofItems);

    return 0;
}