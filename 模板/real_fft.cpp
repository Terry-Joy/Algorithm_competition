#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=4e6+5;
namespace Poly{ 
    const db PI=acos(-1.0);
    int rev[maxn];
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
    }A[maxn],B[maxn],C[maxn];//大小(n+m)<<1
    void fft(cp A[],int len,int op){ 
        for(int i=0;i<len;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
        for(int i=2;i<=len;i<<=1){ 
            cp wn={ cos(2*PI/i),sin(2*PI/i)};
            int d=i>>1;
            for(int j=0;j<len;j+=i){ 
                cp wk={ 1,0};
                for(int k=j;k<j+d;++k,wk=wk*wn){ 
                    cp x=A[k],y=wk*A[k+d];
                    A[k]=x+y,A[k+d]=x-y;
                }
            }
        }
        if(op==-1){ 
            reverse(A+1,A+len);
            for(int i=0;i<len;++i)A[i].x/=len;
        }
    }
    void workFFT(int a[],int n,int b[],int m,int c[]){ 
        int len=1;
        while(len<=n+m)len<<=1;
        for(int i=0;i<len;++i){ 
            rev[i]=(rev[i>>1]>>1)|((i&1)*(len>>1));
        }
        for(int i=0;i<len;++i){ 
            A[i]=i<=n?cp{ a[i],0}:cp{ 0,0};//输入a 0~n次系数
            B[i]=i<=m?cp{ b[i],0}:cp{ 0,0};//输入b 0~n次系数
        }
        fft(A,len,1),fft(B,len,1);
        for(int i=0;i<len;++i)C[i]=A[i]*B[i];
        fft(C,len,-1);
        for(int i=0;i<=n+m;++i)c[i]=(int)(C[i].x+0.5);
    }

    //NTT
    int f[maxn],g[maxn],lim,pre[maxn],c[maxn],n,m;
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
    void getmul(int n,int m,int*a,int*b){ 
        getlim(n+m+2);
        initpre();
        initrev();
        ntt(a,1);ntt(b,1);
        for(int i=0;i<lim;++i)c[i]=mul(a[i],b[i]);
        ntt(c,0);
    }
    void solve(){ 
        cin>>n>>m;
        for(int i=0;i<=n;++i)cin>>f[i];
        for(int i=0;i<=m;++i)cin>>g[i];
        getmul(n,m,f,g);
        //[0,n+m]对应系数
    }
    
}
using namespace Poly;
int main(){ 
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    for(int i=0;i<=n+m;++i)cout<<c[i]<<" ";
    return 0;
}
