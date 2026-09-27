#include<iostream>
#include<cmath>
using namespace std;

int midpointSplitSearch(int arr[], int size, int targetID){ //sorted list

    //check if array is sorted
    for(int i=0 ; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            cout<<"Error: Conveyor is unsorted. Search aborted."<<endl;
            return -1;
        }
    }

    //search for targetid
    int high = size-1;
    int low = 0;
    int steps=0;

    while(low<=high){
        int mid = low + (high-low)/2;
        steps++;

        cout<<"LOW | MID | HIGH"<<endl;
        cout<<"  "<<low<<" |  "<<mid<<"  |  "<<high<<endl;
        if(arr[mid] == targetID){
            cout<<"Target Index: ";
            return mid;
        }
        else if(targetID > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        cout<<"Remaining Search Percentage:" <<(double)(high - low + 1)/size *100<<"% "<<endl;
        cout<<"Steps taken so far | theoretical max steps: "<<steps<<" | "<<floor(log2(size)) + 1<<endl<<endl;
    }
    cout<<"Target Index: ";
    return -1;
}

int main(){
    int numofItems;
    cin>>numofItems;
    int trackingNums[numofItems];
    for(int i=0; i<numofItems; i++){
        cin>>trackingNums[i];
    }
    int targetID;
    cout<<"Target ID? ";
    cin>>targetID;

    cout<<midpointSplitSearch(trackingNums,numofItems, targetID);

    return 0;
}