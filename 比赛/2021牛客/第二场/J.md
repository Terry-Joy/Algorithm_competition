# 2021 牛客多校第二场补题（ J

J

题意：

给$n$个数，问大小为$k$的集合的gcd的连乘

思路：
一开场就看了这题...思路也一眼出了，但是卡在欧拉降幂的大小判断上了...赛后一看rank1代码就懂了...

我的做法是容斥，好像还有后缀和等做法（但我不会）

$f[i]$为$gcd$为$i$和$i$的倍数的$k$大小子集的方案数，$num[i]$为集合中为$i$及$i$的倍数的个数，显然$f[i]=C(num[i],k)$，然后倒序枚举值域容斥即减掉其倍数即可，就能得到gcd恰好为i的方案数，但这种做法有一个问题就是组合数位于指数，需要欧拉降幂，但是组合数需要预处理，根据拓展欧拉定理，难以判断指数$phi(mod)$的大小，然后我就自闭了，但其实我们可以再维护一个$f2[i]$，但是选择模一个>phi(m)的数字，如果最后的$f2[i]$和$f[i]$不一样的话，说明要+phi(mod)，真的非常巧妙....（这里rank1的代码选择模一个质数来判断，我无法理解...如果有人理解道理的话请在下方留言告诉我），但这题数据水了，有人直接模phi(mod)也过了，但是是可以hack的。

我的时间复杂度是$O(Tmax(x_i)ln(x_i)+T质数个数+Tnk)$

事实上这题非常卡常...也可能是我的做法不好，瓶颈在于求欧拉函数那，如果用Pollaro可能快一点，本代码经过卡常跑了$830ms+$才过，此外还要注意本题需要__int128

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
const int maxm=4e4+5;
const ll mod=1e14;
bool v[maxn];
int prime[maxn],cnt=0,t,a[maxm];
ll f[maxm<<1],f2[maxm<<1];
ll c[maxm][32],P,c2[maxm][32];
bool is[maxm][32],ismod[maxm<<1];
ll phi(ll x){ 
    ll ans=x;
    for(int i=1;1ll*prime[i]*prime[i]<=x&&i<=cnt;++i){ 
        if(x%prime[i]==0){ 
            ans-=ans/prime[i];
            while(x%prime[i]==0)x/=prime[i];
        }
    }
    if(x>1)ans-=ans/x;
    return ans;
}
void init(){ 
    for(int i=2;i<maxn;++i){ 
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=0;i<=maxm-5;++i){ 
        c2[i][0]=1;
        for(int j=1;j<=min(i,30);++j){ 
            c2[i][j]=c2[i-1][j-1]+c2[i-1][j];
            if(c2[i][j]>=mod)c2[i][j]-=mod;  
        }
    }
}
void init2(ll phi,int k,int n){ 
    c[0][0]=1;
    for(int i=1;i<=30;++i)c[i][i]=1;
    for(int i=0;i<=n;++i){ 
        c[i][0]=1;
        for(int j=1;j<=min(i,k);++j){ 
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            if(c[i][j]>=phi){ 
                c[i][j]-=phi;
            }
        }
    }
}
ll mul(ll a,ll b,ll mod){ 
    return __int128(a)*b%mod;
}
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=mul(ans,a,P);
        a=mul(a,a,P);
        b>>=1;
    }
    return ans;
}
void read(int &num)
{
	num=0;
	char ch=getchar();
	while (ch<48 || ch>57) ch=getchar();
	while (ch>=48 && ch<=57) num=num*10+ch-48,ch=getchar();
}
void readll(ll &num)
{
	num=0;
	char ch=getchar();
	while (ch<48 || ch>57) ch=getchar();
	while (ch>=48 && ch<=57) num=num*10+ch-48,ch=getchar();
}
int main(){ 
    init();
	read(t);
    int s,k;
    while(t--){ 
		read(s);
		read(k);
		readll(P);
        int mx=0;
        ll x=phi(P);
        init2(x,k,s);
        for(int i=1;i<=s;++i){ 
            read(a[i]);
			mx=max(mx,a[i]);
            f[a[i]]++;
        }
        for(int i=1;i<=mx;++i){ 
            for(int j=2*i;j<=mx;j+=i)
                f[i]+=f[j];
        }
        for(int i=1;i<=mx;++i)f2[i]=c2[f[i]][k],f[i]=c[f[i]][k];
        int M=(mx+1)/2;
        for(int i=M;i>=1;--i){ 
            for(int j=2*i;j<=mx;j+=i){ 
                f[i]-=f[j];
                if(f[i]<0)
                    f[i]+=x;
                f2[i]-=f2[j];
                if(f2[i]<0)
                    f2[i]+=mod;
            }   
        }
        ll ans=1;
        for(int i=1;i<=mx;++i){ 
            if(f[i]!=f2[i])f[i]+=x;
                ans=mul(ans,mypow(i,f[i]),P);
        }
        for(int i=1;i<=mx;++i)f[i]=f2[i]=0;
        cout<<ans<<"\n";
    }
    return 0;
}


```



