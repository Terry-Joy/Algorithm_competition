### 分治FFT小结

**分治FFT**本质上是分治+FFT

暂时两种套路

1.$f_i=\sum\limits_{j=1}^{i}f_{i-j}g_j$  $or$  $f_i=\sum\limits_{j=0}^{i-1}f_jg_{i-j}$  即前面对自己转移

直接卷积枚举每个点卷积的复杂度是$O(n^2logn)$

考虑$CDQ$分治，先处理$f(l,mid)$, 考虑$f(l,mid)$对$f(mid+1,r)$的贡献，再递归$f(mid+1,r)$计算

具体来说，$f(l,mid)$对$f(mid+1,r)$的贡献实质是$f(l,mid)$卷$g(1,r-l)$

$h(x)=\sum\limits_{i=l}^{mid}f[i]g[x-i]$   此时把$f(mid+1,r)$看成是$0$则可以拓展为$h(x)=\sum\limits_{i=l}^{x-1}f[i]g[x-i]$

$h(x)=\sum\limits_{i=0}^{x-1-l}f[i+l]g[x-l-i]$ ，令$a[i]=f[i+l]$, $b[i-1]=g[i]$

则$h(x)=\sum\limits_{i=0}^{x-1-l}a[i]b[x-l-1-i]$  ，$fft$即可

```c++
 void cdq(int l,int r){ //一般ntt模板 给f[0] g[1~n-1]算f[1~n-1]
        if(l==r)return;
        int mid=l+r>>1,length=r-l+1;
        cdq(l,mid);//先做完左边
        getlim(length+1);//r-l+2
        initrev();
        initpre();
        for(int i=0;i<lim;++i)a[i]=b[i]=0;
        for(int i=l;i<=mid;++i)a[i-l]=f[i];//考虑贡献到[mid+1,r]即为
        for(int i=1;i<length;++i)b[i-1]=g[i];//f[l,mid]卷g[1,r-l] 
        ntt(a,1);ntt(b,1);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        ntt(a,0);
        for(int i=mid+1;i<=r;++i){ 
            f[i]+=a[i-1-l];
            if(f[i]>=mod)f[i]-=mod;
            if(f[i]<0)f[i]+=mod;
        }
        cdq(mid+1,r);
    }
```



当然也可多项式求逆

设$F(x)=\sum_{i=0}^{\infty}f_ix^i$,$G(x)=\sum_{i=0}^{\infty}g_ix^i$    $g_0=0$

$F(x)G(x)\equiv\sum\limits_{i=0}^{n-1}\sum\limits_{j=0}^{i}f_{i-j}g_{j}x^i\equiv F(x)-f(0)x^0$, $mod  x^n $   $F(X)≡(1−G(x))^{-1}(modx^n)$



$2.\prod(a_ix+b_i)$  即可以看成两个集合选指定个数的数连乘之和，最裸的分治$FFT$了

```cpp
poly solve(int l,int r){
    if(l==r) return poly{b_i,a_i};
 	int mid=l+r>>1;
    return solve(l,mid)*solve(mid+1,r);
}
```



$3.$卷积的时候与值域大小比较相关，此时可以考虑对值域分治，按照值域限制贡献



3.$f_i=\sum\limits_{j=1}^{i}f_{i-j}f_j$ 待更



题目：

**1.P4721** 

思路：

模板题，思路已经在上面讲了

