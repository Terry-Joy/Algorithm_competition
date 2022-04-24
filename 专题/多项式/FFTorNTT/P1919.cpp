#include<bits/stdc++.h>

using namespace std;
const int maxn=4e6+5;
const int maxm=1e6+5;
const double Pi=acos(-1.0);
char s1[maxm],s2[maxm];
int ans[maxn];
struct CP{ 
    double x,y;
    CP(double xx=0,double yy=0){ x=xx;y=yy;}
    CP operator + (CP const&B)const{ 
        return CP(x+B.x,y+B.y);
    }
    CP operator-(CP const&B)const{ 
        return CP(x-B.x,y-B.y);
    }
    CP operator*(CP const&B)const{ 
        return CP(x*B.x-y*B.y,x*B.y+y*B.x);
    }
}f[maxn],p[maxn];
int tr[maxn],n=0,m=0;
void fft(CP*f,bool flag){ 
    for(int i=0;i<n;++i)
        if(i<tr[i])swap(f[i],f[tr[i]]);
    for(int p=2;p<=n;p<<=1){ 
        int len=p>>1;
        CP tG(cos(2*Pi/p),sin(2*Pi/p));
        if(!flag)tG.y*=-1;
        for(int k=0;k<n;k+=p){ 
            CP buf(1,0);
            for(int l=k;l<k+len;++l){ 
                CP tt=buf*f[len+l];
                f[len+l]=f[l]-tt;
                f[l]=f[l]+tt;
                buf=buf*tG;
            }
        }
    }
}
int main(){
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int len1=strlen(s1+1),len2=strlen(s2+1);
    for(int i=len1;i>=1;--i)f[n++].x=s1[i]-'0';
    for(int i=len2;i>=1;--i)p[m++].x=s2[i]-'0';
    n--;m--;
    for(m+=n,n=1;n<=m;n<<=1);
    for(int i=0;i<n;++i)
        tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
    fft(f,1);fft(p,1);
    for(int i=0;i<n;++i)f[i]=f[i]*p[i];
    fft(f,0);
    for(int i=0;i<=m;++i){ 
        ans[i]+=(int)(f[i].x/n+0.5);
        if(ans[i]>=10)
            ans[i+1]+=ans[i]/10,ans[i]%=10,m+=(i==m);
    }
    for(int i=m;i>=0;--i)
        cout<<ans[i];
    return 0;
}
