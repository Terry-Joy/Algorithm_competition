#include<bits/stdc++.h>
#define N maxn*36
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}
    return x*s;
}
inline void in(int&x){
    x=read();
}
const int maxn=2e5+5;
int dp[maxn][2],head[maxn],ver[maxn<<1],next1[maxn<<1],cnt,n,id[maxn];
int a[maxn],b[maxn],m,y;
struct SegmentTree{
    int rt[maxn][6],tot,lc[N],rc[N],num[N];
    void pushUp(int p){
        num[p]=num[ls]+num[rs];
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=++tot;
        if(l==r){
            num[p]+=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int query(int p,int l,int r){
        if(!p)return 0;
        if(l==r)return l;
        int mid=l+r>>1;
        if(num[rs])return query(rson);
        else return query(lson);
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            num[p]+=num[q];return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
}tr;
void add(int x,int y){
    ver[++cnt]=y,next1[cnt]=head[x],head[x]=cnt;
}
void dfs(int x,int fa){
    dp[x][1]=1;
    for(int i=head[x];i;i=next1[i]){
        int v=ver[i];
        if(v==fa)continue;
        dfs(v,x);
        int mx1=tr.query(tr.rt[v][1],1,m),mx2=tr.query(tr.rt[v][0],1,m);
        if(a[x]>mx1&&a[x]>mx2){
            if(dp[v][1]>dp[v][0]){
                dp[x][1]+=dp[v][1];
                tr.rt[x][1]=tr.merge(tr.rt[x][1],tr.rt[v][1],1,m);   
            }else if(dp[v][0]>dp[v][1]{
                dp[x][1]+=dp[v][0];
                tr.rt[x][1]=tr.merge(tr.rt[x][1],tr.rt[v][0],1,m);
            }else{
                dp[x][1]+=dp[v][1];
                tr.rt[x][2]
            }
        }else if(a[x]>mx1){
            dp[x][1]+=dp[v][1];
            tr.rt[x][1]=tr.merge(tr.rt[x][1],tr.rt[v][0],1,m);
        }
        else if(a[x]>mx2){
            dp[x][1]+=dp[v][0];
            tr.rt[x][1]=tr.merge(tr.rt[x][1],tr.rt[v][0],1,m);
        }
        if(dp[v][0]>dp[v][1]){
            dp[x][0]+=dp[v][0];
            tr.rt[x][0]=tr.merge(tr.rt[x][0],tr.rt[v][0],1,m);
        }else{
            dp[x][0]+=dp[v][1];
            tr.rt[x][0]=tr.merge(tr.rt[x][0],tr.rt[v][1],1,m);
        }
    }
    tr.update(tr.rt[x][1],1,m,a[x],1);
}
int main(){
    in(n);
    for(int i=1;i<=n;++i){
        in(a[i]);b[i]=a[i];
        in(y);
        if(i==1)continue;
        add(i,y);
        add(y,i);
    }
    sort(b+1,b+1+n);
    m=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i){
        a[i]=lower_bound(b+1,b+1+m,a[i])-b;
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<"\n";
    return 0;
}