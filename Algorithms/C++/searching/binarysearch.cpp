#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
cpp program to find the index of the target number in an array of no duplicate numbers.
*/
int main(){
    int n,x,k;
    cout<<"Enter the size of the vector"<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of the vector"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        v[i]=x;
    }
    sort(v.begin(),v.end());
    cout<<"Enter the target number"<<endl;
    cin>>k;
    int l=0,h=n-1,mid,ans=-1;
    while(l<=h){
        mid=(l+h)/2;
        if(k==v[mid]){
            ans=mid;
            break;
        }
        else if(k>v[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<"Index of target number is: "<<ans<<endl;
    return 0;
}
