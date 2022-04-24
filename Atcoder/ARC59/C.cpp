#include<bits/stdc++.h>
using namespace std;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a[105];
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
    double mid=sum*1.0/n;
    int x1=ceil(mid),x2=floor(mid),now=1e9,ans=0;
    for(int i=1;i<=n;++i){ 
        ans=ans+(x1-a[i])*(x1-a[i]);
    }
    now=min(now,ans);
    ans=0;
    for(int i=1;i<=n;++i){ 
        ans=ans+(x2-a[i])*(x2-a[i]);
    }
    now=min(now,ans);
    cout<<now;
    return 0;
}
