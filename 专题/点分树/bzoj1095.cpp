#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct EraseHeap{//两个堆维护可删堆
    priority_queue<int>a,b;//a存所有状态,b存无用状态
    void push(int x){
        a.push(x);
    }
    void erase(int x){
        b.push(x);
    }
    void pop(){
        while(!b.empty()&&a.top()==b.top())
            a.pop(),b.pop();
        a.pop();
    }
    int top(){//最大
        while(!b.empty()&&a.top()==b.top())
            a.pop(),b.pop();
        return a.empty()?0:a.top();
    }
    int size(){
        return a.size()-b.size();
    }   
    int stop(){//次大
        if(size()<2)return 0;
        int x=top();pop();
        int y=top();push(x);
        return y;
    }
}a[maxn],b[maxn],ans;//a维护子树节点到其点分树父亲的距离,b维护x儿子的a的最大值(堆顶)
int fa[maxn],mxson[maxn],sz[maxn],rt,S,dfn[maxn],d[maxn],st[maxn<<1][21],lg[maxn<<1],ti;
bool v[maxn],col[maxn];
int n,head[maxn],ver[maxn<<1],next1[maxn<<1],tot,num,m;//num存黑点数量
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int f){
    dfn[x]=++ti;d[x]=d[f]+1;st[ti][0]=x;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        st[++ti][0]=x;
    }
}
void RMQ(){
    for(int i=2;i<=ti;++i)lg[i]=lg[i>>1]+1;
    for(int j=1;j<=lg[ti];++j)
        for(int i=1;(i+(1<<j)-1)<=ti;++i){
            int r=i+(1<<(j-1));
            st[i][j]=d[st[i][j-1]]<d[st[r][j-1]]?st[i][j-1]:st[r][j-1];
        }
}
inline int LCA(int l,int r){
    if(l>r)swap(l,r);
    int k=lg[r-l+1];
    return d[st[l][k]]<d[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}
int dis(int x,int y){
    int lca=LCA(dfn[x],dfn[y]);
    return d[x]+d[y]-2*d[lca];
}
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];  
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
void dfz(int x){
    v[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        init(y);
        fa[rt]=x;
        dfz(rt);
    }
}
void OFF(int x){//考虑 x->i->fa[i]讨论
    b[x].push(0);//自己当端点
    if(b[x].size()==2)ans.push(b[x].top());//自己当端点的情况一条链
    for(int i=x;fa[i];i=fa[i]){//更新
        int f=fa[i];
        int dd=dis(f,x),tmp=a[i].top();
        a[i].push(dd);//更新自己到父亲
        if(dd>tmp){
            int mx=b[f].top()+b[f].stop(),size=b[f].size();
            if(tmp)b[f].erase(tmp);//tmp不在堆顶了
            b[f].push(dd);
            int now=b[f].top()+b[f].stop();
            if(now>mx){
                if(size>=2)ans.erase(mx);//mx原来在里面
                if(b[f].size()>=2)ans.push(now);
            }
        }
    }
}
void ON(int x){
    if(b[x].size()==2)ans.erase(b[x].top());//只剩自己当端点的链删掉
    b[x].erase(0);
    for(int i=x;fa[i];i=fa[i]){
        int f=fa[i];
        int dd=dis(f,x),tmp=a[i].top();
        a[i].erase(dd);
        if(dd==tmp){//可能删的就是堆顶
            int mx=b[f].top()+b[f].stop(),size=b[f].size();
            b[f].erase(dd);
            if(a[i].top())b[f].push(a[i].top());//删除后看看有没有必要更新堆顶
            int now=b[f].top()+b[f].stop();
            if(now<mx){
                if(size>=2)ans.erase(mx);
                if(b[f].size()>=2)ans.push(now);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    RMQ();
    S=n;
    mxson[rt=0]=maxn;
    getRoot(1,0);
    dfz(rt);
    scanf("%d",&m);
    for(int i=1;i<=n;++i)col[i]=1;//黑点
    char s[2];
    for(int i=1;i<=n;++i){
        OFF(i);
        num++;
    }
    for(int i=1;i<=m;++i){
        scanf("%s",s);
        if(s[0]=='G'){
            if(num<=1)cout<<num-1<<"\n";
            else cout<<ans.top()<<"\n";
        }else{
            scanf("%d",&u);
            if(col[u])ON(u),num--;
            else OFF(u),num++;
            col[u]^=1;
        }
    }
    return 0;
}