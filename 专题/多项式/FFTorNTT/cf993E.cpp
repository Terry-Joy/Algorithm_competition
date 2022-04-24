#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=8e5+100;
namespace Poly{ 
    const db PI=acos(-1.0);
    int rev[maxn],n,x;
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
}
using namespace Poly;
int f[maxn];
ll cal(){ 
    ll ans=0;
    int pre=0;
    for(int i=1;i<=n;++i){ 
        if(f[i]!=f[i-1])pre=i;
        ans+=i-pre;
    }
    return ans;
}
int main(){ 
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>x;
    int y;
    for(int i=1;i<=n;++i){ 
        cin>>y;
        if(y<x)f[i]=f[i-1]+1;
        else f[i]=f[i-1];
        A[f[i]].x++;
    }
    A[0].x++;
    for(int i=0;i<=n;++i)B[i].x=A[n-i].x;
    int lim=1;
    while(lim<=n+n)lim<<=1;
    for(int i=0;i<lim;++i){ 
        rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
    }
    fft(A,lim,1);fft(B,lim,1);
    for(int i=0;i<lim;++i)A[i]=A[i]*B[i];
    fft(A,lim,-1);
    cout<<cal()<<" ";
    for(int i=1;i<=n;++i)cout<<(long long)(A[n-i].x+0.5)<<" ";
    return 0;
}
