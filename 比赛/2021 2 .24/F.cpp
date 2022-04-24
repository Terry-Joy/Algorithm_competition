#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
int a[maxn],n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i+=2)cout<<a[i]<<" ";
    for(int i=2;i<=n;i+=2)cout<<a[i]<<" ";
    return 0;
}