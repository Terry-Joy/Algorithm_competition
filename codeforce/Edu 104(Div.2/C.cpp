#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int t,n,ans[105];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n;
        n--;
        if(n&1){ 
            for(int i=1;i<=n/2;++i)ans[i]=1;
            ans[(n+1)/2]=0;
            for(int i=(n+1)/2+1;i<=n;++i)ans[i]=-1;
        }else{ 
            for(int i=1;i<=n/2;++i)ans[i]=1;
            for(int i=n/2+1;i<=n;++i)ans[i]=-1;
        }
        for(int i=n;i>=1;--i){ 
            for(int j=1;j<=i;++j)cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
