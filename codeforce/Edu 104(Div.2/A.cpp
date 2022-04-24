#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int t,n,a[105];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=n;++j){ 
                if(i==j)continue;
                else if(a[i]>a[j]){ 
                    ans++;break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
