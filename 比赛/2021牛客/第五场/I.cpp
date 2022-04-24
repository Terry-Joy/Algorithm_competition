#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=998244353;
int a[maxn],pos[maxn],L[maxn],R[maxn],big,n,m,num,pre[maxn],nxt[maxn],cnt[maxn],ans[maxn],tot,Tong[maxn];
struct Q{ 
    int l,r,k,id;
    bool operator<(const Q&x)const{ 
        return (pos[l]^pos[x.l])?(pos[l]<pos[x.l]):r<x.r;
    }
}q[maxn];
void init(){ 
    big=sqrt(n);
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){ 
        L[i]=R[i-1]+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i)
        for(int j=L[i];j<=R[i];++j)
            pos[j]=i;
}
void add(int x,int&ans){ 
    cnt[x]++;
    if(cnt[x]==1){ 
        pre[x]=nxt[x]=x;
        if(cnt[x-1])pre[x]=pre[x-1];
        if(cnt[x+1])nxt[x]=nxt[x+1];
        if(pre[x])nxt[pre[x]]=nxt[x];
        if(nxt[x])pre[nxt[x]]=pre[x];
        ans=max(ans,nxt[x]-pre[x]+1);
    }
}
void del(int x){ 
    cnt[x]--;
    if(!cnt[x]){ 
        pre[x]=nxt[x]=0;//保证链的端点对就好了
        if(pre[x-1])
            nxt[pre[x-1]]=nxt[x-1]=x-1;
        if(nxt[x+1])
            pre[nxt[x+1]]=pre[x+1]=x+1;
    }
}
void Clear(int x){ 
    cnt[x]=pre[x]=nxt[x]=0;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i){ 
        cin>>q[i].l>>q[i].r>>q[i].k;
        q[i].id=i;
    }
    sort(q+1,q+1+m);
    for(int i=1,now=1;i<=num;++i){ //枚举块
        int pl=R[i]+1,pr=R[i];//
        for(int i=1;i<=n;++i)cnt[i]=pre[i]=nxt[i]=0;
        int nowans=0;
        for(;pos[q[now].l]==i;now++){ 
            if(pos[q[now].l]==pos[q[now].r]){  //同块暴力
                int tmpans=0,sum=0;
                int k=q[now].k;
                for(int j=q[now].l;j<=q[now].r;++j){ 
                    add(a[j],tmpans);
                    Tong[++tot]=a[j];
                }
                sum+=tmpans;
                int tmpL=q[now].l,tmpR=q[now].r;
                for(int j=1,f=(n+1);j<=k-1;++j,f=(ll)f*(n+1)%mod){ 
                    add(a[tmpL-j],tmpans);
                    add(a[tmpR+j],tmpans);
                    Tong[++tot]=a[tmpL-j],Tong[++tot]=a[tmpR+j];
                    sum=(sum+(ll)tmpans*f)%mod;
                }
                while(tot)del(Tong[tot--]);
               // for(int j=tmpL-(k-1);j<=tmpR+(k-1);++j)
                 //   Clear(a[j]);
                ans[q[now].id]=sum;
            }else{ //不同块右端点单调，左端点回滚
                int sum=0,k=q[now].k;
                while(pr<q[now].r)
                    add(a[++pr],nowans);
                int tmp=nowans,tmpL=pl;
                while(pl>q[now].l){ 
                    add(a[--pl],nowans),Tong[++tot]=a[pl];
                }
                sum+=nowans;
                sum%=mod;
                for(int j=1,f=(n+1);j<=k-1;++j,f=(ll)f*(n+1)%mod){ 
                    add(a[pl-j],nowans);
                    add(a[pr+j],nowans);
                    Tong[++tot]=a[pl-j],Tong[++tot]=a[pr+j];
                    sum=(sum+(ll)nowans*f)%mod;
                }
                ans[q[now].id]=sum;
                if(pos[q[now+1].l]==i){ //注意回滚的时候是当前块全部回滚还是只回滚一个询问
                    while(tot)del(Tong[tot--]);
                }else{ 
                    for(int j=pl-(k-1);j<=pr+(k-1);++j)Clear(a[j]);
                    tot=0;
                }
                pl=tmpL,nowans=tmp;
            }
        }
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
    return 0;
}   

