#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=1e5+5;
ll dp[104][maxn];
ll sumC[maxn];
int n,m,p,D[maxn],H[maxn],T[maxn],sumD[maxn],C[maxn],q[maxn],h,t;
ll Y(int x,int i){ 
    return dp[i][x]+sumC[x];
}
ll X(int x){ 
    return x;
}
db slope(int i,int j,int k){ 
    return 1.0*(Y(j,k)-Y(i,k))/(X(j)-X(i));
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>p;
    for(int i=2;i<=n;++i)cin>>D[i];
    for(int i=1;i<=m;++i)cin>>H[i]>>T[i];
    for(int i=1;i<=n;++i)sumD[i]=sumD[i-1]+D[i];
    for(int i=1;i<=m;++i)C[i]=T[i]-sumD[H[i]];
    sort(C+1,C+1+m);
    for(int i=1;i<=m;++i)sumC[i]=sumC[i-1]+C[i];
    for(int i=1;i<=m;++i)dp[0][i]=9e18;
    dp[0][0]=0;
    for(int i=1;i<=p;++i){ 
        h=t=1;
        q[1]=0;
        for(int j=1;j<=m;++j){ 
            while(h<t&&slope(q[h],q[h+1],i-1)<=C[j])h++;
            int k=q[h];
            dp[i][j]=dp[i-1][k]+(ll)C[j]*(j-k)+sumC[k]-sumC[j];
            while(h<t&&slope(q[t-1],q[t],i-1)>=slope(q[t],j,i-1))t--;
            q[++t]=j;
        }
    }
    ll ans=9e18;
    for(int i=1;i<=p;++i)ans=min(ans,dp[i][m]);
    cout<<ans;
    return 0;
}
