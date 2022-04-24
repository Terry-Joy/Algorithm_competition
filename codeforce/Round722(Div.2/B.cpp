#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+5;
int a[maxn];
vector<int>s,b;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        s.clear();
        b.clear();
        int ans=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            ans+=(a[i]<=0);
            if(a[i]<=0)s.pb(a[i]);
        }
        sort(s.begin(),s.end());
        int mx=2e9;
        for(int i=1;i<s.size();++i){
            mx=min(mx,abs(s[i]-s[i-1]));
        }
        for(int i=1;i<=n;++i){
            if(a[i]>0&&a[i]<=mx){
                ans++;break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}