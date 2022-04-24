#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=4e5+100;
namespace Poly{ 
    const db PI=acos(-1.0);
    int rev[maxn],a[maxn];
    ll cnt[maxn];
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
    }A[maxn];//大小(n+m)<<1
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
}
using namespace Poly;
const int M=1e5;
int main(){ 
    int t,n;
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        int mx=0;
        for(int i=1;i<=n;++i){ 
            int x;
            scanf("%d",&x);
            a[x]++;
            mx=max(mx,x);
        }
        int lim=1;
        while(lim<=mx+mx)lim<<=1;
        for(int i=0;i<lim;++i)
            rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
        for(int i=0;i<lim;++i)A[i]=i<=mx?cp{a[i],0}:cp{ 0,0};
        fft(A,lim,1);
        for(int i=0;i<lim;++i)A[i]=A[i]*A[i];
        fft(A,lim,-1);
        for(int i=0;i<=mx+mx;++i)cnt[i]=(ll)(A[i].x+0.5);
        for(int i=1;i<=2*mx;++i){ 
            if(i&1){ 
                cnt[i]>>=1;
            }else{ 
                cnt[i]=(cnt[i]-(ll)a[i>>1]*a[i>>1])/2+(ll)a[i>>1]*(a[i>>1]-1)/2;
            }
        }
        //for(int i=1;i<=2*mx;++i)
        //  cout<<i<<" "<<cnt[i]<<" "<<a[i]<<"\n";
        ll ans=(ll)n*(n-1)*(n-2)/6;
        ll sum=0;
        for(int i=mx;i>=1;--i){ 
            sum-=(ll)a[i]*cnt[i];
            a[i-1]+=a[i];
        }
       // cout<<sum<<" "<<ans<<"\n"; 
        for(int i=mx;i>=0;--i)a[i]=0;
        printf("%.7f\n",1.0*(ans+sum)/ans);
        cout<<1.0*(ans+sum)/ans<<"\n";
    }
}
