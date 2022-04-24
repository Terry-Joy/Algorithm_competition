#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            ll a,b;
            cin>>a>>b;
            ans+=a*b;
        }
        cout<<ans<<"\n";
    }
    return 0;
}