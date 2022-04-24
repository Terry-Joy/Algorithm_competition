#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=8e5+1000;
const int N=2e5+5;
namespace Poly{ 
    int lim,pre[maxn],c[maxn],n,m,len,rev[maxn];
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
    void initrev(){ 
         for(int i=0;i<lim;++i){ 
            rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
        }
    }
    void getlim(int x){ 
        lim=1;
        while(lim<x)lim<<=1;
    }
    void initpre(){ 
        for(int i=1;i<len;i<<=1){ //一半长度
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
char s1[N],s2[N],x[]={ '0','1','2','3','4','5','6','7','8','9','*'};
int sum1[N],sum2[N],a[maxn],b[maxn],ans[N];
void init(){ 
    for(int i=0;i<lim;++i)c[i]=0;
    for(int i=0;i<=m+1;++i)ans[i]=0;
}
int main(){ 
    int t;
    int M=4e5+2;
    len=1;
    while(len<M)len<<=1;
    initpre();
    scanf("%d",&t);
    while(t--){ 
        scanf("%d%d",&n,&m);
        scanf("%s",s1);
        scanf("%s",s2);
        sum1[0]=(s1[0]=='*'?1:0);
        sum2[0]=(s2[0]=='*'?1:0);
        for(int i=1;i<n;++i)sum1[i]=sum1[i-1]+(s1[i]=='*');
        for(int i=1;i<m;++i)sum2[i]=sum2[i-1]+(s2[i]=='*');
        reverse(s2,s2+m);
    	getlim(n+m+2);
        initrev();
        for(int p=0;p<10;++p){ 
            for(int i=0;i<n;++i)a[i]=(s1[i]==x[p]?1:0);
            for(int i=n;i<lim;++i)a[i]=0;
            for(int i=0;i<m;++i)b[i]=(s2[i]==x[p]?1:0);
            for(int i=m;i<lim;++i)b[i]=0;
            ntt(a,1);ntt(b,1);
            for(int i=0;i<lim;++i)c[i]=Add(c[i],mul(a[i],b[i]));
        }    
        for(int i=0;i<n;++i)a[i]=(s1[i]=='*'?1:0);
        for(int i=n;i<lim;++i)a[i]=0;
        for(int i=0;i<m;++i)b[i]=(s2[i]=='*'?1:0);
        for(int i=m;i<lim;++i)b[i]=0;
        ntt(a,1);ntt(b,1);
        for(int i=0;i<lim;++i)c[i]=Sub(c[i],mul(a[i],b[i]));
        ntt(c,0);
        for(int i=m-1;i<=n-1;++i){ 
            c[i]=Add(c[i],Sub(sum1[i],((i-m>=0)?sum1[i-m]:0)));
            c[i]=Add(c[i],sum2[m-1]);
        }
        for(int i=m-1;i<=n-1;++i)
            c[i]=Sub(m,c[i]),ans[c[i]]++;
        for(int i=1;i<=m;++i)ans[i]+=ans[i-1];
        for(int i=0;i<=m;++i)cout<<ans[i]<<"\n";
        init();
    }
    return 0;
}
