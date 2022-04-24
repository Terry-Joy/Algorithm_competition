#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
    scanf("%lld%lld",&n,&m);
    if(n==1||m==1)cout<<0<<"\n";
    cout<<(1ll<<n)+(1ll<<m)-2<<"\n";
    return 0;
}