#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
struct Point{
    ll x,y;
}st,ed,cur;
char s[maxn];
int n;
ll X[maxn],Y[maxn];
int check(ll x){
    ll d = x/n;
    cur.x=st.x+d*X[n];
    cur.y=st.y+d*Y[n];
    cur.x=cur.x+X[x%n];
    cur.y=cur.y+Y[x%n];
    ll dis=abs(cur.x-ed.x)+abs(cur.y-ed.y);
    return dis<=x;
}
int main(){
    scanf("%lld%lld%lld%lld",&st.x,&st.y,&ed.x,&ed.y);
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        X[i]=X[i-1];Y[i]=Y[i-1];
        X[i]+=(s[i]=='R');
        X[i]-=(s[i]=='L');
        Y[i]+=(s[i]=='U');
        Y[i]-=(s[i]=='D');
    }
    ll l=0,r=1e15,mid;
    while(l<r){
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==1e15) cout<<-1;
    else cout<<l;
    return 0;
}
