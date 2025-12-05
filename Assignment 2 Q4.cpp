/*
4) String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    //(a) 

    string first_name,last_name,full_name;
    cout<<"Enter first name: ";
    cin>>first_name;
    cout<<"Enter surname: ";
    cin>>last_name;
    full_name=first_name+" "+last_name;
    cout<<"Full name: "<<full_name;

    int size=full_name.length();
    string reversed_string="";

    //(b)

    for(int i=size-1;i>=0;i--){
        reversed_string=reversed_string+full_name[i];
    }
    cout<<"\nReversed string: "<<reversed_string;

    //(c) 

    char vowels[]={'a','e','i','o','u','A','E','I','O','U'};
    string no_vowels="";

    for(int i=0;i<size;i++){
        bool is_vowel=false;
        for(int j=0;j<10;j++){
            if(full_name[i]==vowels[j]){
                is_vowel=true;
                break;
            }
        }
        if(is_vowel!=true){
            no_vowels+=full_name[i];
        }
    }
    cout<<"\nNo vowels: "<<no_vowels;

    //(d) 

    string is_alpha=full_name;
    char temp;

    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){

            int a=is_alpha[j];
            int b=is_alpha[j+1];

            if(65<=a && a<=90){
                a=a+32;
            }
            if(65<=b && b<=90){
                b=b+32;
            }

            if(a>b){
                temp=is_alpha[j];
                is_alpha[j]=is_alpha[j+1];
                is_alpha[j+1]=temp;
            }
        }
    }
    cout<<"\nAlphabetical string: "<<is_alpha;

    //(e) 

    string upper="ABCDEF";
    int size_upper=upper.length();
    
    for(int i=0;i<size_upper;i++){
        int c=upper[i];
        if(65<=c && c<=90){
            c=c+32;
            upper[i]=char(c);    
        }
    }
    cout<<"\nLower: "<<upper;

    return 0;
}