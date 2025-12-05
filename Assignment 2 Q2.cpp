/*
Q2. Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
the adjacent elements if they are in wrong order. Code the Bubble sort with the
following elements:
64 34 25 12 22 11 90
*/

#include <iostream>
using namespace std;

int main(){

    int arr[]={641,34,25,12,332,11,96};
    int size=sizeof(arr)/sizeof(arr[0]);
    int temp=0;

    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"Sorted array is as follows: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }

    return 0;
}