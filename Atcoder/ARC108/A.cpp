#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    ll s,p;
    cin>>s>>p;
    ll a=sqrt(p);
    for(ll i=1;i<=a;++i){ 
        ll x=s-i;
        if(x*i==p){ 
            puts("Yes");return 0;
        } 
    }
    puts("No");
    return 0;
}
