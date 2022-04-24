#include<bits/stdc++.h>
#define cbit(x) __builtin_popcount(x)
using namespace std;
using ll=long long;
const int maxn=(1<<20)+100;
const int mod=1e9+9;
int a[22][maxn],b[22][maxn],c[22][maxn];
inline int mul(int x,int y){ return (ll)x*y%mod;}
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
int getlim(int x){ 
    int lim=1;
    while(lim<x)lim<<=1;
    return lim;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int lim=(1<<n);
    for(int i=0;i<lim;++i)cin>>a[cbit(i)][i];
    for(int i=0;i<lim;++i)cin>>b[cbit(i)][i];
    for(int i=0;i<=n;++i)fwt(a[i],0,lim);
    for(int i=0;i<=n;++i)fwt(b[i],0,lim);
    for(int i=0;i<=n;++i){ 
        for(int j=0;i+j<=n;++j){ 
            for(int k=0;k<lim;++k)
                c[i+j][k]=Add(c[i+j][k],mul(a[i][k],b[j][k]));
        }
    }
    for(int i=0;i<=n;++i)fwt(c[i],1,lim);
    for(int i=0;i<((1<<n)-1);++i)cout<<c[cbit(i)][i]<<" ";
    cout<<c[n][(1<<n)-1];
    return 0;
}
