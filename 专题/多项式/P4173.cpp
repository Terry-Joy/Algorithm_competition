#include<bits/stdc++.h>

using namespace std;
const int maxn=3e5+5;
const double Pi=acos(-1.0);
int n,m,a[maxn],b[maxn],len,tr[maxn<<1],cnt=0;
struct CP{ 
    CP(double xx=0,double yy=0){ x=xx,y=yy;}
    double x,y;
    CP operator+(CP const&B)const
    { return CP(x+B.x,y+B.y);}
    CP operator-(CP const&B)const
    { return CP(x-B.x,y-B.y);}
    CP operator*(CP const &B)const
    { return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
}A1[maxn<<1],A2[maxn<<1],B1[maxn<<1],B2[maxn<<1],C1[maxn<<1],C2[maxn<<1],ans[maxn<<1];
char A[maxn],B[maxn];
void fft(CP *f,bool flag){ 
    for(int i=0;i<len;++i)
        if(i<tr[i])swap(f[i],f[tr[i]]);
    for(int p=2;p<=len;p<<=1){ 
        int len2=p>>1;
        CP tG(cos(2*Pi/p),sin(2*Pi/p));
        if(!flag)tG.y*=-1;
        for(int k=0;k<len;k+=p){ 
            CP buf(1,0);
            for(int l=k;l<k+len2;++l){ 
                CP tt=buf*f[len2+l];
                f[len2+l]=f[l]-tt;
                f[l]=f[l]+tt;
                buf=buf*tG;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>m>>n;
    cin>>A>>B;
    for(len=1;len<=(n-1);len<<=1);
    for(int i=m-1;i>=0;--i){ 
        a[cnt++]=((A[i]=='*')?0:(A[i]-'a'+1));
    }
    for(int i=0;i<len;++i)
        tr[i]=(tr[i>>1]>>1)|((i&1)?len>>1:0);
    for(int i=0;i<n;++i)b[i]=((B[i]=='*')?0:(B[i]-'a'+1));
    for(int i=0;i<m;++i)A1[i]=CP(a[i]*a[i]*a[i],0);
    for(int i=0;i<n;++i)A2[i]=CP(b[i],0);
    for(int i=0;i<m;++i)B1[i]=CP(a[i]*a[i],0);
    for(int i=0;i<n;++i)B2[i]=CP(b[i]*b[i],0);
    for(int i=0;i<m;++i)C1[i]=CP(a[i],0);
    for(int i=0;i<n;++i)C2[i]=CP(b[i]*b[i]*b[i],0);
    fft(A1,1);fft(A2,1);
    for(int i=0;i<len;++i)ans[i]=ans[i]+A1[i]*A2[i];
    fft(B1,1);fft(B2,1);
    for(int i=0;i<len;++i)ans[i]=ans[i]-B1[i]*B2[i]*2.0;
    fft(C1,1);fft(C2,1);
    for(int i=0;i<len;++i)ans[i]=ans[i]+C1[i]*C2[i];
    fft(ans,0);
    cnt=0;
    for(int i=m-1;i<n;++i){ 
        if(!(int)(ans[i].x/len+0.5))a[++cnt]=i-m+2;
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;++i)
        cout<<a[i]<<" ";
    return 0;
}