```cpp
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=4e5+100;
namespace Poly{ 
   int f[maxn],g[maxn],lim,pre[maxn],c[maxn],n,m,rev[maxn],a[maxn],b[maxn];
    const int mod=998244353,G=3,invG=332748118;
    int mypow(int a,int b){ 
        int ans=1;
        while(b){ 
            if(b&1)ans=(ll)ans*a%mod;
            a=(ll)a*a%mod;
            b>>=1;
        }
        return ans;
    }
    int Add(int x,int y){ 
        x+=y;
        if(x>=mod)x-=mod;
        return x;
    }
    int Sub(int x,int y){ 
        x-=y;
        if(x<0)x+=mod;
        return x;
    }
    int mul(int x,int y){ return (ll)x*y%mod;}
    int inv(int x){ return mypow(x,mod-2);}
    void getlim(int x){ 
        lim=1;
        while(lim<x)lim<<=1;
    }
    void initrev(){ 
         for(int i=0;i<lim;++i){ 
            rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
        }
    }
    void initpre(){ 
        for(int i=1;i<lim;i<<=1){ //一半长度
            int w = mypow(3, (mod - 1) / (i << 1));//g^((p-1)/(n))
            pre[i] = 1;
            for (int j = 1; j < i; j++) pre[i + j] = mul(pre[i + j - 1], w);
        }
    }
    void ntt(int*a,bool tp){ 
        for (int i = 0; i < lim; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int mid = 1, cnt = 0; mid < lim; mid <<= 1, cnt++)
            for (int j = 0, len = mid << 1; j < lim; j += len)
                for (int k = 0; k < mid; k++) {
                    int x = a[j + k], y = mul(pre[mid + k], a[j + k + mid]);
                    a[j + k] = Add(x, y);
                    a[j + k + mid] = Sub(x, y);
                }
        if (tp) return;
        int invlim = inv(lim);
        for (int i = 0; i < lim; i++) a[i] = mul(a[i], invlim);
        reverse(a + 1, a + lim);
    }
    void cdq(int l,int r){ 
        if(l==r)return;
        int mid=l+r>>1,length=r-l+1;
        cdq(l,mid);//先做完左边
        getlim(length+1);
        initrev();
        initpre();
        for(int i=0;i<lim;++i)a[i]=b[i]=0;
        for(int i=l;i<=mid;++i)a[i-l]=f[i];
        for(int i=1;i<length;++i)b[i-1]=g[i];
        ntt(a,1);ntt(b,1);
        for(int i=0;i<lim;++i)a[i]=mul(a[i],b[i]);
        ntt(a,0);
        for(int i=mid+1;i<=r;++i){ 
            f[i]+=a[i-1-l];
            if(f[i]>=mod)f[i]-=mod;
            if(f[i]<0)f[i]+=mod;
        }
        cdq(mid+1,r);
    }
}
using namespace Poly;
int main(){ 
    cin>>n;
    f[0]=1;
    for(int i=1;i<n;++i)cin>>g[i];
    cdq(0,n-1);
    for(int i=0;i<n;++i){ 
        cout<<f[i]<<" ";
    }
    cout<<endl;
    return 0;
}
```



**2.hdu 6900**

#### 题意：

![image-20210825175038246](C:\Users\98753\AppData\Roaming\Typora\typora-user-images\image-20210825175038246.png)

思路：考虑把$f_i(x)$写成$n$行，每一行向上一行的转移其实就两种操作，一种是乘$c_i$到$f[i-1][j]$,一种是乘$jb_i$到$f[i-1][j+1]$ , 每一次操作对多项式的贡献可以用一个生成函数描述$c_i+b_ix$,  则从$f[1][i]$到$f[n][j]$ $(i>=j)$的贡献是该生成函数的连乘的第$i-j$项系数，$\prod(b_ix+c_i)$可以用分治$NTT$求出，考虑对$f[n][j]$的所有贡献。

则$f[j]=\sum\limits_{i=0}^{n-j}g[j]a[i+j] \frac{(i+j)!}{j!}$， 把后面的翻转做个$FFT$即可

```cpp
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

```



**3.bzoj 4836**

题意：

定义二元运算 opt 满足

![image-20210825180231333](C:\Users\98753\AppData\Roaming\Typora\typora-user-images\image-20210825180231333.png)
现在给定一个长为 n 的数列 a 和一个长为 m 的数列 b ，接下来有 q 次询问。每次询问给定一个数字 c

