#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=4e5+100;
const int N=1e5+10;
const int mod=998244353,G=3;
int a[maxn];
namespace Poly{ 
    typedef vector<int>poly;
    poly roots,rev;
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
    inline int mul(int x,int y){ return (ll)x*y%mod;}
    int mypow(int a,int b){ 
        int ans=1;
        while(b){ 
            if(b&1)ans=(ll)ans*a%mod;
            a=(ll)a*a%mod;
            b>>=1;
        }
        return ans;
    }
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
            poly x(2);
            x[0]=1;x[1]=a[l];
            return x;
        }
        int mid=l+r>>1;
        return solve(l,mid)*solve(mid+1,r);
    }
}
using namespace Poly;
int fac[maxn],facinv[maxn];
void init(){ 
    fac[1]=fac[0]=1;
    for(int i=2;i<N;++i)fac[i]=(ll)fac[i-1]*i%mod;
    facinv[N-1]=mypow(fac[N-1],mod-2);
    for(int i=N-2;i>=0;--i)
        facinv[i]=(ll)facinv[i+1]*(i+1)%mod;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t,n;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        auto f=solve(1,n);
        int ans=0;
        for(int i=1;i<=n;++i){ 
            ans=Add(ans,mul(f[i],mul(fac[i],fac[n-i])));
        }
        cout<<mul(ans,facinv[n])<<"\n";
    }
    return 0;
}
