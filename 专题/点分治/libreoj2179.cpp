#include<bits/stdc++.h>
#define N maxn*36
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r
#define pb push_back 
#define fi first 
#define se second 
using namespace std;
const int maxn=2e5+5;
const int INF=-0x3f3f3f3f;
typedef pair<int,int> P;
vector<P>G[maxn];
int n,m,l,r,val[maxn],mxson[maxn],sz[maxn],rt1,rt2,S,rt,ans=INF,cnttmp;
P tmp[maxn];
bool v[maxn];
struct SegmentTree{
    int lc[N],rc[N],tot,mx[N]={INF};
    void pushUp(int p){
        mx[p]=max(mx[ls],mx[rs]);//?????0 ??????????INF; 
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){mx[p]=max(mx[p],mx[q]);return p;}
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
    int query(int p,int l,int r,int L,int R){
        if(!p||L>r||R<l)return INF;
        if(L<=l&&r<=R)return mx[p];
        int mid=l+r>>1;
        int ans=INF;
        if(L<=mid)ans=max(ans,query(lson,L,R));
        if(R>mid)ans=max(ans,query(rson,L,R));
        return ans;
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p){p=++tot;ls=rs=0;mx[p]=INF;}
        if(l==r){
            mx[p]=max(mx[p],val);return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
}tr;
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(auto&z:G[x]){
        int y=z.se;
        if(v[y]||y==f)continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-mxson[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
    mxson[rt=0]=maxn;
    S=sz[x];
    getRoot(x,0);
}
void getQue(int x,int f,int col,int d,int sum){
	if(d>r)return;
    tmp[++cnttmp]={d,sum};
    if(d>=l&&d<=r) 
    	ans=max(ans,sum);
    for(auto&z:G[x]){
        int y=z.se,edge=z.fi;
        if(y==f||v[y])continue;
        getQue(y,x,edge,d+1,sum+((edge==col)?0:val[edge]));
    }
}
void cal(int x){
    rt1=0;rt2=0;
    int lastcol=0;
    for(int i=0;i<G[x].size();++i){
        int y=G[x][i].se,col=G[x][i].fi;
        if(v[y])continue;
        if(i&&col!=lastcol){
            rt1=tr.merge(rt1,rt2,1,r);rt2=0;
        }
        cnttmp=0;
        getQue(y,x,col,1,val[col]);
        for(int j=1;j<=cnttmp;++j){
            ans=max(ans,tmp[j].se+tr.query(rt1,1,r,max(1,l-tmp[j].fi),r-tmp[j].fi));
			if(rt2)
            	ans=max(ans,tmp[j].se+tr.query(rt2,1,r,max(1,l-tmp[j].fi),r-tmp[j].fi)-val[col]);
        }
        for(int j=1;j<=cnttmp;++j){
                tr.update(rt2,1,r,tmp[j].fi,tmp[j].se);
        }
        lastcol=col;
    }   
}
void dfz(int x){
    v[x]=1;
    cal(x);
    for(auto&z:G[x]){
        int y=z.se;
        if(v[y])continue;
        init(y);
        dfz(rt);
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&l,&r);
    int u,v,w;
    for(int i=1;i<=m;++i)scanf("%d",&val[i]);
    for(int i=1;i<n;++i){
        scanf("%d%d%d",&u,&v,&w);
        G[u].pb({w,v});G[v].pb({w,u});
    }
    for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end());
    S=n;
    mxson[rt=0]=maxn;
    getRoot(1,0);
    dfz(rt);
    cout<<ans<<"\n";
    return 0;
}