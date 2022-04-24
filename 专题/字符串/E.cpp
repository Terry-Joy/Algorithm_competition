#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
const int maxn=1e5+5;
vector<pair<int,int>>G[maxn];
int tr[maxn*63][2],cnt,n,l[maxn],r[maxn],u,v,w,val[maxn],sum[maxn*63],ans=0;
void dfs(int x,int fa,int d){ 
    val[x]=d;
    for(auto&u:G[x]){ 
        if(u.fi==fa)continue;
        dfs(u.fi,x,d^u.se);
    }
}
void pushDown(int p){ 
    sum[tr[p][0]]+=sum[p];
    sum[tr[p][1]]+=sum[p];
    sum[p]=0;
}
void change(int a,int val,int c){ 
    int now=0;
    for(int i=29;i>=0;--i){ 
        int nxt=((a^val)>>i)&1;
        if(!tr[now][0])tr[now][0]=++cnt;
        if(!tr[now][1])tr[now][1]=++cnt;
        pushDown(now);
        if(val&(1<<i))sum[tr[now][nxt^1]]+=c;
        now=tr[now][nxt];
    }
    sum[now]+=c;
}
void query(int x,int d){ 
    if(!tr[x][0]&&!tr[x][1]){ 
        if(sum[x]==n)ans+=(1<<d);
        return;
    }
    pushDown(x);
    if(tr[x][0])query(tr[x][0],d-1);
    if(tr[x][1])query(tr[x][1],d-1);
}
int main(){ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
    for(int i=1;i<n;++i){ 
        scanf("%d%d%d",&u,&v,&w);
        G[u].pb({v,w});G[v].pb({u,w});
    }
    dfs(1,0,0);
    for(int i=1;i<=n;++i){ 
        change(val[i],r[i],1);
        if(l[i])
            change(val[i],l[i]-1,-1);
    }
    ans=0;
    query(0,30);
    cout<<ans;
    return 0;
}
