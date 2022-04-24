#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,m,t,x[maxn],y[maxn],cnt1,cnt2;
ll r[maxn],c[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t;
    int flag=-1;
    int a,b;
    for(int i=1;i<=t;++i){
        cin>>a>>b;
        x[a]++;y[b]++;
    }
    for(int i=1;i<=n;++i)x[i]+=x[i-1];
    for(int i=1;i<=m;++i)y[i]+=y[i-1];
    if(t%n==0&&t%m==0)flag=1;
    else if(t%n==0&&t%m!=0)flag=2;
    else if(t%n&&t%m==0)flag=3;
    else if(t%m&&t%n)flag=4;
    ll ans=0;
    if(flag==4){cout<<"impossible";return 0;}
    if(flag==1||flag==3){
        int M=t/m;
        c[++cnt1]=0;
        for(int i=1;i<=m-1;++i){
            c[++cnt1]=1ll*i*M-y[i];
        }
        sort(c+1,c+cnt1+1);
        int pos=0;
        if(cnt1&1)pos=c[(cnt1+1)/2];
        else pos=c[cnt1/2];
        for(int i=1;i<=cnt1;++i){
            ans+=abs(pos-c[i]);
        }
    }
    if(flag==1||flag==2){
        int M=t/n;
        r[++cnt2]=0;
        for(int i=1;i<=n-1;++i){
            r[++cnt2]=1ll*i*M-x[i];
        }
        sort(r+1,r+1+cnt2);
        int pos=0;
        if(cnt2&1)pos=r[(cnt2+1)/2];
        else pos=r[cnt2/2];
        for(int i=1;i<=cnt2;++i){
            ans+=abs(pos-r[i]);
        }
    }
    if(flag==1)cout<<"both"<<" "<<ans;
    else if(flag==2)cout<<"row"<<" "<<ans;
    else if(flag==3)cout<<"column"<<" "<<ans;
    return 0;
}
