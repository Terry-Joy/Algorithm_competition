#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
ll a[maxn];
ll getVal(int l,int mid,int r){
    return abs(a[r]-a[mid]-(a[mid]-a[l-1]));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],a[i]+=a[i-1];
    int i=1,j=2,k=3;
    ll ans=9e18;
    for(j=2;j<=n-1;++j){ 
        while(i+1<j&&getVal(1,i,j)>getVal(1,i+1,j))i++;
        while(k+1<n&&getVal(j+1,k,n)>getVal(j+1,k+1,n))k++;
        ans=min(ans,max(max(a[j]-a[i],a[i]),max(a[n]-a[k],a[k]-a[j]))-min(min(a[j]-a[i],a[i]),min(a[n]-a[k],a[k]-a[j])));
    }
    cout<<ans;
    return 0;
}
