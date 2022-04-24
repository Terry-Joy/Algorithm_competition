#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C(ll n){
    ll ans=1;
    for(int i=1;i<=3;++i){
        ans*=(n-i+1);
        ans/=i;
    }
    return ans;
}
int main(){
    ll n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    if(n==1&&m==1)puts("0");
    else 
         cout<<C((n+1)*(m+1))-(n+1)*C(m+1)-(m+1)*C(n+1)-2*(m-n+1)*C(n+1);
    return 0;
}