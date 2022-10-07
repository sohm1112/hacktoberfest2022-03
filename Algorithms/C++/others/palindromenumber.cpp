#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number to check for palindrome :\n";
    cin>>n;
    int temp=n,sum=0;
    while(n>0){
        int r=n%10;
        sum=sum*10 + r;
        n=n/10;

    }
   
    if(sum==temp){
        printf("%d is a palindrome\n",temp);
    }
    else
    printf("Not a palindrome :\n");
    return 0;

}