/*
5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix
*/

#include <iostream>
using namespace std;

int main(){

    //(a) Diagonal Matrix.
    int size_diagonal;

    cout<<"Enter the size of the matirx";
    cin>>size_diagonal;

    int arr[size_diagonal],num;

    cout<<"Enter matrix elelemtns";
    for (int i=0;i<size_diagonal;i++){
        cout<<": ";
        cin>>num;
        arr[i]=num;
    }

    for (int i=0;i<size_diagonal;i++){
        cout<<"|";
        for (int j=0;j<size_diagonal;j++){
            if(i==j){
                cout<<arr[i]<<" ";
            }
            else{
            cout<<"0 ";
            }
        }
        cout<<"|\n";
    }

    //(b) Tri-diagonal Matrix.

    int size_trigonal;

    cout<<"Enter the size of the matirx: ";
    cin>>size_trigonal;

    int arr2[3*size_trigonal-2];

    cout<<"Enter matrix elelemtns: "; 
    for(int i=0;i<3*size_trigonal-2;i++){
        cout<<": ";
        cin>>arr2[i];
    }

    int count=0;
    for (int i=0;i<size_trigonal;i++){
        cout<<"|";
        for(int j=0;j<size_trigonal;j++){
            if(abs(i-j)<=1){
                cout<<arr2[count]<<" ";
                count+=1;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"|\n";
    }

    //(c) Lower triangular Matrix.

    cout<<"Enter the size of matrix: ";
    int size_lower;
    cin>>size_lower;

    int arr3[size_lower*(size_lower+1)/2];

    cout<<"Enter the non zero elements row wise: ";
    for(int i=0;i<size_lower*(size_lower+1)/2;i++){
        cout<<": ";
        cin>>arr3[i];
    }
    
    count=0;
    for(int i=0;i<size_lower;i++){
        cout<<"|";
        for(int j=0;j<size_lower;j++){
            if(i-j>=0){
                cout<<arr3[count]<<" ";
                count+=1;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"|\n";
    }

    //(c) Upper triangular Matrix.

    cout<<"Enter the size of matrix: ";
    int size_upper;
    cin>>size_upper;

    int arr4[size_upper*(size_upper+1)/2];

    cout<<"Enter the non zero elements row wise";
    for(int i=0;i<size_upper*(size_upper+1)/2;i++){
        cout<<": ";
        cin>>arr4[i];
    }
    
    count=0;
    for(int i=0;i<size_upper;i++){
        cout<<"|";
        for(int j=0;j<size_upper;j++){
            if(j-i>=0){
                cout<<arr4[count]<<" ";
                count+=1;
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<"|\n";
    }

    //(e) Symmetric Matrix

    cout<<"Enter the size of matrix: ";
    int size_symmetric;
    cin>>size_symmetric;

    int arr5[size_symmetric*(size_symmetric+1)/2];

    cout<<"Enter the non zero elements row wise";
    for(int i=0;i<size_symmetric*(size_symmetric+1)/2;i++){
        cout<<": ";
        cin>>arr5[i];
    }
    
    for(int i=0;i<size_symmetric;i++){
        cout<<"|";
        for(int j=0;j<size_symmetric;j++){
            int count1;
            if(j-i>=0){
                count1=i*size_symmetric-(i*(i-1))/2+(j-i);
            }
            else{
                count1=j*size_symmetric-(j*(j-1))/2+(i-j);
            }
            cout<<arr5[count1]<<" ";
        }
        cout<<"|\n";
    }
  
    return 0;
}