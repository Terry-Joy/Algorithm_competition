#include<bits/stdc++.h>
#define pb push_back
#define fi first 
#define se second
using namespace std;
typedef pair<int,int>P;
const int maxn=2e5+5;
vector<int>G[maxn];
vector<P>st[maxn];
int in[maxn],sz[maxn],top[maxn],ti,fa[maxn],son[maxn],col[maxn],cnt[maxn],C,a,b,n,q;
void dfs1(int x,int f){
    sz[x]=1;fa[x]=f;
    int mxson=-1;
    for(auto&v:G[x]){
        if(v==f)continue;
        dfs1(v,x);
        sz[x]+=sz[v];
        if(sz[v]>mxson)mxson=sz[v],son[x]=v;
    }
}
void dfs2(int x,int t){
    in[x]=++ti;
    top[x]=t;
    if(!son[x])return;
    dfs2(son[x],t);
    for(auto&v:G[x]){
        if(v==fa[x]||v==son[x])continue;
        dfs2(v,v);
    }
}
void update(int val,int c){
    cnt[col[c]]--;
    col[c]+=val;
    cnt[col[c]]++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>C>>q;
    cnt[0]=C;
    for(int i=1;i<n;++i){
        cin>>a>>b;
        G[a].pb(b);G[b].pb(a);
    }
    dfs1(1,0);dfs2(1,1);
    int u,c,m;
    for(int i=1;i<=q;++i){
        cin>>u>>c>>m;
        while(u){
            int tt=top[u],dfn=in[u],fir=in[tt]-1;//fir表示撤销的顶
            while(!st[tt].empty()&&st[tt].back().fi<=dfn){
                P a=st[tt].back();st[tt].pop_back();
                update(-(a.fi-fir),a.se);
                fir=a.fi;
            }   
            if(!st[tt].empty()){//还有比当前深度更深的没撤销
                update(-(in[u]-fir),st[tt].back().se);
            }                            
            st[tt].pb({in[u],c});
            update(in[u]-in[tt]+1,c);//top[u]->fa[top[u]]的边算上，但根算多了一次
            u=fa[top[u]];
        }
        int ans=cnt[m];
        if(col[c]==m)ans--;//只有在根的时候会被多算一次，通过撤销之前深度更深的，保证只会在当前新询问多计算一次
        else if(col[c]==m+1)ans++;
        cout<<ans<<"\n";
    }
    return 0;
}