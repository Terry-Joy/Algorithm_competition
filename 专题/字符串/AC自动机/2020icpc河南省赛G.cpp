//可持久化线段树维护大字符集ac自动机
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int M=100000;//字符集大小
const int maxn=1e5+5;//ac点数
const int N=maxn*36;
vector<int>G[maxn],G1[maxn];
int n,mxp;
ll sz[maxn];
struct AC{
    #define ls lc[p]
    #define rs rc[p]
    #define lson lc[p],l,mid 
    #define rson rc[p],mid+1,r 
    unordered_map<int,int>tran[maxn];
    int lc[N],rc[N],val[N],fail[maxn],trie[maxn],tot,cnt;
    queue<int>q;
    void build(int&p,int l,int r){
        p=++tot;
        if(l==r){
            if(tran[0].find(l)!=tran[0].end())val[p]=tran[0][l];
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void update(int q,int&p,int l,int r,int pos,int num){
        p=++tot;
        ls=lc[q],rs=rc[q],val[p]=val[q];
        if(l==r){
            val[p]=num;return;
        }
        int mid=l+r>>1;
        if(pos<=mid)update(lc[q],lson,pos,num);
        else update(rc[q],rson,pos,num);
    }
    int query(int p,int l,int r,int pos){
        if(l==r)return val[p];
        int mid=l+r>>1;
        if(pos<=mid)return query(lson,pos);
        else return query(rson,pos);
    }
    void insert(int u,int v,int w){
        tran[u][w]=v;
    }
    void getFail(){ 
        build(trie[0],1,mxp);
        for(auto&[k,v]:tran[0]){
            q.push(v);
        }
        while(!q.empty()){
            int x=q.front();q.pop();
            trie[x]=trie[fail[x]];
            for(auto&[k,v]:tran[x]){
                update(trie[x],trie[x],1,mxp,k,v);
                //cout<<"caonima"<<"\n";
                fail[v]=query(trie[fail[x]],1,mxp,k);
                // cout<<val[3]<<"\n";
                // if(v==3)cout<<fail[v]<<' '<<trie[fail[x]]<<" "<<k<<"\n";
                q.push(v);
            }
        }
        for(int i=1;i<=n;++i)G1[fail[i]].pb(i);
    }
}ac;
void dfs(int x){
    for(auto&v:G[x]){
        dfs(v);
        sz[x]+=sz[v];
    }
}
void dfs1(int x){
    for(auto&v:G1[x]){
        dfs1(v);
        sz[x]+=sz[v];
    }
}
int main(){ 
    cin>>n;
    int u,v,w;
    for(int i=1;i<=n;++i){
        cin>>u>>v>>w;
        mxp=max(mxp,w);
        G[u].pb(v);
        ac.insert(u,v,w);
    }
    ac.getFail();
    for(int i=1;i<=n;++i)sz[i]=1;
    dfs(0);dfs1(0);
    //for(int i=0;i<=n;++i)cout<<ac.trie[i]<<"\n";
    for(int i=1;i<=n;++i)cout<<sz[i]<<"\n";
    // for(int i=1;i<=n;++i)cout<<ac.fail[i]<<"\n";
    return 0;
}
