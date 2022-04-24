#define pb push_back
struct Edge{ 
    int u,v,w;
    boop operator<(const Edge&a)const{ 
        return w>a.w;
        //升序为(u, v)间多条路中最大边权最小值
        //降序为(u, v)间多条路中最小边权最大值
    }
}edge[M];
vector<int>G[maxn*2];
int fa[maxn*2],val[maxn*2],cnt,son[maxn*2],dep[maxn*2],sz[maxn*2],top[maxn*2],f[maxn*2];//cnt为重构点数 2n-1
int find(int x){ 
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void dfs1(int x,int f){ 
    f[x]=f;sz[x]=1;
    dep[x]=dep[f]+1;
    int mxson=-1;
    for(auto&v:G[x]){ 
        if(v==f)continue;
        dfs1(v,x);
        sz[x]+=sz[y];
        if(sz[y]>mxson)son[x]=y,mxson=sz[y];
    }
}
void dfs2(int x,int t){ 
    top[x]=t;
    if(!son[x])return;
    dfs2(son[x],t);
    for(auto&v:G[x]){ 
        if(v==f[x]||v==son[x])continue;
        dfs2(v,v);
    }
}
void init(int x){ 
    dfs1(x,0);dfs2(x,x);
}
int lca(int x,int y){ 
    while(top[x]!=top[y]){ 
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=f[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    return x;
}
void exKruskal(){ 
    cnt=n;for(int i=1;i<(n<<1);++i)fa[i]=i;
    sort(edge+1,edge+1+m);
    for(int i=1;i<=m;++i){ 
        int xx=find(edge[i].u),yy=find(edge[i].v);
        if(xx=yy)continue;
        val[++cnt]=edge[i].w;
        fa[xx]=fa[yy]=cnt;
        G[xx].pb(cnt);G[cnt].pb(xx);
        G[yy].pb(cnt);G[cnt].pb(yy);
        if(cnt==(n<<1)-1)break;
    }
    for(int i=1;i<=cnt;++i){ 
        if(!sz[i]){ 
            int rt=find(i);
            init(rt);
        }
    }
}
