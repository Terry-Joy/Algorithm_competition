#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=3e5+5;
int head[maxn],edge[maxn<<1],ver[maxn<<1],next1[maxn<<1];
int fa[maxn],d[maxn],v[maxn],ans[maxn],n,m,tot,li[maxn],cnt=0,LCA[maxn];
int L[maxn],R[maxn],num[maxn],len[maxn],mx=0,mxlen=0,mx2=0;
vector<int>q[maxn],qid[maxn];
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
            LCA[id]=lca;
            ans[id]=min(ans[id],d[x]+d[y]-2*d[lca]);
        }
    }
    v[x]=2;
}
void add_query(int x,int y,int i){
    q[x].pb(y);q[y].pb(x);
    qid[x].pb(i);qid[y].pb(i);
}
void dfs(int x,int f){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i],z=edge[i];
        if(y==f)continue;
        dfs(y,x);
        num[x]+=num[y];
        if(num[y]==cnt)
            mx=max(mx,z);
    }
}
bool check(int x){
    cnt=0;
    mx=-1;mxlen=0;
    for(int i=1;i<=n;++i)num[i]=0;
    for(int i=1;i<=m;++i){
        if(ans[i]>x){
            li[++cnt]=i;
            mxlen=max(mxlen,ans[i]);
        }
    }
    if(!cnt)return 1;
    for(int i=1;i<=cnt;++i){
        num[L[li[i]]]++;num[R[li[i]]]++;
        num[LCA[li[i]]]-=2;
    }
    dfs(1,-1);
    if(mx==-1)return 0;
    return mxlen-mx<=x;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b,c;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=n-1;++i){
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    for(int i=1;i<=m;++i){
        cin>>L[i]>>R[i];
        if(L[i]==R[i])ans[i]=0;
        else{
            add_query(L[i],R[i],i);
            ans[i]=1<<30;
        }
    }
    tarjan(1);
    int l=0,r=3e8+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
}