#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
const int N=1e5+5;
const int mod=998244353,G=3;
typedef long long ll;
template<typename T>
void read(T &f){ 
    f=0;T fu=1;char c=getchar();
    while(c<'0'||c>'9'){ if(c=='-')fu=-1;c=getchar();}
    while(c>='0'&&c<='9'){ f=(f<<3)+(f<<1)+(c&15);c=getchar();}
    f*=fu;
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

inline int mul(int x,int y){ return 1ll*x*y%mod;}

int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=mul(ans,a);
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}
int a[maxn],b[maxn],c[maxn],fac[maxn],facinv[maxn],f[maxn];
namespace Poly{ 
    typedef vector<int>poly;
    poly roots,rev;
    void getRevRoot(int base){ 
        int lim=1<<base;
        if((int)roots.size()==lim)return;
        roots.resize(lim);rev.resize(lim);
        for(int i=1;i<lim;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<(base-1));
        for(int mid=1;mid<lim;mid<<=1){ 
            int wn=mypow(G,(mod-1)/(mid<<1));
            roots[mid]=1;
            for(int i=1;i<mid;++i)roots[mid+i]=mul(roots[mid+i-1],wn);
        }
    }
    
    void ntt(poly&a,int base){ 
        int lim=1<<base;
        for(int i=0;i<lim;++i)if(i<rev[i])swap(a[i],a[rev[i]]);
        for(int mid=1;mid<lim;mid<<=1){ 
            for(int i=0;i<lim;i+=(mid<<1)){ 
                for(int j=0;j<mid;++j){ 
                    int x=a[i+j],y=mul(a[i+j+mid],roots[j+mid]);
                    a[i+j]=Add(x,y);
                    a[i+j+mid]=Sub(x,y);
                }
            }
        }
    }

    poly operator*(poly a,poly b){ 
        int lim=(int)a.size()+(int)b.size()-1,base=0;
        while((1<<base)<lim)++base;
        a.resize(1<<base);b.resize(1<<base);
        getRevRoot(base);
        ntt(a,base);ntt(b,base);
        for(int i=0;i<(1<<base);++i)a[i]=mul(a[i],b[i]);
        ntt(a,base);
        reverse(a.begin()+1,a.end());
        a.resize(lim);
        int inv=mypow(1<<base,mod-2);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],inv);
        return a;
    }
    poly solve(int l,int r){ 
        if(l==r){ 
            return { c[l],b[l]};
        }
        int mid=l+r>>1;
        return solve(l,mid)*solve(mid+1,r);
    }
}
void init(){ 
    fac[0]=fac[1]=1;
    for(int i=2;i<N;++i)fac[i]=(ll)fac[i-1]*i%mod;
    facinv[N-1]=mypow(fac[N-1],mod-2);
    for(int i=N-2;i>=0;--i){ 
        facinv[i]=(ll)facinv[i+1]*(i+1)%mod;
    }
}
using namespace Poly;
int main(){ 
    int t,n;
    read(t);
    init();
    while(t--){ 
        read(n);
        for(int i=0;i<=n;++i)read(a[i]);
        for(int i=2;i<=n;++i)read(b[i]);
        for(int i=2;i<=n;++i)read(c[i]);
        auto g=solve(2,n);
        vector<int>f;
        f.resize(n+1);
        for(int i=0;i<=n;++i)f[i]=mul(a[i],fac[i]);
        reverse(f.begin(),f.end());
        f=g*f;
        for(int i=0;i<n;++i){ 
            cout<<(ll)f[n-i]*facinv[i]%mod<<" ";
        }
        cout<<(ll)f[0]*facinv[n]%mod<<"\n";
    }
    return 0;
}
