#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> P;
const int maxn=3e4+5;
const int INF=0x3f3f3f3f;
vector<P>G[maxn];
int head[maxn],ver[maxn*4],next1[maxn*4],edge[maxn*4],tot,t,n,m,k,rt;
int sz[maxn],mxson[maxn],S,cnttmp,tmp[maxn],sum[maxn],ans1,ans2,tmp2[maxn],sum2[maxn],val[maxn];
bool v[maxn];
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
struct DIJ{
    int d[maxn];
    bool vis[maxn];
    priority_queue<P,vector<P>,greater<P> >q;
    void dij(int x){
        while(!q.empty())q.pop();
        for(int i=1;i<=n;++i)d[i]=INF,vis[i]=0;
        d[x]=0;q.push({d[x],x});
        while(!q.empty()){
            int u=q.top().se,dis=q.top().fi;q.pop();
            if(d[u]<dis)continue;
            for(auto&e:G[u]){
                int v=e.fi,w=e.se;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    q.push({d[v],v});
                }
            }
        }
        solve_tree();
    }
    void solve_tree(){
        for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end());
        dfs(1);
    }
    void dfs(int x){
        vis[x]=1;
        for(auto&e:G[x]){
            int v=e.fi,w=e.se;
            if(vis[v])continue;
            if(d[v]==d[x]+w){
                add(x,v,w);
                add(v,x,w);
                dfs(v);
            }
        }
    }
}dij;
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-mxson[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
    S=sz[x];
    mxson[rt=0]=maxn;
    getRoot(x,0);
}
void getQue(int x,int f,int num,int val){
    cnttmp=max(cnttmp,num);
    if(val==tmp[num])sum[num]++;
    else if(val>tmp[num])sum[num]=1,tmp[num]=val;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getQue(y,x,num+1,val+edge[i]);
    }
}
void cal(int x){
    int num=0;
    tmp2[1]=0;sum2[1]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        cnttmp=0;
        getQue(y,x,1,edge[i]);
        for(int j=1;j<=cnttmp;++j){
            if(k>j){//tmp[i]i个点最长长度,sum[i]表示数量
                if(ans1<tmp[j]+tmp2[k-j])
                    ans1=tmp[j]+tmp2[k-j],ans2=sum[j]*sum2[k-j];
                else if(ans1==tmp[j]+tmp2[k-j])
                    ans2+=sum[j]*sum2[k-j];
            }
        }
        for(int j=1;j<=cnttmp;++j){
            if(tmp[j]>tmp2[j+1]){
                tmp2[j+1]=tmp[j];sum2[j+1]=sum[j];
            }else if(tmp[j]==tmp2[j+1])
                sum2[j+1]+=sum[j];
            val[++num]=j+1;
        }
        for(int j=1;j<=cnttmp;++j)tmp[j]=sum[j]=0;//记得清掉临时桶
    }
    for(int i=1;i<=num;++i)tmp2[val[i]]=sum2[val[i]]=0;
    sum2[1]=0;
}
void dfz(int x){
    v[x]=1;
    cal(x);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        init(y);
        dfz(rt);
    }
    v[x]=0;
}
void init1(){
    ans1=ans2=0;
    tot=0;
    for(int i=1;i<=n;++i)G[i].clear(),head[i]=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
        init1();
        cin>>n>>m>>k;
        int u,v,w;
        for(int i=1;i<=m;++i){
            cin>>u>>v>>w;
            G[u].pb({v,w});G[v].pb({u,w});
        }
        dij.dij(1);
        S=n;
        mxson[rt=0]=maxn;
        getRoot(1,0);
        dfz(rt);
        cout<<ans1<<" "<<ans2<<"\n";
    
    return 0;
}