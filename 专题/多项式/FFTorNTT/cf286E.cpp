#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=4e6+5;
namespace Poly{ 
    int f[maxn],lim,pre[maxn],n,m,rev[maxn];
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
bool v[maxn];
int main(){ 
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){ 
        int x;
        cin>>x;
        v[x]=f[x]=1;
    }
    getlim(2*m+2);
    initpre();
    initrev();
    ntt(f,1);
    for(int i=0;i<lim;++i)f[i]=mul(f[i],f[i]);
    ntt(f,0);
    int cnt=0;
    for(int i=1;i<=m;++i){ 
        if(!f[i])continue;
        cnt++;
        if(!v[i]){ 
            puts("NO");return 0;
        }
    }
    cout<<"YES\n";
    cout<<n-cnt<<"\n";
    for(int i=1;i<=m;++i){ 
        if(!f[i]&&v[i])cout<<i<<" ";
    }
    return 0;
}

