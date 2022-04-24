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
        getlim(length);
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
