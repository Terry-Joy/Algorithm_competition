#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn];
int n,m,v,p;
ll sum[maxn];
bool cmp(int x,int y){return x>y;}
int main(){
    scanf("%d%d%d%d",&n,&m,&v,&p);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i)sum[i]=(sum[i-1]+a[i]);
    int i;
    for(i=n;i>p;--i){
        if(a[i]+m>=a[p])
        if(1ll*m*(max(v-p-(n-i),0))<=1ll*(a[i]+m)*(i-p)-(sum[i-1]-sum[p-1]))break;
    }
    cout<<i<<endl;
    return 0;
}