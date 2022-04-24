#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
const int mod=998244353,G=3;//原根
const int maxn=2e5+5;
template<typename T>
void read(T &f){ 
    f=0;T fu=1;char c=getchar();
    while(c<'0'||c>'9'){ if(c=='-')fu=-1;c=getchar();}
    while(c>='0'&&c<='9'){ f=(f<<3)+(f<<1)+(c&15);c=getchar();}
    f*=fu;
}

template<typename T>
void print(T x){ 
    if(x<0)putchar('-'),x=-x;
    if(x<10)putchar(x+48);
    else print(x/10),putchar(x%10+48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
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
    poly polyInv(poly f,int base){ 
        int lim=1<<base;
        f.resize(lim);
        if(lim==1){ 
            poly ans(1,mypow(f[0],mod-2));
            return ans;
        }
        poly g(1<<base,0),g0=polyInv(f,base-1),tmp=g0*g0*f;
        for(int i=0;i<(1<<(base-1));++i)g[i]=Add(g0[i],g0[i]);
        for(int i=0;i<(1<<base);++i)g[i]=Sub(g[i],tmp[i]);
        return g;
    }
    poly polyInv(poly f){ 
        int lim=(int)f.size(),base=0;
        while((1<<base)<lim)++base;
        f=polyInv(f,base);f.resize(lim);
        return f;
    }
    
    poly operator+(const poly&a,const poly&b){
        poly c=a;
        c.resize(max(a.size(),b.size()));
        int lim=(int)b.size();
        for(int i=0;i<lim;++i)c[i]=Add(c[i],b[i]);
        return c;
    }

    poly operator-(const poly&a,const poly&b){ 
        poly c=a;
        c.resize(max(a.size(),b.size()));
        int lim=(int)b.size();
        for(int i=0;i<lim;++i)c[i]=Sub(c[i],b[i]);
        return c;
    }

    poly operator*(const int&b,const poly&a){ 
        poly c=a;
        int lim=(int)a.size();
        for(int i=0;i<lim;++i)c[i]=mul(b,c[i]);
        return c;
    }
    
    int inv[maxn<<2];//未知 
    void initInv(){ 
        inv[1]=1;
        for(int i=2;i<maxn;++i)inv[i]=mul(inv[mod%i],(mod-mod/i));
    }
    //多项式求导
    poly deri(poly a){ 
        int lim=(int)a.size()-1;
        for(int i=0;i<lim;++i)a[i]=mul(a[i+1],i+1);
        a.resize(lim);
        return a;
    }
    //多项式积分
    poly inte(poly a){ //记得init inv
        int lim=(int)a.size()+1;
        a.resize(lim);
        for(int i=lim-1;i>=1;--i)a[i]=mul(a[i-1],inv[i]);
        a[0]=0;//原a_0=1才可以用于求ln ln(a_0)=0
        return a;
    }

    poly polyLn(poly a){ 
        int lim=(int)a.size();//
       // a=inte(deri(a)*polyInv(a));//n+m大小 逆元开第一个二次幂
        a=deri(a)*polyInv(a);//mod (x^n)下 [0,n-1]用
        a.resize(lim-1);
        a=inte(a);
      //  a.resize(lim);
        return a;
    }
    
    poly polySqr(poly a,int base){ 
        int lim=1<<base;
        a.resize(lim);
        if(lim==1){ 
            poly ans(1,1);//a[0]=1
            return ans;
        }
        poly g0=polySqr(a,base-1);g0.resize(lim);
        a=a*polyInv(g0)+g0;
        a.resize(lim);
        for(int i=0;i<lim;++i){ 
            if(a[i]&1)a[i]=(a[i]+mod)>>1;
            else a[i]=a[i]>>1;
        }
        return a;
    }
    
    poly polySqr(poly f){ 
        int lim=(int)f.size(),base=0;
        while((1<<base)<lim)++base;
        f=polySqr(f,base);f.resize(lim);
        return f;
    }
}
using namespace Poly;
int n,m;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    poly G,F;
    G.resize(m+1);
    G[0]=0;
    for(int i=1;i<=n;++i){ 
        int a;
        cin>>a;
        if(a>m)continue;
        G[a]++;
    }
    for(int i=1;i<=m;++i){ 
        G[i]=mod-4ll*G[i]%mod;
    }
    G[0]=1;
    G=polySqr(G);
    G[0]=Add(G[0],1);
    F=2*polyInv(G);
    for(int i=1;i<=m;++i)
        cout<<F[i]<<" ";
}
