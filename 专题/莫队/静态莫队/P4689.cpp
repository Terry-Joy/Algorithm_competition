#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int maxm=5e5+5;
int head[maxn],ver[maxn<<1],next1[maxn<<1],tot,n,m,a[maxn],b[maxn],rt=1,fa[maxn],son[maxn],dep[maxn],sz[maxn],pos[maxn],num,big,cnt1[maxn],cnt2[maxn];
int top[maxn],in[maxn],ti,val[maxn];
ll sum,ans[maxm];
int op[maxm];
struct Q{
    int L,R,id;
    bool is;
    bool operator<(const Q&a)const{
        return pos[L]^pos[a.L]?pos[L]<pos[a.L]:pos[L]&1?R<a.R:R>a.R; 
    }
}q[maxm*9];
void dfs1(int x,int f){
    fa[x]=f;sz[x]=1;
    dep[x]=dep[f]+1;
    int mxson=-1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs1(y,x);
        sz[x]+=sz[y];
        if(sz[y]>mxson)son[x]=y,mxson=sz[y];
    }
}
void dfs2(int x,int t){
    in[x]=++ti;
    val[ti]=a[x];
    top[x]=t;
    if(!son[x])return;
    dfs2(son[x],t);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    return x;
}
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
int findson(int x,int y){
    while(top[x]!=top[y]){
        if(fa[top[y]]==x)
            return top[y];
        y=fa[top[y]];
    }
    return son[x];
}
void update(int x,int y,int i){
    int xx=lca(x,rt),yy=lca(y,rt);
    if(xx!=x&&yy!=y){
        q[++num]={in[x]+sz[x]-1,in[y]-1,i,0};
        q[++num]={in[x]+sz[x]-1,in[y]+sz[y]-1,i,1};
        q[++num]={in[y]+sz[y]-1,in[x]-1,i,0};
        q[++num]={in[x]-1,in[y]-1,i,1};
    }else if(xx!=x&&y==rt){
        q[++num]={in[x]+sz[x]-1,n,i,1};
        q[++num]={in[x]-1,n,i,0};
    }else if(xx!=x&&yy==y&&y!=rt){
        int zu=findson(y,rt);
        q[++num]={in[x]+sz[x]-1,in[zu]-1,i,1};
        q[++num]={in[x]+sz[x]-1,n,i,1};
        q[++num]={in[x]+sz[x]-1,in[zu]+sz[zu]-1,i,0};
        q[++num]={in[x]-1,in[zu]-1,i,0};
        q[++num]={in[x]-1,n,i,0};
        q[++num]={in[x]-1,in[zu]+sz[zu]-1,i,1};
    }else if(x==rt&&yy!=y){
        q[++num]={in[y]+sz[y]-1,n,i,1};
        q[++num]={in[y]-1,n,i,0};
    }else if(x==rt&&y==rt){
        q[++num]={n,n,i,1};
    }else if(x==rt&&yy==y&&y!=rt){
        int zu=findson(y,rt);
        q[++num]={in[zu]-1,n,i,1};
        q[++num]={n,n,i,1};
        q[++num]={in[zu]+sz[zu]-1,n,i,0};
    }else if(xx==x&&x!=rt&&yy!=y){
        int zu=findson(x,rt);
        q[++num]={in[y]+sz[y]-1,in[zu]-1,i,1};
        q[++num]={in[y]+sz[y]-1,n,i,1};
        q[++num]={in[y]+sz[y]-1,in[zu]+sz[zu]-1,i,0};
        q[++num]={in[y]-1,in[zu]-1,i,0};
        q[++num]={in[y]-1,n,i,0};
        q[++num]={in[y]-1,in[zu]+sz[zu]-1,i,1};
    }else if(xx==x&&x!=rt&&y==rt){
        int zu=findson(x,rt);
        q[++num]={in[zu]-1,n,i,1};
        q[++num]={n,n,i,1};
        q[++num]={in[zu]+sz[zu]-1,n,i,0};
    }else if(xx==x&&x!=rt&&yy==y&&y!=rt){
        int x=findson(x,rt),y=findson(y,rt);
        q[++num]={in[x]-1,in[y]-1,i,1};
        q[++num]={n,in[x]-1,i,1};
        q[++num]={in[x]-1,in[y]+sz[y]-1,i,0};
        q[++num]={n,in[y]-1,i,1};
        q[++num]={n,n,i,1};
        q[++num]={n,in[y]+sz[y]-1,i,0};
        q[++num]={in[y]-1,in[x]+sz[x]-1,i,0};
        q[++num]={n,in[x]+sz[x]-1,i,0};
        q[++num]={in[x]+sz[x]-1,in[y]+sz[y]-1,i,1};
    }
}
void add0(int x){
    sum+=cnt2[val[x]];
    cnt1[val[x]]++;
}
void add1(int x){
    sum+=cnt1[val[x]];
    cnt2[val[x]]++;
}
void del0(int x){
    sum-=cnt2[val[x]];
    cnt1[val[x]]--;
}
void del1(int x){
    sum-=cnt1[val[x]];
    cnt2[val[x]]--;
}
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]),b[i]=a[i];
    }
    sort(b+1,b+1+n);
    x=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+1+x,a[i])-b;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs1(1,0);dfs2(1,1);
    for(int i=1;i<=m;++i){
        scanf("%d",&op[i]);
        if(op[i]==1){
            scanf("%d",&rt);
        }else{
            scanf("%d%d",&x,&y);
            update(x,y,i);
        }
    }
    for(int i=1;i<=num;++i){
        if(q[i].L>q[i].R)swap(q[i].L,q[i].R);
    }
    big=n/sqrt(num);
    for(int i=1;i<=n;++i)pos[i]=(i-1)/big+1;
    sort(q+1,q+1+num);
    int pl=0,pr=0;
    for(int i=1;i<=num;++i){
        int l=q[i].L,r=q[i].R;
        while(pl<l)add0(++pl);
        while(pr<r)add1(++pr);
        while(pl>l)del0(pl--);
        while(pr>r)del1(pr--);
        ans[q[i].id]+=(q[i].is?sum:-sum);
    }
    for(int i=1;i<=m;++i){
        if(op[i]==2)cout<<ans[i]<<"\n";
    }
    return 0;
}