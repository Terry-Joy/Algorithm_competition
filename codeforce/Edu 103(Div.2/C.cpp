#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int t,n;
ll c[maxn],a[maxn],b[maxn],ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i)cin>>c[i];
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i)cin>>b[i];
        ll sum=0;
        for(int i=2;i<=n;++i){ 
            if(a[i]==b[i]||i==2)
                sum=abs(a[i]-b[i])+1+c[i];
            else{ 
                sum=max(sum-abs(a[i]-b[i])+c[i]+1,abs(a[i]-b[i])+1+c[i]);
            }
            ans=max(ans,sum);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
