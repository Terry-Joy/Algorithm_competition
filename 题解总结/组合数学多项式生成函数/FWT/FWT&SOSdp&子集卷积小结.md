## FWT&SOSdp&子集卷积小结

先补上这篇欠了老久的博客

$FWT$是用于多项式位运算卷积的一种线性变换的方法

**一些性质**

$FWT(A±B)=FWT(A)±FWT(B)$

$FWT(A⊕B)=FWT(A)∗FWT(B) (对应相乘)$



下面不会给出具体证明

$OR$运算

$FWT(A)[i]=\sum\limits_{j|i=i}A_j$  ,也就是下标子集和

$AND$运算

$FWT(A)[i]=\sum\limits_{j\&i=j}A_j$  ,同样是下标子集和

$XOR$运算

$FWT(A)[i]=\sum\limits_{d(i\&j)mod2=0}A_j-\sum\limits_{d(i\&j)mod1=0}A_j$ 

$d(i)$表示二进制中$i$中1的个数



一些题目：

**1.BZOJ 4589**

题意：问多少种方案使得异或和为0

思路：

显然每次转移可以看成是两个多项式的异或卷积，构造出初始的质数多项式$F$，答案是$F^n[0]$,  但是我们不必做n次FWT，只需要一次$FWT$后快速幂即可

```cpp

#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
const int mod=1e9+7;
const int maxn=1e5+10;
const int N=5e4+10;
const int G=3;
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
    poly inte(poly a){ 
        int lim=(int)a.size()+1;
        a.resize(lim);
        for(int i=lim-1;i>=1;--i)a[i]=mul(a[i-1],mypow(i,mod-2));//稳健
        a[0]=0;//原a_0=1才可以用于求ln ln(a_0)=0
        return a;
    }

    poly polyLn(poly a){ 
        int lim=(int)a.size();//
        a=inte(deri(a)*polyInv(a));//n+m大小 逆元开两倍 只要[0,n-1]用注释的
        /*a=deri(a)*polyInv(a);
        a.resize(lim);
        a=inte(a);*/
        a.resize(lim);
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
   
    //FWT
    void FWT_OR(poly&a,bool f){ 
        int n=a.size();
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    if(!f)
                        a[i+j+m]=Add(a[i+j+m],a[i+j]);
                    else
                        a[i+j+m]=Sub(a[i+j+m],a[i+j]);
                }
        }
    }
    void FWT_AND(poly&a,bool f){ 
        int n=a.size();
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    if(!f)
                        a[i+j]=Add(a[i+j],a[i+j+m]);
                    else
                        a[i+j]=Sub(a[i+j],a[i+j+m]);
                }
        }
    }
    void FWT_XOR(poly&a,bool f){ 
        int n=a.size(),inv2=mypow(2,mod-2);
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    int x=a[i+j],y=a[i+j+m];
                    if(!f){ 
                        a[i+j]=Add(x,y);
                        a[i+j+m]=Sub(x,y);
                    }else{ 
                        a[i+j]=mul(Add(x,y),inv2);
                        a[i+j+m]=mul(Sub(x,y),inv2);
                    }
                }
        }
    }
    int getlim(int x){ //[0,m]项 传 m+1进来
        int lim=1;
        while(lim<x)lim<<=1;
        return lim;
    }
    poly OR(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_OR(a,0);
        FWT_OR(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_OR(a,1);
        return a;
    }
    poly AND(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_AND(a,0);
        FWT_AND(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_AND(a,1);
        return a;
    }
    poly XOR(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_XOR(a,0);
        FWT_XOR(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_XOR(a,1);
        return a;
    }
}
using namespace Poly;
bool v[N];
int prime[N];
void pr(){ 
    v[1]=1;
    for(int i=2;i<N;++i){ 
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<N;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    pr();
    while(cin>>n>>m){
        vector<int>a;
        a.resize(m+1);
        for(int i=1;i<=cnt&&prime[i]<=m;++i)a[prime[i]]=1;
        int lim=getlim(m+1);//+1
        a.resize(lim);
        FWT_XOR(a,0);
        for(int i=0;i<lim;++i)a[i]=mypow(a[i],n);
        FWT_XOR(a,1);
        cout<<a[0]<<"\n";
    } 
    return 0;
}

```



**2.hdu 5909**

题意：

给一颗$n$个节点的树，点有点权，问有多少个非空子树权值异或和等于$k$，$k$从$[0,m)$

思路：

显然有个$dp$，$dp[i][j]$表示以$i$为根的子树中异或和为$j$的方案数为多少，这样每次转移相当于一次异或卷积，所以做$n$次$fwt$即可，复杂度$O(Tnmlogm)$

