#include<bits/stdc++.h>
using namespace std;
using db=double;
const int maxn=4e5+100;
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
    }f[maxn],g[maxn],f2[maxn];//大小(n+m)<<1
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
int main(){ 
    int n;
    scanf("%d",&n);
    f[0].x=g[0].x=0;
    for(int i=1;i<=n;++i)scanf("%lf",&f[i].x),g[i].x=1.0/i/i,f2[i].x=f[i].x;
    reverse(f2,f2+n+1);
    int lim=1;
    while(lim<=n+n)lim<<=1;
    for(int i=0;i<lim;++i){ 
        rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));        
    }
    fft(f,lim,1);fft(g,lim,1);fft(f2,lim,1);
    for(int i=0;i<lim;++i)f[i]=f[i]*g[i],f2[i]=f2[i]*g[i];
    fft(f,lim,-1);fft(f2,lim,-1);
    for(int i=1;i<=n;++i){ 
        printf("%.3f\n",f[i].x-f2[n-i].x);
    }
    return 0; 
}
