#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=1e6+5;
int n,x[maxn],p[maxn],c[maxn],q[maxn],h,t;
ll sumP[maxn],sum[maxn],dp[maxn];
ll X(int x){
    return sumP[x];
}
ll Y(int x){ 
    return dp[x]+sum[x];
}
db slope(int i,int j){ 
    return 1.0*(Y(j)-Y(i))/(X(j)-X(i));
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i]>>p[i]>>c[i];
    for(int i=1;i<=n;++i)sumP[i]=sumP[i-1]+p[i],sum[i]=sum[i-1]+(ll)p[i]*x[i];
    h=t=1;q[h]=0;
    for(int i=1;i<=n;++i){ 
        while(h<t&&slope(q[h],q[h+1])<=x[i])h++;
        int j=q[h];
        dp[i]=dp[j]+sum[j]-(ll)x[i]*sumP[j]-sum[i-1]+(ll)x[i]*sumP[i-1]+c[i];
        while(h<t&&slope(q[t-1],q[t])>slope(q[t],i))t--;
        q[++t]=i;
    }
    int now=n;
    ll ans=9e18;
    while(!p[now]){ 
        ans=min(ans,dp[now]);
        now--;
    }
    cout<<min(ans,dp[now]);
    return 0;
}
