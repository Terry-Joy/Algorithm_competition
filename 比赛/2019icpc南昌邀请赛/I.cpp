#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int L[maxn],R[maxn],q[maxn],h,t,a[maxn],Log[maxn],n;
ll mn[maxn][25],mx[maxn][25],sum[maxn];
void RMQ(){
    for(int i=0;i<=n;++i)mn[i][0]=mx[i][0]=sum[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<j)-1<=n;++i){
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
        }
        Log[1]=0;
        for(int i=2;i<=n+1;++i)Log[i]=Log[i/2]+1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    RMQ();
    h=1;t=0;
    a[n+1]=a[0]=-1e9;//边界
    for(int i=1;i<=n+1;++i){
        while(h<=t&&a[q[t]]>a[i]){
            R[q[t]]=i-1;
            t--;
        }
        q[++t]=i;
    }
    h=1,t=0;
    for(int i=n;i>=0;--i){
        while(h<=t&&a[q[t]]>a[i]){
            L[q[t]]=i+1;t--;
        }
        q[++t]=i;
    }
    ll ans=-1e18;
    for(int i=1;i<=n;++i){
        if(a[i]>0)ans=max(ans,1ll*a[i]*(sum[R[i]]-sum[L[i]-1]));
        else{
            int l1,r1,l2,r2;
            l1=L[i]-1,r1=i-1;
            l2=i,r2=R[i];
            int k1=Log[r1-l1+1],k2=Log[r2-l2+1];
            ll m1=max(mx[l1][k1],mx[r1-(1<<k1)+1][k1]);
            ll m2=min(mn[l2][k2],mn[r2-(1<<k2)+1][k2]);
            ans=max(ans,1ll*a[i]*(m2-m1));
        }
    }
    cout<<ans<<'\n';
    return 0;
}