你需要求出有多少对 (i, j) 使得 $a_i$ $opt$ $b_i$=$c$

思路：

考虑对值域分治，分别对$a(l,mid)和b(mid+1,r)$做加法卷积以及$a(mid+1,r)和b(l,mid)$做翻转卷积即可

注意分治的时候的下标范围，需要手写验证一下

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
const int maxn=2e5+5;
namespace Poly{ 
    const db PI=acos(-1.0);
    int rev[maxn],a[maxn],b[maxn];
    ll ans[maxn];
    struct cp{ 
        db x,y;
        friend cp operator+(const cp&a,const cp&b){ 
            return cp{ a.x+b.x,a.y+b.y};
        }
        friend cp operator-(const cp&a,const cp&b){ 
            return cp{ a.x-b.x,a.y-b.y};
        }
        friend cp operator*(const cp&a,const cp&b){ 
            return cp{ a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
        }
    }A[maxn],B[maxn];//大小(n+m)<<1
    void fft(cp A[],int lim,int op){ 
        for(int i=0;i<lim;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
        for(int i=2;i<=lim;i<<=1){ 
            cp wn={ cos(2*PI/i),sin(2*PI/i)};
            int d=i>>1;
            for(int j=0;j<lim;j+=i){ 
                cp wk={ 1,0};
                for(int k=j;k<j+d;++k,wk=wk*wn){ 
                    cp x=A[k],y=wk*A[k+d];
                    A[k]=x+y,A[k+d]=x-y;
                }
            }
        }
        if(op==-1){ 
            reverse(A+1,A+lim);
            for(int i=0;i<lim;++i)A[i].x/=lim;
        }
    }
    void getlim(int&lim,int x){ 
        lim=1;
        while(lim<=x)lim<<=1;
        for(int i=0;i<lim;++i){ 
            rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
        }
        for(int i=0;i<lim;++i)A[i]=B[i]=cp{ 0,0};
    }
    void solve(int l,int r){ 
        if(l==r){//l==r 
             ans[0]+=(ll)a[l]*b[l];
             return;
        }
        //l<r
        int mid=l+r>>1,len1=mid-l+1,len2=r-l,lim;
        getlim(lim,r-l-1);
        for(int i=l;i<=mid;++i)A[i-l]=cp{a[i],0};
        for(int i=mid+1;i<=r;++i)B[i-(mid+1)]=cp{b[i],0};
        fft(A,lim,1);fft(B,lim,1);
        for(int i=0;i<lim;++i)A[i]=A[i]*B[i];
        fft(A,lim,-1);
        for(int i=0;i<=r-l-1;++i)ans[i+l+mid+1]+=(ll)(A[i].x+0.5);

        //l>r
        for(int i=0;i<lim;++i)A[i]=B[i]=cp{ 0,0};
        for(int i=mid+1;i<=r;++i)A[i-(mid+1)]=cp{ a[i],0};
        for(int i=l;i<=mid;++i)B[mid-i]=cp{b[i],0};
        fft(A,lim,1);fft(B,lim,1);
        for(int i=0;i<lim;++i)A[i]=A[i]*B[i];
        fft(A,lim,-1);
        for(int i=0;i<=r-l-1;++i)ans[i+1]+=(ll)(A[i].x+0.5);
        solve(l,mid);solve(mid+1,r);
    }
}
using namespace Poly;
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        int n,m,q,x,mx=0;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;++i){ 
            scanf("%d",&x);a[x]++,mx=max(mx,x);
        }
        for(int i=1;i<=m;++i){ 
            scanf("%d",&x);b[x]++,mx=max(mx,x);
        }
        //memset(ans,0,sizeof(ans));
        solve(0,50000);
        while(q--){ 
            scanf("%d",&x);
            cout<<ans[x]<<"\n";
        }
        for(int i=0;i<=mx;++i)a[i]=b[i]=0;
        for(int i=0;i<=2*mx;++i)ans[i]=0;
    }
    return 0;
}

```

