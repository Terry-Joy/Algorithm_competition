**浅谈树$dfs$序与欧拉序与$LCA$结合的相关问题**

声明：

在本文章中，$dfs序$指dfs中点的入栈顺序，而出栈顺序表示该点子树的结尾区间

```cpp
void dfs(int x,int fa){
	in[x]=++ti;
    ....
    out[x]=ti;
}
```



欧拉序长为$2n$,且一般记录对应位置的符号

```cpp
void dfs(int x,int fa){
    in[x]=++ti;f[ti]=1;
    ...
    out[x]=++ti;f[ti]=-1
}
```

两者都可将子树线性化，只是面对不同问题，代码复杂度与维护难度稍有不同，基本上dfs序能做的，欧拉序都能做，有些问题我会列举出来，有些不会

诚然，里面很多问题树剖都可以替代dfs序和欧拉序，但是还是希望大家在遇到**子树线性化与某点到根的链计算**维护的时候可以先思考这两者，再考虑树剖，复杂的树链问题当然就使用树剖了

下面先给出关于这两者的7个经典问题及其解法

**1.树上单点加，子树点权和**

$dfs$序后每个位置维护每个点的权值，所以树状数组单点加，区间查询

**2.$x->y$树上链加，单点查询**

离线树上差分，$x++,y++,LCA[(x,y)]--,fat[LCA(x,y)]--$，子树和查询，只是这里在线，所以$dfs$序转化后，相等于1问题，链加变单点加，单点查询变区间查询，树状数组维护即可

**3.x->y树上链加，子树和查询**

$dfs序$后，修改同2，考虑修改A，查询B，当A是B的子树时，才有$(dep[A]-dep[B]+1)*w$,所以两个树状数组分别维护

$(dep[x]+1)*w$,$w$,答案为$Sum(out[B])-Sum(in[B]-1)-(Sum1(out[B])-Sum1(in[B]-1))*dep[B]$

**4.单点加，x->y路径点权查询**

两种方法：路径点权转化为$+x->rt,+y->rt,-(LCA(x,y)->rt),-(fat[LCA(x,y)]->rt)$

（1）欧拉序后，点到根路径和等价于$Sum(in[x])$,修改就在$in[x]$位置$+=val$,$out[x]$位置$-=w$就好了，树状数组维护，$O(ln(2n))$(更快更好写)

   (2)$dfs$序后，每个位置直接保留$x->rt$的答案，则操作变成$[in[x],out[x]]$区间加，单点查询，线段树维护，$O(logn)$,

**5.子树加，单点查询**

$dfs序$后线段树$[in[x],out[x]]$区间修改，单点查询

**6.子树加，子树查询**

同6差不多，$dfs序$后区间加，区间和，线段树即可

**7.子树加，链权值查询**

链权值查询转为4个点到根查询，$dfs$序后每个位置直接保留$x->rt$的权值和，子树加对于x的子树中y点来说，$+=（1-dep[x])*val+val*dep[y]$，两个树状数组分别维护$(1-dep[x])*val$和$val$，区间修改单点查询差分转单点修改区间前缀和查询即可

答案就是$Sum1(in[x])+Sum2(in[x])*dep[x]$

**8.链路径加，单点查询，子树查询**

比3多了个查询，直接在维护的其中一个树状数组上查就好了

**9.单点加，子树加，链权值查询**

同$7$,多个单点加，只是在$Sum1$这个树状数组内一样做个差分修改即可

我们可以发现对于树上的基本操作，**单点加，单点查询，子树加，子树查询，链加，链查询**，基本上只要查询或者修改只有一种操作，就可以用$dfs序$来维护，不用写树剖,而一般更为常见于子树问题，当然我觉得很多问题**线段树合并**都可以暴力做x

下面是几道相关的题目

**1.bzoj4034**

题意：树上单点加，子树加，路径和

思路：就是9，随便写，当然只是个树剖模板题，带多个$log$而已

```cpp
#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r 
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int a[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,ti,in[maxn],out[maxn],val[maxn<<1],f[maxn<<1];
struct SegmentTree{
    ll sum[maxn<<3],add[maxn<<3];
    void pushDown(int p,int l,int r){
        int mid=l+r>>1;
        sum[ls]+=1ll*(f[mid]-f[l-1])*add[p];
        sum[rs]+=1ll*(f[r]-f[mid])*add[p];
        add[ls]+=add[p];add[rs]+=add[p];
        add[p]=0;   
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            sum[p]+=1ll*(f[r]-f[l-1])*val;
            add[p]+=val;
            return;
        }
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void build(int p,int l,int r){
        add[p]=0;
        if(l==r){
            sum[p]=val[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    ll query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
void dfs(int x,int fa){
    in[x]=++ti;
    val[ti]=a[x];f[ti]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
    out[x]=++ti;
    val[ti]=-a[x];f[ti]=-1;
}
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;    
}
int main(){
    int n,m,q,op;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    int x,y;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    for(int i=1;i<=ti;++i)f[i]+=f[i-1];
    tr.build(1,1,ti);
    for(int i=1;i<=q;++i){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&y);
            tr.update(1,1,ti,in[x],in[x],y);
            tr.update(1,1,ti,out[x],out[x],y);
        }else if(op==2){
            scanf("%d%d",&x,&y);
            tr.update(1,1,ti,in[x],out[x],y);      
        }else if(op==3){
            scanf("%d",&x);
            cout<<tr.query(1,1,ti,1,in[x])<<"\n";
        }
    }
    return 0;
}
```



