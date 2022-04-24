#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e4+5;
ll a[maxn],d[66],p[66],ask;
int t,n,q,cnt=0;
void add(ll x){
    for(int i=63;i>=0;--i){
        if(x&(1ll<<i)){
            if(d[i])x^=d[i];
            else{
                d[i]=x;break;
            }
        }
    }
}
void rebuild(){
    for(int i=63;i>=0;--i)
        for(int j=i-1;j>=0;--j)
            if(d[i]&(1ll<<j))d[i]^=d[j];
    for(int i=0;i<=63;++i)
        if(d[i])p[cnt++]=d[i];
}
ll get_kth(int k){
    if(k>=(1ll<<cnt))return -1;
    ll ans=0;
    for(int i=63;i>=0;--i)
        if(k&(1ll<<i))ans^=p[i];
    return ans;
}
int main(){
    scanf("%d",&t);
    for(int j=1;j<=t;++j){
        zero=0;
        for(int i=0;i<=63;++i)d[i]=p[i]=0;
        printf("Case #%d:\n",j);
        scanf("%d",&n);
        cnt=0;
        for(int i=1;i<=n;++i)scanf("%lld",&a[i]),add(a[i]);
        rebuild();
        scanf("%d",&q);
        for(int i=1;i<=q;++i){
            scanf("%lld",&ask);
            if(cnt<n)ask--;
            printf("%lld\n",get_kth(ask));
        }
    }
    return 0;
}