#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i =0 ; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void diminishingDistanceScanner(int arr[], int size){
    for(int gap = size/2; gap>=1; gap=gap/2){
        cout<<"Gap: "<<gap<<" \nGap Percentage: "<<(double)gap/size *100<<"% \n"<<endl;
        int cmp =0;
        int swaps = 0;
        for(int i=gap; i<size ;i++){
            for(int j=i-gap; j>=0 ;j = j-gap){
                cmp++;
                if(arr[j+gap]>arr[j]){
                    break;
                }
                else{
                    swaps++;
                    swap(arr[j+gap],arr[j]);
                }
            }
        }
        cout<<"Number of comparisons in gap = "<<gap<<" : "<<cmp<<endl;
        cout<<"Number of swaps in gap = "<<gap<<" : "<<swaps<<endl;
    }
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
    diminishingDistanceScanner(trackingNums,numofItems);
    cout<<"After Sorting: "<<endl;
    display(trackingNums,numofItems);

    return 0;
}