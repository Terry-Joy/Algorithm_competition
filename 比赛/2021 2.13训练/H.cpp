#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=6e4+5;
const int del=3e4;
const int maxm=270005;
const double Pi=acos(-1.0);
int nu,nm,nl,cnt1[maxm],cnt2[maxm],b[maxn],n,m,tr[maxm],a[maxn],c[maxn];
ll cnt[maxm];
struct CP{
    double x,y;
    CP(double xx=0,double yy=0){x=xx,y=yy;}
    CP operator+(CP const&B)const{
        return CP(x+B.x,y+B.y);
    }
    CP operator-(CP const&B)const{
        return CP(x-B.x,y-B.y);
    }
    CP operator*(CP const&B)const{
        return CP(x*B.x-y*B.y,x*B.y+y*B.x);
    }
}f[maxm],p[maxm];
void fft(CP*f,bool flag){
    for(int i=0;i<n;++i)
        if(i<tr[i])swap(f[i],f[tr[i]]);
    for(int p=2;p<=n;p<<=1){
        int len=p>>1;
        CP tG(cos(2*Pi/p),sin(2*Pi/p));
        if(!flag)tG.y*=-1;
        for(int k=0;k<n;k+=p){
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>nu;
    int len1=0,len2=0;
    for(int i=1;i<=nu;++i){
        cin>>a[i];
        a[i]+=del;
        len1=max(len1,a[i]);
        cnt1[a[i]]++;
    }
    cin>>nm;
    for(int i=1;i<=nm;++i){
        cin>>b[i];
        b[i]+=del;
    }
    cin>>nl;
    for(int i=1;i<=nl;++i){
        cin>>c[i];
        c[i]+=del;
        len2=max(len2,c[i]);
        cnt2[c[i]]++;
    }
    n=len1,m=len2;
    len1++;len2++;
    for(m+=n,n=1;n<=m;n<<=1);
    for(int i=0;i<len1;++i)
        f[i]=CP(cnt1[i],0);
    for(int i=len1;i<n;++i)
        f[i]=CP(0,0);
    for(int i=0;i<len2;++i)
        p[i]=CP(cnt2[i],0);
    for(int i=len2;i<n;++i)
        p[i]=CP(0,0);
    for(int i=0;i<n;++i)
        tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
    fft(f,1);
    fft(p,1);
    for(int i=0;i<n;++i)f[i]=f[i]*p[i];
    fft(f,0);
    for(int i=0;i<n;++i){
        cnt[i]=(long long)(f[i].x/n+0.5);
    }
    ll ans=0;
    for(int i=1;i<=nm;++i)
        ans+=cnt[2*b[i]];
    cout<<ans<<"\n";
    return 0;
}