```cpp
#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ull=unsigned long long;
using ll=long long;
const int mod=1e9+7,G=3;//原根
const int maxn=1e5+5;
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
    poly inte(poly a){ 
        int lim=(int)a.size()+1;
        a.resize(lim);
        for(int i=lim-1;i>=1;--i)a[i]=mul(a[i-1],mypow(i,mod-2));//稳健
        a[0]=0;//原a_0=1才可以用于求ln ln(a_0)=0
        return a;
    }

    poly polyLn(poly a){ 
        int lim=(int)a.size();//
        a=inte(deri(a)*polyInv(a));//n+m大小 逆元开两倍 只要[0,n-1]用注释的
        /*a=deri(a)*polyInv(a);
        a.resize(lim);
        a=inte(a);*/
        a.resize(lim);
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
   
    //FWT
    void FWT_OR(poly&a,bool f){ 
        int n=a.size();
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    if(!f)
                        a[i+j+m]=Add(a[i+j+m],a[i+j]);
                    else
                        a[i+j+m]=Sub(a[i+j+m],a[i+j]);
                }
        }
    }
    void FWT_AND(poly&a,bool f){ 
        int n=a.size();
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    if(!f)
                        a[i+j]=Add(a[i+j],a[i+j+m]);
                    else
                        a[i+j]=Sub(a[i+j],a[i+j+m]);
                }
        }
    }
    void FWT_XOR(poly&a,bool f){ 
        int n=a.size(),inv2=(mod+1)>>1;
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    int x=a[i+j],y=a[i+j+m];
                    if(!f){ 
                        a[i+j]=Add(x,y);
                        a[i+j+m]=Sub(x,y);
                    }else{ 
                        a[i+j]=mul(Add(x,y),inv2);
                        a[i+j+m]=mul(Sub(x,y),inv2);
                    }
                }
        }
    }
    int getlim(int x){ 
        int lim=1;
        while(lim<x)lim<<=1;
        return lim;
    }
    poly OR(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_OR(a,0);
        FWT_OR(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_OR(a,1);
        return a;
    }
    poly AND(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_AND(a,0);
        FWT_AND(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_AND(a,1);
        return a;
    }
    poly XOR(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_XOR(a,0);
        FWT_XOR(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_XOR(a,1);
        return a;
    }
}
using namespace Poly;
vector<int>g[maxn];
int dp[maxn][(1<<10)+10],ans[(1<<10)+10],n,k,t,m,vi[maxn];
poly dfs(int x,int fa){ 
    poly tmp;
    tmp.resize(m);
    tmp[vi[x]]=1;
    for(auto&v:g[x]){ 
        if(v==fa)continue;
        auto it=dfs(v,x);
        auto nxt=XOR(tmp,it);
        for(int i=0;i<m;++i)tmp[i]=Add(tmp[i],nxt[i]);
    }
    for(int i=0;i<m;++i)ans[i]=Add(ans[i],tmp[i]);
    return tmp;
}
int main(){ 
    //initInv();
    read(t);
    while(t--){ 
        read(n);read(m);
        for(int i=1;i<=n;++i)read(vi[i]),g[i].clear();
        for(int i=0;i<m;++i)ans[i]=0;
        int u,v;
        for(int i=1;i<n;++i){ 
            read(u);read(v);
            g[u].eb(v);g[v].eb(u);
        }
        dfs(1,0);
        for(int i=0;i<m-1;++i)cout<<ans[i]<<" ";
        cout<<ans[m-1]<<"\n";
    }
}


```



**3.cf 662C**

题意：

有一个$n$行$m$列的表格(n<=20,m<=105n<=20,m<=105)，
每个表格里面有一个$0/1$，
每次可以将一行或者一列的$01$全部翻转
回答表格中最少有多少个1

思路：

观察到$n$很小，考虑状压，暴力枚举行的状态，然后列状态贪心选择，但是这样的复杂度是$O(2^nm)$的，我们发现事实上列的状态也只有$2^n$种而已，所以我们可以合并相同状态的列，记$f[i]$表示列状态为$i$的数目，$g[i]$为$i$状态下最少的1的个数, $ans[i]$表示行翻转状态为$i$下的答案，然后$ans[i]=\sum f[i]g[j]$

即做$f$和$g$异或卷积下的答案

