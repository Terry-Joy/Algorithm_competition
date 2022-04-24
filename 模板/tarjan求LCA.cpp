#include<bits/stdc++.h>	
#define pb push_back
using namespace std;
const int size=40100;
int head[size],edge[size*2],ver[2*size],next1[2*size];
int fa[size],d[size],v[size],ans[size];
vector<int>q[size],qid[size];
int n,m,tot,t;
void add(int x,int y,int z){
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
int get(int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}
void tarjan(int x){
    v[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        d[y]=d[x]+edge[i];
        tarjan(y);
        fa[y]=x; 
    } 
    for(int i=0;i<q[x].size();++i){
        int y=q[x][i],id=qid[x][i];
        if(v[y]==2){
            int lca=get(y);
            ans[id]=min(ans[id],d[x]+d[y]-2*d[lca]); //两点距离 求lca就直接赋值为lca
        } 
    }
    v[x]=2;
}
void add_query(int x,int y,int i){
    q[x].pb(y),q[y].pb(x);
    qid[x].pb(i),qid[y].pb(i);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        tot=0;
        for(int i=1;i<=n;++i){
            head[i]=0,fa[i]=i,v[i]=0;
            q[i].clear(),qid[i].clear(); 
        } 
        for(int i=1;i<n;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c); 
        }
        for(int i=1;i<=m;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==y)
                ans[i]=0;
            else{
                add_query(x,y,i);
                ans[i]=1<<30; 
            } 
        }
        tarjan(1);
        for(int i=1;i<=m;++i)
            printf("%d\n",ans[i]);
    }   
    return 0;
}
