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
