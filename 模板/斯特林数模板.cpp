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
        for(int i=2;i<maxn;++i)inv[i]=mul(inv[mod%i],(mod-mod/i));//跑2倍
    }
    //多项式求导
    poly deri(poly a){ 
        int lim=(int)a.size()-1;
        for(int i=0;i<lim;++i)a[i]=mul(a[i+1],i+1);
        a.resize(lim);
        return a;
    }
    //多项式积分
    poly inte(poly a){ //!!记得init inv
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

    poly polyExp(poly f,int base){ 
        int lim=1<<base;f.resize(lim);
        if(lim==1){ 
            poly ans(1,1);
            return ans;
        }
        poly g0=polyExp(f,base-1),g(1,1);
        g0.resize(lim);//同样%x^n下,所以要两倍
        g=g0*(g-polyLn(g0)+f);
        return g;
    }

    poly polyExp(poly f){ 
        int lim=(int)f.size(),base=0;
        while((1<<base)<lim)++base;
        f=polyExp(f,base);f.resize(lim);
        return f;
    }
   
    poly polyPow(poly a,int k){ //a_0=1 多项式系数mod 998244353下算
        return polyExp(k*polyLn(a));
    }
 
   poly polyPow(poly a){ 
        int n,c,k=0;
        scanf("%d",&n);
        a.resize(n);
        c=getchar();while(isspace(c))c=getchar();//k是int直接读
        for(;isdigit(c);c=getchar())k=(k*10ll+(c^'0'))%mod;
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        return polyPow(a,k);
    }
	int norm(int n){return 1<<(32-__builtin_clz(n-1));}
	void norm(poly &a){ 
		if(!a.empty()){
			a.resize(norm(a.size()),0);
		}else
			a={0};
	}
	poly polyPow2(poly a,int b1,int b2){//b1=b%P,b2=b%phi(P) and b>=n iff a[0]>0
		int n=a.size(),d=0,k;
		while(d<n&&!a[d])++d;
		if((ll)d*b1>=n)return poly(n,0);
		a.erase(a.begin(),a.begin()+d);
		k=mypow(a[0],mod-2);
		a=k*a;
		norm(a);
		a=mypow(k,mod-1-b2)*polyPow(a,b1);
		a.resize(n);d*=b1;
		for(int i=n-1;i>=0;--i)a[i]=i>=d?a[i-d]:0;
		return a;
	}
	void P5273(){//A(x)^s次方 s是大数
		int n;
		int k1 = 0, k2 = 0, big = 0; string s;
		cin >> n >> s;
		poly a(n,0);
		for(auto c: s){
			k1 = (10ll * k1 + c - '0') % mod,
			k2 = (10ll * k2 + c - '0') % (mod - 1), big = big || k1 >= n;
		}
		for (auto &x: a) 
			cin >> x;
		a = big && !a[0] ? poly(n,0) : polyPow2(a, k1, k2);
		for (auto x : a)
			cout<<x<<" ";
	}
}
const int N=3e5+5;
int fac[N],facinv[N]; 
void init(int n){ 
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=mul(fac[i-1],i);
	facinv[n]=mypow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)facinv[i]=mul(facinv[i+1],i+1);
}
using namespace Poly;
namespace Stiring{
 
    namespace Stiring1{ 
        poly Offset(poly f,int c){ //f(x)->f(x+c)
            poly g(c+1),h(c+1);
            for(int i=0,j=1;i<=c;++i,j=(ll)j*c%mod){ 
                h[i]=mul(j,facinv[i]);
                g[i]=mul(f[c-i],fac[c-i]);
            }
            g=g*h;
            for(int i=0;i<=c;++i)h[i]=mul(g[c-i],facinv[i]);
            return h;
        }
        poly Solve(int n){//x^(up n) 
            if(!n)return { 1};
            int m=n/2;
            poly f=Solve(m),g=Offset(f,m);
            f=f*g;
            f.resize(n+1);
            if(n&1){//乘上(x+n-1) 
                for(int i=n;i>=0;--i){ 
                    f[i]=mul(f[i],n-1);
                    if(i>0)
                        f[i]=Add(f[i],f[i-1]);
                }
            }
            return f;
        }
        poly Stiring1_row(int n){ 
            init(n+1);
            return Solve(n);
        }
		poly Stiring1_line(int n,int k){ 
			poly f(n+1);
			int fack=1;
			for(int i=1;i<=k;++i)fack=(ll)fack*i%mod;
			fack=mypow(fack,mod-2);
			for(int i=0;i<=n;++i)f[i]=inv[i];//记得initInv()
			f=polyPow2(f,k,k);
			for(int i=0,fac=1;i<=n;++i,fac=(ll)fac*i%mod)f[i]=(ll)f[i]*fack%mod*fac%mod;
			f.resize(n+1);
			return f;
		}
		vector<vector<int>> Stiring1All(int n,int m){//n行,m列
			vector<vector<int>>dp(n+1,vector<int>(m+1,0));
			dp[0][0]=1;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					dp[i][j]=(dp[i-1][j-1]+(ll)(i-1)*dp[i-1][j])%mod;
			return dp;
		}
    }
	namespace Stiring2{
		poly Stiring2_row(int n,int m){//第n行的[0,m]列
			poly f(m+1),g(m+1);
			init(m+1);
			for(int i=0;i<=m;++i)f[i]=mul(mypow(-1,i),facinv[i]);
			for(int i=0;i<=m;++i)g[i]=mul(mypow(i,n),facinv[i]);
			f=f*g;
			f.resize(m+1);
			return f;
		}
		poly Stiring2_line(int n,int k){//第k列 [0,n] 
			poly f(n+1,0);
			init(n+1);
			for(int i=1;i<=n;++i)f[i]=facinv[i];//f[0]=0;
			f=polyPow2(f,k,k);
			for(int i=0;i<=n;++i)f[i]=(ll)f[i]*facinv[k]%mod*fac[i]%mod;
			f.resize(n+1);
			return f;
		}
		vector<vector<int>> Stiring2All(int n,int m){//n行,m列
			vector<vector<int>>dp(n+1,vector<int>(m+1,0));
			dp[0][0]=1;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					dp[i][j]=(dp[i-1][j-1]+(ll)j*dp[i-1][j])%mod;
			return dp;
		}
	}
}
namespace Bell{
	//cal B[1,n]
	poly BellAll(int n){
		init(n+1);
		poly ans(n+1,0);
		for(int i=1;i<=n;++i)ans[i]=facinv[i];
		return polyExp(ans);
	}
	
}
using namespace Stiring;
using namespace Stiring1;
using namespace Stiring2;
using namespace Bell;
int main(){ 
    //int n,k;
    initInv();

    int n,k,T;
	read(T);
	poly dd=BellAll(100001);
	//for(int i=1;i<=n;++i)cout<<facinv[i]<<" ";
	while(T--){
		read(n);
		cout<<(ll)dd[n]*fac[n]%mod<<"\n";
	}
}