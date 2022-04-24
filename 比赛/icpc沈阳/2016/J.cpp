#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
int t,head[maxn],next1[maxn<<1],ver[maxn<<1],tot,n,a,b,deg[maxn],q;
ll sum[maxn<<2],add[maxn<<2];
char s[10];
int sL[maxn],sR[maxn],grasL[maxn],grasR[maxn],lin[maxn][2],id[maxn],size=0,fa[maxn];//保留儿子最左最右序号
void add_edge(int x,int y){ 
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot,deg[y]++;
}
void topsort(){ 
    queue<int>q;
    for(int i=1;i<=n;++i){ 
        if(deg[i]==1)q.push(i);
    }
    while(!q.empty()){ 
        int u=q.front();q.pop();
        for(int i=head[u];i;i=next1[i]){ 
            int y=ver[i];
            if(deg[y]>1){ 
                deg[y]--;
                if(deg[y]==1)q.push(y);
            }
        }
    }
}
void bfs(int x){ 
    queue<int>q;
    q.push(x);
    while(!q.empty()){ 
        int u=q.front();q.pop();
        sL[u]=grasL[u]=INF;
        sR[u]=grasR[u]=0;
        for(int i=head[u];i;i=next1[i]){ 
            int y=ver[i];
            if(deg[y]>1||y==fa[u])continue;
            id[y]=++size;
            fa[y]=u;
            sL[u]=min(sL[u],id[y]);
            sR[u]=max(sR[u],id[y]);
            q.push(y);
        }
        grasL[fa[u]]=min(grasL[fa[u]],sL[u]);
        grasR[fa[u]]=max(grasR[fa[u]],sR[u]);
    }
}
void build(int p,int l,int r){ 
    sum[p]=add[p]=0;
    if(l==r)return;
    int mid=l+r>>1;
    build(lson);
    build(rson);
}
void pushUp(int p){ 
    sum[p]=sum[ls]+sum[rs];
}
void pushDown(int p,int l,int r,int mid){ 
    if(add[p]){ 
        add[ls]+=add[p];
        add[rs]+=add[p];
        sum[ls]+=add[p]*(mid-l+1);
        sum[rs]+=add[p]*(r-mid);
        add[p]=0;
    }
}
void change(int p,int l,int r,int L,int R,int val){ 
    if(L==0||R==0)return;
    if(L<=l&&r<=R){ 
        sum[p]+=1ll*(r-l+1)*val;
        add[p]+=val;
        return;
    }
    int mid=l+r>>1;
    pushDown(p,l,r,mid);
    if(L<=mid)change(lson,L,R,val);
    if(R>mid)change(rson,L,R,val);
    pushUp(p);
}
void work(int u,int k,int d){ 
    if(k==0)change(1,1,n,id[u],id[u],d);
    else if(k==1){ 
        change(1,1,n,sL[u],sR[u],d);
        change(1,1,n,id[u],id[u],d);
        if(deg[u]==1)
            change(1,1,n,id[fa[u]],id[fa[u]],d);
        else{ 
           for(int i=0;i<=1;++i)
            change(1,1,n,id[lin[u][i]],id[lin[u][i]],d);
        }
    }else{ 
        change(1,1,n,sL[u],sR[u],d);//儿子和曾孙
        change(1,1,n,grasL[u],grasR[u],d);
        if(deg[u]==1){ 
            change(1,1,n,id[fa[u]],id[fa[u]],d);
            change(1,1,n,sL[fa[u]],sR[fa[u]],d);
            if(deg[fa[u]]==1)change(1,1,n,id[fa[fa[u]]],id[fa[fa[u]]],d);
            else{ 
                for(int i=0;i<=1;++i){ 
                    int y=lin[fa[u]][i];
                    change(1,1,n,id[y],id[y],d);
                }
            }
        }else{ 
            change(1,1,n,id[u],id[u],d);
            int linlin[2],num=0;
            for(int i=0;i<=1;++i){ 
                int y=lin[u][i];
                change(1,1,n,id[y],id[y],d);
                change(1,1,n,sL[y],sR[y],d);
                for(int j=0;j<=1;++j){ 
                    if(lin[y][j]==u||lin[y][j]==lin[u][0]||lin[y][j]==lin[u][1])continue;
                    if(num>0&&lin[y][j]==linlin[num-1])continue;
                    linlin[num++]=lin[y][j];
                }

            }
            for(int i=0;i<num;++i)
                change(1,1,n,id[linlin[i]],id[linlin[i]],d);
        }
    }
}
ll query(int p,int l,int r,int L,int R){ 
    if(L==0||R==0)return 0;
    if(L<=l&&r<=R){ 
        return sum[p];
    }
    int mid=l+r>>1;
    pushDown(p,l,r,mid);
    ll ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>mid)ans+=query(rson,L,R);
    return ans;
}
ll getans(int u,int k){ 
    ll ans=0;
    if(k==0)return query(1,1,n,id[u],id[u]);
    else if(k==1){ 
        ans+=query(1,1,n,sL[u],sR[u]);
        ans+=query(1,1,n,id[u],id[u]);
        if(deg[u]==1){ //在树上
            ans+=query(1,1,n,id[fa[u]],id[fa[u]]);
        }else{ 
            for(int i=0;i<=1;++i){ 
                int y=lin[u][i];
                ans+=query(1,1,n,id[y],id[y]);
            }
        }
        return ans;
    }
    else{ 
        ans+=query(1,1,n,sL[u],sR[u]);
        ans+=query(1,1,n,grasL[u],grasR[u]);
        if(deg[u]==1){ 
            ans+=query(1,1,n,id[fa[u]],id[fa[u]]);
            ans+=query(1,1,n,sL[fa[u]],sR[fa[u]]);
            if(deg[fa[u]]==1)
                ans+=query(1,1,n,id[fa[fa[u]]],id[fa[fa[u]]]);
            else{ 
                for(int i=0;i<=1;++i){ 
                    int y=lin[fa[u]][i];
                    ans+=query(1,1,n,id[y],id[y]);
                }
            }
        }else{ 
            int linlin[2],num=0;
            ans+=query(1,1,n,id[u],id[u]);
            for(int i=0;i<=1;++i){ 
                int y=lin[u][i];
                ans+=query(1,1,n,id[y],id[y]);
                ans+=query(1,1,n,sL[y],sR[y]);
                for(int j=0;j<=1;++j){ 
                    if(lin[y][j]==u||lin[y][j]==lin[u][0]||lin[y][j]==lin[u][1])continue;
                    if(num>0&&lin[y][j]==linlin[num-1])continue;                      //去重
                    linlin[num++]=lin[y][j];
                }
            }
            for(int i=0;i<num;++i)
                ans+=query(1,1,n,id[linlin[i]],id[linlin[i]]);
        }   
    }
    return ans;
}
void init(){ 
    for(int x=1;x<=n;++x){ 
        if(deg[x]>1){ 
            int j=0;
            for(int i=head[x];i;i=next1[i]){ 
                int y=ver[i];
                if(deg[y]>1)lin[x][j++]=y;
            }
            id[x]=++size;
            bfs(x);
        }
    }
    build(1,1,n);
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        size=0;
        tot=0;
        for(int i=1;i<=n;++i)head[i]=0,deg[i]=0,fa[i]=0;
        for(int i=1;i<=n;++i){ 
            scanf("%d%d",&a,&b);
            add_edge(a,b);
            add_edge(b,a);
        }
        topsort();
        init();
        scanf("%d",&q);
        while(q--){ 
            scanf("%s",s);
            if(s[0]=='M'){ 
                int u,k,d;
                scanf("%d%d%d",&u,&k,&d);
                work(u,k,d);
            }else{ 
                int u,k;
                scanf("%d%d",&u,&k);
                printf("%lld\n",getans(u,k));
            }
        }
    }
    return 0;
}
