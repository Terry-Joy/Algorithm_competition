#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int maxn=1.2e6+5;
const int N=3e5+5;
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
    void init(int&lim,int n,int m){ 
        while(lim<=n+m)lim<<=1;
        for(int i=0;i<lim;++i){ 
            rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
        }
    }
}
using namespace Poly;
char s1[N],s2[N];
int m,n,a[N],b[N],c[N],pos[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>m>>n;
    cin>>s1;
    cin>>s2;
    reverse(s1,s1+m);
    m--;n--;
    for(int i=0;i<=m;++i)a[i]=(s1[i]!='*'?s1[i]-'a'+1:0);
    for(int i=0;i<=n;++i)b[i]=(s2[i]!='*'?s2[i]-'a'+1:0);
    int lim=1;
    init(lim,n,m);
    for(int i=0;i<lim;++i){ 
        A[i]=i<=m?cp{ a[i]*a[i]*a[i],0}:cp{ 0,0};
        B[i]=i<=n?cp{b[i],0}:cp{ 0,0};
    }
    fft(A,lim,1),fft(B,lim,1);
    for(int i=0;i<lim;++i)C[i]=C[i]+A[i]*B[i];
    for(int i=0;i<lim;++i){ 
        A[i]=i<=m?cp{ 2*a[i]*a[i],0}:cp{ 0,0};
        B[i]=i<=n?cp{b[i]*b[i],0}:cp{ 0,0};
    }
    fft(A,lim,1);fft(B,lim,1);
    for(int i=0;i<lim;++i)C[i]=C[i]-A[i]*B[i];
    for(int i=0;i<lim;++i){ 
        A[i]=i<=m?cp{ a[i],0}:cp{ 0,0};
        B[i]=i<=n?cp{b[i]*b[i]*b[i],0}:cp{ 0,0};
    }
    fft(A,lim,1);fft(B,lim,1);
    for(int i=0;i<lim;++i)C[i]=C[i]+A[i]*B[i];
    fft(C,lim,-1);
    for(int i=0;i<=n+m;++i)c[i]=(int)(C[i].x+0.5);
    int cnt=0;
    for(int i=m;i<=n;++i)
        if(!c[i])pos[++cnt]=i-m+1;
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;++i)cout<<pos[i]<<" ";
    return 0;
}
