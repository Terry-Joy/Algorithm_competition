#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=8e5+100;
const int N=2e5+5;
namespace Poly{ 
    int a[maxn],b[maxn],lim,pre[maxn],c[maxn],n,m,rev[maxn],k;
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
}

using namespace Poly;
char x[]={ 'A','G','C','T'};
char S[N],T[N];
int main(){ 
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    cin>>S>>T;
    reverse(T,T+m);
    getlim(n+m+2);
    initpre();
    initrev();
    for(int i=0;i<4;++i){ 
        for(int j=0;j<lim;++j)a[j]=b[j]=0;
        int las=-1e9;
        for(int j=0;j<n;++j){ 
            if(S[j]==x[i])las=j;
            if(j-las<=k)a[j]=1;
        }
        las=1e9;
        for(int j=n-1;j>=0;--j){ 
            if(S[j]==x[i])las=j;
            if(las-j<=k)a[j]=1;
        }
        for(int j=n;j<lim;++j)a[j]=0;
        for(int j=0;j<m;++j)
            b[j]=((T[j]==x[i])?1:0);
        for(int j=m;j<lim;++j)b[j]=0;
        ntt(a,1);ntt(b,1);
        for(int j=0;j<lim;++j)c[j]=Add(c[j],mul(a[j],b[j]));
    }
    ntt(c,0);
    int ans=0;
    for(int i=m-1;i<=n-1;++i)ans+=(c[i]==m);
    cout<<ans;
    return 0;
}
