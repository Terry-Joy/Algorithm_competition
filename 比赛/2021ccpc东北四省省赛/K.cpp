#include<bits/stdc++.h>
#define fi first 
#define se second
#define eb emplace_back
using namespace std;
using ll=long long;
const int maxn=1e5+5;
typedef pair<int,int>P;
vector<P>Q;
int fa[maxn],sz[maxn];
ll ans=0,sum[maxn<<1];
struct Edge{ 
    int u,v,w;
    bool operator<(const Edge&x)const{ 
        return w>x.w;
    }
}edge[maxn<<1];
ll S(int x){ 
    return (ll)x*(x-1)/2;
}
void init(int n){ 
    Q.clear();
    ans=0;
    for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
}
int find(int x){ 
    return (x==fa[x])?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){ 
    int xx=find(x),yy=find(y);
    if(xx==yy)return;
    ans-=S(sz[xx]);
    ans-=S(sz[yy]);
    fa[yy]=xx;
    sz[xx]+=sz[yy];
    ans+=S(sz[xx]);
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,q;
    cin>>t;
    while(t--){ 
        cin>>n>>m>>q;
        init(n);
        int u,v,w;
        for(int i=1;i<=m;++i){ 
            cin>>u>>v>>w;
            edge[i]={ u,v,w};
        }
        sort(edge+1,edge+1+m);
        for(int i=1;i<=q;++i){ 
            int p;
            cin>>p;
            Q.eb(make_pair(p,i));
        }
        sort(Q.begin(),Q.end(),[&](P a,P b){ 
                return a.fi>b.fi;
                });
        int now=1;
        for(auto u:Q){ 
            while(edge[now].w>=u.fi){ 
                merge(edge[now].u,edge[now].v);
                now++;
            }
            sum[u.se]=ans;
        }
        for(int i=1;i<=q;++i)cout<<sum[i]<<"\n";
    }
    return 0;
}