```cpp
#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
const int mod=998244353,G=3;//原根
const int maxn=1e5+5;
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
    typedef vector<ll>poly;
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
    poly inte(poly a){ 
        int lim=(int)a.size()+1;
        a.resize(lim);
        for(int i=lim-1;i>=1;--i)a[i]=mul(a[i-1],mypow(i,mod-2));//稳健
        a[0]=0;//原a_0=1才可以用于求ln ln(a_0)=0
        return a;
    }

    poly polyLn(poly a){ 
        int lim=(int)a.size();//
        a=inte(deri(a)*polyInv(a));//n+m大小 逆元开两倍 只要[0,n-1]用注释的
        /*a=deri(a)*polyInv(a);
        a.resize(lim);
        a=inte(a);*/
        a.resize(lim);
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
   
    //FWT
    void FWT_OR(poly&a,bool f){ 
        int n=a.size();
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    if(!f)
                        a[i+j+m]=Add(a[i+j+m],a[i+j]);
                    else
                        a[i+j+m]=Sub(a[i+j+m],a[i+j]);
                }
        }
    }
    void FWT_AND(poly&a,bool f){ 
        int n=a.size();
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    if(!f)
                        a[i+j]=Add(a[i+j],a[i+j+m]);
                    else
                        a[i+j]=Sub(a[i+j],a[i+j+m]);
                }
        }
    }
    void FWT_XOR(poly&a,bool f){ 
        int n=a.size();
        for(int l=2,m=1;l<=n;l<<=1,m<<=1){ 
            for(int j=0;j<n;j+=l)
                for(int i=0;i<m;++i){ 
                    ll x=a[i+j],y=a[i+j+m];
                    if(!f){ 
                        a[i+j]=x+y;
                        a[i+j+m]=x-y;
                    }else{ 
                        a[i+j]=(x+y)/2;
                        a[i+j+m]=(x-y)/2;
                    }
                }
        }
    }
    int getlim(int x){ 
        int lim=1;
        while(lim<x)lim<<=1;
        return lim;
    }
    poly OR(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_OR(a,0);
        FWT_OR(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_OR(a,1);
        return a;
    }
    poly AND(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_AND(a,0);
        FWT_AND(b,0);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        FWT_AND(a,1);
        return a;
    }
    poly XOR(poly a,poly b){ 
        int n=max(a.size(),b.size());
        int lim=getlim(n);
        a.resize(lim);b.resize(lim);
        FWT_XOR(a,0);
        FWT_XOR(b,0);
        for(int i=0;i<lim;++i)a[i]=(ll)a[i]*b[i];
        FWT_XOR(a,1);
        return a;
    }
}
using namespace Poly;
int n,m;
char s[22][maxn];
poly g,f;
int main(){ 
    read(n);read(m);
    for(int i=1;i<=n;++i){ 
        scanf("%s",s[i]+1);
    }
    g.resize(1<<n);f.resize(1<<n);
    for(int i=1;i<=m;++i){ 
        int now=0;
        for(int j=1;j<=n;++j){ 
            if(s[j][i]=='1')now+=(1<<(j-1));
        }
        f[now]++;
    }
    for(int i=0;i<(1<<n);++i){ 
        int bit=__builtin_popcount(i);
        g[i]=min(bit,n-bit);
    }
    poly ans=XOR(f,g);
    ll sum=1e9;
    for(int i=0;i<(1<<n);++i)sum=min(sum,ans[i]);
    cout<<sum;
}
```



**ARC 100 E**

题意：

对每个$K$求最大的$A_i+A_j$使得$i|j\leq K$

思路：

$i|j<=K$ 可以转化为对每个$K$求$i|j=k$，但这样仍不好求，考虑转化为$i|j  \subseteq  k$，这样就变成了维护子集信息，维护子集最大次大值，高维前缀和思想即可，最后再做个前缀最大值即可。

```cpp
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using P=pair<int,int>;
const int maxn=(1<<18)+10;
int n,a[maxn];
P f[maxn];
int main(){ 
    cin>>n;
    for(int i=0;i<(1<<n);++i)cin>>a[i],f[i].fi=a[i];
    for(int i=0;i<n;++i){ 
        for(int j=0;j<(1<<n);++j){ 
            if((1<<i)&j){ 
                if(f[j^(1<<i)].fi>f[j].fi){ 
                    f[j].se=f[j].fi;
                    f[j].fi=f[j^(1<<i)].fi;
                }else if(f[j^(1<<i)].fi>f[j].se){ 
                    f[j].se=f[j^(1<<i)].fi;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<(1<<n);++i){ 
        ans=max(ans,f[i].fi+f[i].se);
        cout<<ans<<"\n";
    }
    return 0;
}

```

