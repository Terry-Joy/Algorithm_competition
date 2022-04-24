#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
struct Node{ 
    int l,r;
}a[maxn],b[maxn];
int n,k;
bool cmp(Node&a,Node&b){ 
    if(a.l==b.l)return a.r<b.r;
    return a.l<b.l;
}
int len[maxn],num,m,dp[maxn][maxn],q[maxn],h=1,t=0;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){ 
        scanf("%d%d",&a[i].l,&a[i].r),a[i].r--;
    }
    sort(a+1,a+1+n,cmp);
    int mx=2e9;
    for(int i=n;i;--i){ 
        if(mx<=a[i].r)len[++num]=a[i].r-a[i].l+1;
        else mx=a[i].r,b[++m]=a[i];
    }
    sort(len+1,len+1+num);
    reverse(len+1,len+1+num);
    reverse(b+1,b+1+m);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=k;++i){ 
        h=1,t=0;
        for(int j=i;j<=m;++j){ 
            if(~dp[i-1][j-1]){ 
                while(h<=t&&dp[i-1][q[t]]+b[q[t]+1].r<=dp[i-1][j-1]+b[j].r)t--;
                q[++t]=j-1;
            }
            while(h<=t&&b[q[h]+1].r<b[j].l)h++;
            if(h<=t){ 
                dp[i][j]=dp[i-1][q[h]]+b[q[h]+1].r-b[j].l+1;
            }
        }
    }
    int ans=0,sum=0;
    for(int i=0;i<=min(k,num);++i){ 
        sum+=len[i];
        if(~dp[k-i][m])
            ans=max(ans,sum+dp[k-i][m]);
    }
    cout<<ans;
    return 0;
}
