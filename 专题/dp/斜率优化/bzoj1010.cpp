#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=5e4+5;
ll dp[maxn],sum[maxn];
int n,c[maxn],q[maxn],h,t,L;
db X(int x){
    return sum[x]+L;
}
db pow2(ll x){ 
    return x*x;
}
db Y(int x){ 
    return dp[x]+pow2(sum[x]+L);
}
db rate(int i,int j){ 
    return 1.0*(Y(j)-Y(i))/(X(j)-X(i));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>L;
    for(int i=1;i<=n;++i)cin>>c[i],c[i]++;
    L++;
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+c[i];
    h=t=1;q[h]=0;
    for(int i=1;i<=n;++i){ 
        while(h<t&&rate(q[h],q[h+1])<2*sum[i])h++;
        int j=q[h];
        dp[i]=dp[j]+pow2(sum[i]-sum[j]-L);
        while(h<t&&rate(q[t-1],q[t])>rate(q[t],i))t--;
        q[++t]=i;
    }
    cout<<dp[n];
    return 0;
}
