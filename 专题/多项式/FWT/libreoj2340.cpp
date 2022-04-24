#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=(1<<22)+100;
const int mod=998244353;
int sum[maxn],g[23][maxn],f[23][maxn],inv[maxn],n,m,p,u[maxn],v[maxn],w[maxn];
bool ok[maxn];
int fa[maxn],deg[25],bit[maxn];
int find(int x){ 
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){
    int S=(1<<n);
    for(int i=0;i<S;++i){ 
        int num=0;
        for(int j=1;j<=n;++j){ 
            if((1<<(j-1))&i)sum[i]+=w[j],num++;
            fa[j]=j;deg[j]=0;
        }
        bit[i]=num;
        for(int j=1;j<=m;++j){ 
            if(((1<<(u[j]-1))&i)&&((1<<(v[j]-1))&i)){ 
                int xx=find(u[j]),yy=find(v[j]);
                if(xx!=yy){ 
                    fa[xx]=yy;
                    num--;
                }
                deg[u[j]]++;deg[v[j]]++;
            }
        }
        if(num!=1)ok[i]=1;
        int flag=0;
        for(int j=1;j<=n;++j){ 
            flag+=(deg[j]&1);
        }
        if(flag)ok[i]=1;
        if(ok[i])g[bit[i]][i]=mypow(sum[i],p);
        inv[i]=mypow(mypow(sum[i],p),mod-2);
    }
}
inline int Add(int x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
inline int Sub(int x,int y){ 
    x-=y;
    if(x<0)x+=mod;
    return x;
}
inline int mul(int x,int y){ 
    return (ll)x*y%mod;
}
void fwt(int a[],bool f,int lim){ 
    for(int l=2,m=1;l<=lim;l<<=1,m<<=1){ 
        for(int j=0;j<lim;j+=l){ 
            for(int i=0;i<m;++i){ 
                if(!f)a[i+j+m]=Add(a[i+j+m],a[i+j]);
                else a[i+j+m]=Sub(a[i+j+m],a[i+j]);
            }
        }
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>p;
    int lim=1<<n;
    for(int i=1;i<=m;++i){ 
        cin>>u[i]>>v[i];
    }
    for(int i=1;i<=n;++i)cin>>w[i];
    init();
   // for(int i=0;i<(1<<n);++i)cout<<(int)ok[i]<<" ";
    for(int i=0;i<=n;++i)fwt(g[i],0,lim);
    f[0][0]=1;
    fwt(f[0],0,lim);
    for(int i=1;i<=n;++i){ 
        for(int j=0;j<=i-1;++j){ 
            for(int k=0;k<lim;++k){ 
                f[i][k]=Add(f[i][k],mul(f[j][k],g[i-j][k]));
            }
        }
        fwt(f[i],1,lim);
        for(int k=0;k<lim;++k){ 
            f[i][k]=mul(f[i][k],inv[k]);
        }
        if(i!=n)
            fwt(f[i],0,lim);
    }
    cout<<f[n][lim-1];
    return 0;
}
