#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        ll ans=0;
        cin>>n;
        for(ll i=1;(i*i+1)/2<=n;++i){ 
            ll b=i*i-1;
            if(b%2==0&&b>=i)ans++;
        }
        cout<<ans<<"\n";
    } 
    return 0;
}
