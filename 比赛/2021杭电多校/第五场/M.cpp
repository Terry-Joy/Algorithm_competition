#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const  ll INF=1e18;
int t,n,p[maxn],head[maxn],edge[maxn<<1],next1[maxn<<1],ver[maxn<<1],tot;
void add(int x,int y,int z){ 
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
ll dp[maxn][2],g[maxn][2];
void dfs(int x,int fa,ll mid){
    dp[x][0]=dp[x][1]=0;
    g[x][1]=g[x][0]=0;
    for(int i=head[x];i;i=next1[i]){ 
        int v=ver[i],z=edge[i];
        if(v==fa)continue;
        dfs(v,x,mid);
        g[x][1]=dp[x][1];
        g[x][0]=dp[x][0];
        if(dp[x][1]+min(dp[v][0]+edge[i],dp[v][1]+(max(0,edge[i]-p[v])))<=mid){ 
            dp[x][1]=max(dp[x][1],min(dp[v][0]+edge[i],dp[v][1]+max(0,(edge[i]-p[v]))));
        }else dp[x][1]=INF;
        ll mn=min(dp[v][0]+edge[i],dp[v][1]+max(0,(edge[i]-p[v])));
        bool f=0;
        if(mn>g[x][1]){ //贡献给当前
            if(dp[v][1]+max(0,edge[i]-p[v])<dp[v][0]+edge[i]){ 
                if(dp[v][1]+max(0,edge[i]-p[v]-p[x])+g[x][1]<=mid)
                    dp[x][0]=dp[v][1]+max(0,edge[i]-p[v]-p[x]),f=1;
            }else{ 
                if(dp[v][0]+max(0,edge[i]-p[x])+g[x][1]<=mid)
                    dp[x][0]=dp[v][0]+max(0,edge[i]-p[x]),f=1;
            }
        }else{ //当前次大
            if(dp[v][1]+max(0,edge[i]-p[v])<dp[v][0]+edge[i]){ 
                if(dp[v][1]+max(0,edge[i]-p[v]-p[x])+g[x][1]<=mid)
                    f=1;
            }else{ 
                if(dp[v][0]+max(0,edge[i]-p[x])+g[x][1]<=mid)
                    f=1;
            }
        }
        bool f2=0;
        if(mn>g[x][0]){ 
            if(mn+g[x][0]<=mid)
                dp[x][0]=f?min(dp[x][0],mn):mn,f2=1;
        }else{ 
            if(mn+g[x][0]<=mid)
                f2=1;
        }
        if(!f&&!f2)dp[x][0]=INF;
    }
}
int main(){ 
    freopen("input.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        tot=0;
        for(int i=1;i<=n;++i)scanf("%d",&p[i]),head[i]=0;
        int a,b,c;
        ll l=0,r=0;
        for(int i=1;i<n;++i){ 
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
            r+=c;
        }
        while(l<r){ 
            ll mid=(l+r)/2;
            dfs(1,0,mid);
            if(dp[1][0]<=mid||dp[1][1]<=mid)r=mid;
            else l=mid+1;
        }
        cout<<r<<"\n";
    }
    return 0;
}
