#include<bits/stdc++.h>
#define lowb(x) (x&(-x))
using namespace std;
const int maxn=1e5+5;
int ti,head[maxn],next1[maxn<<1],ver[maxn<<1],tot;
char s[10];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct BIT{
    int c[maxn];
    void add(int x,int val){
        while(x<=ti){
            c[x]+=val;
            x+=lowb(x);
        }
    }
    int query(int x){
        int ans=0;
        while(x){
            ans+=c[x];
            x-=lowb(x);
        }
        return ans;
    }
}bit;
struct HCD{
    int fa[maxn],son[maxn],dep[maxn],sz[maxn],top[maxn],in[maxn];
    void dfs1(int x,int f){
        fa[x]=f;
        dep[x]=dep[f]+1;
        sz[x]=1;
        int mxson=-1;
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==f)continue;
            dfs1(y,x);
            sz[x]+=sz[y];
            if(sz[y]>mxson)mxson=sz[y],son[x]=y;
        }
    }
    void dfs2(int x,int t){
        top[x]=t;
        in[x]=++ti;
        if(!son[x])return;
        dfs2(son[x],t);
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==fa[x]||y==son[x])continue;
            dfs2(y,y);
        }
    }
    void init(int x){
        dfs1(x,0);dfs2(x,x);
    }
    void Pupdate(int x,int y){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            bit.add(in[top[x]],1);bit.add(in[x]+1,-1);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        if(x==y)return;
        bit.add(in[y]+1,1);
        bit.add(in[x]+1,-1);
    }
    int query(int x){
        return bit.query(in[x]);
    }
}hcd;
int main(){
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    hcd.init(1);
    for(int i=1;i<=m;++i){
        scanf("%s%d%d",s,&u,&v);
        if(s[0]=='P')hcd.Pupdate(u,v);
        else{
            if(hcd.fa[u]==v)
                cout<<hcd.query(u)<<"\n";
            else cout<<hcd.query(v)<<"\n";
        }
    }
    return 0;
}