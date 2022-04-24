#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using P=pair<int,ll>;
const int maxn=1e5+5;
int n,m,a[maxn],f[maxn],big,num,pos[maxn],L[maxn],R[maxn],cnttmpL;//f[i] i的最小值
ll cnt[maxn],sum[maxn];//cnt[i] f[j]=i数量
P tmpL[maxn*2];
struct Q{ 
    int l,r,id;
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
    for(int i=1;i<=num;++i){ 
        for(int j=L[i];j<=R[i];++j)
            pos[j]=i;
    }
}
void addr(int x,ll&ans){ 
    if(f[x]>f[x-1]){ 
        ans+=f[x]-f[x-1];
        cnt[f[x]]--;cnt[f[x-1]]++;f[x]=f[x-1];
    }
}
void addl(int x,ll&ans){ 
    if(!cnt[x+1])return;
    tmpL[++cnttmpL]={x,cnt[x]};
    tmpL[++cnttmpL]={ x+1,cnt[x+1]};
    ans+=cnt[x+1];
    cnt[x]+=cnt[x+1];
    cnt[x+1]=0;
}
void INIT(){ 
    cnttmpL=0;
    for(int i=0;i<=n;++i)f[i]=i+1,cnt[i+1]=1;
}
void Clear(){ 
    while(cnttmpL){ 
        cnt[tmpL[cnttmpL].fi]=tmpL[cnttmpL].se;
        cnttmpL--;
    }
}
int main(){ 
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i){ 
        cin>>q[i].l>>q[i].r;q[i].id=i;
    }
    init();
    sort(q+1,q+1+m);
    INIT();
    for(int i=1,now=1;i<=num;++i){ 
        int pl=R[i]+1,pr=R[i];
        ll nowans=0;
        for(;pos[q[now].l]==i;now++){ 
            if(pos[q[now].l]==pos[q[now].r]){ //同块暴力
                ll tmpans=0;
                for(int j=q[now].l;j<=q[now].r;++j){ 
                    addr(a[j],tmpans);
                }
                for(int j=q[now].l;j<=q[now].r;++j){ 
                    for(int k=a[j]-1;k<=a[j];++k){ 
                        f[k]=k+1;
                        cnt[k+1]=1;
                    }
                }
                sum[q[now].id]=tmpans;
            }else{ 
                while(pr<q[now].r)
                    addr(a[++pr],nowans);
                ll tmp=nowans;
                int tmpL=pl;
                while(pl>q[now].l){ 
                    addl(a[--pl],nowans);
                }
                sum[q[now].id]=nowans;
                if(pos[q[now+1].l]==i){ 
                    Clear();
                }else{ 
                    INIT();
                }
                pl=tmpL;nowans=tmp;
            }
        }
    }
    for(int i=1;i<=m;++i)cout<<sum[i]<<"\n";
    return 0;
}


