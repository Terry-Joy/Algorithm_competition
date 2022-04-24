#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const double Pi=acos(-1.0);
int t,n,a[maxn];
struct CP{ 
    double x,y;
    CP(double xx=0,double yy=0){ x=xx;y=yy;}  
    CP operator +(CP const&B)const
    {return CP(x+B.x,y+B.y);}
    CP operator -(CP const&B)const
    {return CP(x-B.x,y-B.y);}
    CP operator*(CP const&B)const
    {   return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
}cnt[maxn<<2];
int tr[maxn<<2],m,tmp;
ll sum[maxn<<2];
void fft(CP*f,bool flag){ 
    for(int i=0;i<tmp;++i)
        if(i<tr[i])swap(f[i],f[tr[i]]);
    for(int p=2;p<=tmp;p<<=1){ 
        int len=p>>1;
        CP tG(cos(2*Pi/p),sin(2*Pi/p));
        if(!flag)tG.y*=-1;
        for(int k=0;k<tmp;k+=p){ 
            CP buf(1,0);
            for(int l=k;l<k+len;l++){ 
                CP tt=buf*f[len+l];
                f[len+l]=f[l]-tt;
                f[l]=f[l]+tt;
                buf=buf*tG;
            }
        }
    }
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=1;i<=n;++i){ 
            scanf("%d",&a[i]),cnt[a[i]].x++;
        }
        sort(a+1,a+1+n);
        m=a[n],tmp=a[n];
        for(m+=tmp,tmp=1;tmp<=m;tmp<<=1);
        for(int i=0;i<tmp;++i)
            tr[i]=(tr[i>>1]>>1)|((i&1)?tmp>>1:0);
        fft(cnt,1);
        for(int i=0;i<tmp;++i)cnt[i]=cnt[i]*cnt[i];
        fft(cnt,0);
        for(int i=0;i<=m;++i)
            cnt[i].x=(ll)(cnt[i].x/tmp+0.5),sum[i]=cnt[i].x;
        for(int i=1;i<=n;++i)
            sum[a[i]+a[i]]--;
        for(int i=1;i<=m;++i)
            sum[i]>>=1;
        sum[0]=0;                   //前面加了0.5,已经为0
        for(int i=1;i<=m;++i)
            sum[i]+=sum[i-1];
        ll ans=0;
        for(int i=1;i<=n;++i){ 
            ans+=(sum[m]-sum[a[i]]);
            ans-=1ll*(n-i)*(i-1);//一大一小
            ans-=1ll*(n-i)*(n-i-1)/2;//两个大于
            ans-=(n-1);//一个自己,一个另外一个
        }
        ll num=1ll*n*(n-1)*(n-2)/6;
        for(int i=0;i<tmp;++i)
            cnt[i]=CP(0,0);
        printf("%.7f\n",(double)ans/num);
    }
    return 0;
}
