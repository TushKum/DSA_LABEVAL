/*
Q1. Implement the Binary search algorithm regarded as a fast search algorithm with
run-time complexity of Ο(log n) in comparison to the Linear Search.
*/

#include <iostream>
using namespace std;

int main(){

    int num_to_find;
    int arr[]={5,10,12,32,45,87};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter the number to find";
    cin>>num_to_find;

    int low=0,high=size-1,mid=0;
    bool found=false;

    while(low<high){
        mid=(high+low)/2;
        if(arr[mid]==num_to_find){
            cout<<"The desired number at position:"<<mid;
            found=true;
            break;
        }
        else if(arr[mid]>=num_to_find){
            high=mid-1;
        }
        else if(arr[mid]<=num_to_find){
            low=mid+1;
        }
    }
    if(found!=true){
        cout<<"Number not found";
    }

    return 0;
}