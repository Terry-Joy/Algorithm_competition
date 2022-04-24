#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;
const int maxn=1e5+10;
const int maxm=2e5+10;
const int INF=0x3f3f3f3f;
const ll mod=998244353;
int head[maxn],ver[maxm<<1],next1[maxm<<1],tot,s,t;
ll cnt1[maxn],cnt2[maxn],dis[maxn],disS[maxn],disT[maxn];
int T,n,m,a,b;
bool vis[maxn];
void add(int x,int y){ 
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dijkstra(ll x){ 
    queue<P>q;
    for(int i=1;i<=n;++i)vis[i]=0,dis[i]=INF;
    q.push({0,s});
    dis[s]=0;
    if(!x)cnt1[s]=1;
    else cnt2[s]=1;
    while(!q.empty()){ 
        int u=q.front().second;q.pop();
        for(int i=head[u];i;i=next1[i]){ 
            int v=ver[i];
            if(dis[v]==INF){ 
                dis[v]=dis[u]+1;
                if(x)
                    cnt2[v]=cnt2[u];
                else 
                    cnt1[v]=cnt1[u];
                q.push({-dis[v],v});
            }else{ 
                if(dis[v]==dis[u]+1){ 
                    if(!x){ 
                        cnt1[v]=cnt1[u]+cnt1[v];
                        if(cnt1[v]>=mod)cnt1[v]-=mod;
                    } 
                    else{ 
                        cnt2[v]=cnt2[u]+cnt2[v];
                        if(cnt2[v]>=mod)cnt2[v]-=mod;
                    }
                }
            }
        }
    }
    if(!x){ 
        for(int i=1;i<=n;++i)
            disS[i]=dis[i];
    }else{ 
        for(int i=1;i<=n;++i)
            disT[i]=dis[i];
    }
}
int main(){ 
    scanf("%d",&T);
    for(int f=1;f<=T;++f){ 
        scanf("%d%d",&n,&m);
        tot=0;
        s=1;t=n;
        for(int i=0;i<=n;++i)head[i]=0,cnt1[i]=cnt2[i]=0,disS[i]=disT[i]=0;
        for(int i=1;i<=m;++i){ 
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        dijkstra(0);
        swap(s,t);
        dijkstra(1);
        ll d=disT[t];
        ll ans=0;
        for(int i=1;i<=n;++i){ 
            if(disS[i]+disT[i]!=d)continue;
            if(disS[i]==disT[i])
                ans=(ans+cnt1[i]*cnt2[i]%mod*cnt1[i]*cnt2[i]%mod)%mod;
        }
        if(f==T)cout<<ans;
        else cout<<ans<<"\n";
    }
    return 0;
}
