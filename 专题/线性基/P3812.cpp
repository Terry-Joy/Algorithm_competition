#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[60],d[60];
void add(ll x){
    for(int i=52;i>=0;--i){
        if(x&(1ll<<i)){
            if(d[i])x^=d[i];
            else{
                d[i]=x;
                break;
            }
        }
    }
}
ll get_max(){
    ll ans=0;
    for(int i=52;i>=0;--i){
        if((ans^d[i])>ans)ans^=d[i];
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]),add(a[i]);
    cout<<get_max()<<"\n";
    return 0;
}