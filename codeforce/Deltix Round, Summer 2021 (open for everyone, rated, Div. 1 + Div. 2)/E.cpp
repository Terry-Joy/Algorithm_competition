#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
int n,q,a[maxn],b[maxn],Log[maxn];
ll mn[maxn][21],mx[maxn][21],sum[maxn];
void RMQ(){ 
    for(int i=1;i<=n;++i)mx[i][0]=mn[i][0]=sum[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j)-1<=n;++i){ 
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        }
    Log[1]=0;
    for(int i=2;i<=n+1;++i)
        Log[i]=Log[i>>1]+1;
}
ll queryMx(int l,int r){ 
    ll ans=-1e18;
    int k=Log[r-l+1];
    return max(mx[l][k],mx[r-(1<<k)+1][k]);  
}
ll queryMn(int l,int r){ 
    ll ans=1e18;
    int k=Log[r-l+1];
    return min(mn[l][k],mn[r-(1<<k)+1][k]);  
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<=n;++i)a[i]-=b[i];
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    RMQ();
    int l,r;
    for(int i=1;i<=q;++i){ 
        cin>>l>>r;
        if(sum[r]-sum[l-1]!=0||(queryMx(l,r)-sum[l-1]>0))
            cout<<"-1\n";
        else
            cout<<abs(queryMn(l,r)-sum[l-1])<<"\n";
    }
    return 0;
}
