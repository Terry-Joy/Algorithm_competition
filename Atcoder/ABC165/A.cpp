#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int n,x,t;
    cin>>n>>x>>t;
    cout<<((n%x==0)?(n/x*t):(((n/x)+1)*t));
    return 0;
}