#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,a[105],k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n>>k;
        for(int i=1;i<=n;++i)cin>>a[i];
        int ans=0;
        a[n+1]=0;
        for(int i=1;i<=k;++i){ 
            ans=n+1;
            for(int j=1;j<=n;++j){ 
                if(a[j+1]>a[j]){ 
                    ans=j;break;
                }
            }
            a[ans]++;
            if(ans>n)break;
        }
        if(ans>n)ans=-1;
        cout<<ans<<"\n";
    }
    return 0;
}
