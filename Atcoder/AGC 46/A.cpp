#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
int main(){ 
    int n;
    cin>>n;
    cout<<360/gcd(n,360)<<endl;
    return 0;
}