**2.hdu5692**

题意：求一条从根出发必经x点的最大权值路径

思路：子树问题，想到与$dfs$序有关，显然一个点权值只对他的子树有贡献，直接dfs序建线段树，区间更新区间最大值即可

```cpp
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include<iostream>
#include<cstdio>
#include<algorithm>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r 
#define ls p<<1  
#define rs p<<1|1
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int t,n,m,x,y,head[maxn],ver[maxn<<1],next1[maxn<<1],ti,in[maxn],out[maxn],op,a[maxn],tot;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct SegmentTree{
    ll mx[maxn<<2],add[maxn<<2];
    void pushDown(int p,int l,int r){
        int mid=l+r>>1;
        mx[ls]+=add[p];
        mx[rs]+=add[p];
        add[ls]+=add[p];add[rs]+=add[p];
        add[p]=0;   
    }
    void pushUp(int p){
        mx[p]=max(mx[ls],mx[rs]);
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            mx[p]+=val;
            add[p]+=val;return;
        }
        if(add[p])
            pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    void build(int p,int l,int r){
        add[p]=0;
        if(l==r){
            mx[p]=0;return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    ll query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return mx[p];
        int mid=l+r>>1;
        if(add[p])
            pushDown(p,l,r);
        ll ans=-1e18;
        if(L<=mid)ans=max(ans,query(lson,L,R));
        if(R>mid)ans=max(ans,query(rson,L,R));
        return ans;
    }
}tr;
void dfs(int x,int fa){
    in[x]=++ti;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
    out[x]=ti;
}
int main(){
    scanf("%d",&t);
    int T=0;
    while(t--){
ti=0;
        scanf("%d%d",&n,&m);
        tot=0;//清空
        for(int i=0;i<=n;++i)head[i]=0;
        for(int i=1;i<n;++i){
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        cout<<"Case #"<<++T<<":\n";
        dfs(0,-1);
        tr.build(1,1,n);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            tr.update(1,1,n,in[i],out[i],a[i]);
        }
        for(int i=1;i<=m;++i){
            scanf("%d",&op);
            if(!op){
                scanf("%d%d",&x,&y);
                tr.update(1,1,n,in[x],out[x],y-a[x]);
                a[x]=y;
            }else{
                scanf("%d",&x);
                cout<<tr.query(1,1,n,in[x],out[x])<<"\n";
            }
        }
    }
    return 0;
}

```



**3.hdu 5877**

题意：给一颗有根树，点有非负权值，问有多少对$u,v$满足$u$是$v$的祖先且$a_u*a_v\leq k$

思路:

第一个条件显然是个一维偏序关系，可以考虑dfs直接化去，这题可以考虑一个点只对子树有贡献，或者一个点只被祖先贡献，这里我采取后者，$dfs$的时候查询$<=k/a_v$的个数，然后单点增加，回溯的时候再单点减少即可。所以只需要离散化后用树状数组维护即可，当然也可以在回溯的时候考虑第一种方法，考虑每个点对子树的贡献，直接在$dfs$序上单点修改，区间查询即可

这题需要注意，当$a[i]$为0的时候，$k/a[i]$应该设为无穷

当然这题是子树问题，也可以用线段树合并暴力自底向下统计

```cpp
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll INF=2e18;
int t,ver[maxn<<1],head[maxn],next1[maxn<<1],tot,n,m,deg[maxn];
ll a[maxn<<1],b[maxn<<1],ans=0,k;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
int ask(ll x){
    return lower_bound(b+1,b+1+m,x)-b;
}
struct BIT{
    int c[maxn<<1],N;
    void init(int x){
        this->N=x;
        for(int i=0;i<=x;++i)c[i]=0;
    }
    int query(int x){
        int ans=0;
        while(x){
            ans+=c[x];
            x-=lowbit(x);
        }
        return ans;
    }
    void add(int x,int val){
        while(x<=N){
            c[x]+=val;
            x+=lowbit(x);
        }
    }
}bit;
void dfs(int x,int fa){
    int pos=(a[x]?ask(k/a[x]):m),pos2=ask(a[x]);
    ans+=bit.query(pos);
    bit.add(pos2,1);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
    bit.add(pos2,-1);
}
int main(){
    scanf("%d",&t);
    while(t--){
        ans=0;
        tot=0;
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;++i)head[i]=0,deg[i]=0;
        for(int i=1;i<=n;++i){
            scanf("%lld",&a[i]);
            if(!a[i])a[i+n]=INF;
            else a[i+n]=k/a[i];
            b[i]=a[i];
            b[i+n]=a[i+n];
        }
        for(int i=1;i<n;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
            deg[y]++;
        }
        int rt=0;
        for(int i=1;i<=n;++i){
            if(!deg[i]){rt=i;break;}
        }
        sort(b+1,b+1+2*n);
        m=unique(b+1,b+1+2*n)-(b+1);
        bit.init(m);
        dfs(rt,0);
        cout<<ans<<'\n';
    }
    return 0;
}
```

