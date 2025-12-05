/*
7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an
inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to
count the number of inversions in an array.
*/

#include <iostream>
using namespace std;

int main(){

    int num;
    cout<<"Enter the no. of elements of array: ";
    cin>>num;
    int arr[num];

    cout<<"\nEnter elements of the array\n";
    for (int i=0;i<num;i++){
        cout<<": ";
        cin>>arr[i];
    }

    int inversion_count=0;
    for (int i=0;i<num;i++){
        for (int j=i+1;j<num;j++){
            if(arr[i]>arr[j]){
                inversion_count+=1;
            }
        }
    }
    cout<<"Inversion count: "<<inversion_count;

    return 0;
}