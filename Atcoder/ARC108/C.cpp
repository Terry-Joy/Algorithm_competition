#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int n,m;
int ver[maxn<<1],edge[maxn<<1],next1[maxn<<1],head[maxn],tot,fa[maxn];
int ans[maxn],a[maxn],b[maxn],c[maxn];
void add(int x,int y,int z){ 
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
int find(int x){ 
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void dfs(int x,int fa,int val){ 
    if(x!=1){ 
        if(ans[fa]==val){ 
            ans[x]=1;
            if(ans[x]==ans[fa])ans[x]++;
        }
        else ans[x]=val;
    }
    for(int i=head[x];i;i=next1[i]){ 
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x,edge[i]);
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m;++i){ 
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=m;++i){ 
        int f1=find(a[i]);
        int f2=find(b[i]);
        if(f2!=f1){ 
            add(a[i],b[i],c[i]);
            add(b[i],a[i],c[i]);
            fa[f1]=f2;
        }
    }
    ans[1]=1;
    dfs(1,-1,0);
    for(int i=1;i<=n;++i)cout<<ans[i]<<"\n";
    return 0;
}
