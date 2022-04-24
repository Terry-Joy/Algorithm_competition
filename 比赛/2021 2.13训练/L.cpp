#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int maxn=1e6+5;
int n;
const ll INF=-1e18;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}
    return x*s;
}
inline void in(int&x){
    x=read();
}
P L[maxn],R[maxn],ld[maxn],ru[maxn];
int h[maxn],num1,num2;
bool vL[maxn],vR[maxn];
ll S(int i,int j){
    return 1ll*(ru[j].fi-ld[i].fi)*(ru[j].se-ld[i].se);
}
ll solve(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)return 0;
    int mid=l1+r1>>1,now=l2;
    ll x=S(mid,now);
    for(int i=l2+1;i<=r2;++i){
        if(S(mid,now)<=S(mid,i))
            now=i;
    }
    return max(solve(l1,mid-1,l2,now),max(S(mid,now),solve(mid+1,r1,now,r2)));
}
int main(){
    in(n);
    for(int i=1;i<=n;++i){
        in(h[i]);
        L[i].fi=-h[i];R[i].fi=h[i];
        L[i].se=R[i].se=i;
    }
    sort(L+1,L+1+n);
    sort(R+1,R+1+n);
    int pre1=1,pre2=n;
    for(int i=2;i<=n;++i){
        if(L[i].se>=L[pre1].se)vL[i]=1;
        else pre1=i;
    }
    for(int i=1;i<=n;++i){
        if(!vL[i])ld[++num1]=L[i];
    }
    for(int i=n-1;i>=1;--i){
        if(R[i].se<=R[pre2].se)vR[i]=1;
        else pre2=i;
    }
    for(int i=1;i<=n;++i){
        if(!vR[i])ru[++num2]=R[i];
    }
    cout<<solve(1,num1,1,num2)<<"\n";
    return 0;
}