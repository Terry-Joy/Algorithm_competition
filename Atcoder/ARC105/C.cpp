#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
struct Node{
    int l,v;
    bool operator<(const Node&a)const{
        if(l==a.l)return v<a.v;
        return l<a.l;
    }
}a[maxn];
int dp[11],xu[11],n,m,sum[11],ans=1e9,w[11];
bool v[11];
int ask(int x){
    int l=0,r=m,mid,res=0;
    while(l<r){
        mid=(l+r+1)>>1;
        if(a[mid].v>=x)r=mid-1;
        else 
            l=mid;
    }
    return a[l].l;
}
void init(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
        sum[i]=sum[i-1]+w[xu[i]];
    for(int i=2;i<=n;++i){
        for(int j=i-1;j>=1;--j){
            int tmp=sum[i]-sum[j-1];
            int len=ask(tmp);
            dp[i]=max(dp[i],dp[j]+len);
        }
    }
    ans=min(ans,dp[n]);
}
void dfs(int x){
    if(x==n){
        init();
        return;
    }
    for(int i=1;i<=n;++i){
        if(!v[i]){
            v[i]=1;
            xu[x+1]=i;
            dfs(x+1);
            v[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=m;++i){
        cin>>a[i].l>>a[i].v;
    }
    a[m+1].v=1e9;
    sort(a+1,a+1+m);
    int mn=1e9;
    for(int i=m;i>=1;--i){
        mn=min(mn,a[i].v);
        a[i].v=mn;
    }
    for(int i=1;i<=m;++i)
        cout<<a[i].v<<" ";
    for(int i=1;i<=n;++i){
        if(mn<w[i]){
            puts("-1");return 0;
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
} 