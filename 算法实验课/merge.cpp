#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100];
bool cmp(int x,int y){return x<y;}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)cin>>b[i];
    merge(a+1,a+1+n,b+1,b+1+m,c+1,cmp);
    for(int i=1;i<=n+m-1;++i)cout<<c[i]<<" ";
    cout<<c[n+m]<<"\n";
    return 0;
}