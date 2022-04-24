#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int n,t;
const int maxn=2e5+5;
const int mod=1e9+7;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int mn=*min_element(a+1,a+1+n);
        int cnt=0;
        bool f=1;
        for(int i=1;i<=n;++i){
            if(a[i]==mn)cnt++;  
            if((mn&a[i])!=mn)f=0;
        }
        if(!f){
            cout<<0<<"\n";
        }else{
            ll ans=1;
            for(int i=1;i<=n-2;++i)ans*=i,ans%=mod;
            ans=ans*cnt%mod*(cnt-1)%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}