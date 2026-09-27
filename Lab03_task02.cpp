#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i =0 ; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void insertionArmSorter(int arr[], int size){
    int totalshifts = 0;
    for(int i = 1; i<size; i++){
        int keyshift = 0;
        int key = arr[i];
        int prev = i-1;
        bool shift = false;
        while(prev>=0 && arr[prev]>key){
            keyshift++;
            totalshifts++;
            shift = true;
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1]=key;
        if(!shift){
            cout<<"Iteration "<<i<<": "<<endl;
            cout<<"key "<<key<<" is in correct position. No shift required"<<endl;
        }
        else{
            cout<<"Iteration "<<i<<": "<<endl;
            cout<<"Key "<<key<<" required "<<keyshift<<" number of shifts."<<endl;
            display(arr, size);

        }
    }
    cout<<"\nTotal shifts: "<<totalshifts<<endl;
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
    insertionArmSorter(trackingNums,numofItems);
    cout<<"After Sorting: "<<endl;
    display(trackingNums,numofItems);

    return 0;
}