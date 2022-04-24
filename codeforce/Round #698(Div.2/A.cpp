#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
int t,n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    int ans=0,now,a;
    while(t--){ 
        ans=1;
        cin>>n;
        cin>>a;
        now=a;
        int mx=1;
        for(int i=1;i<=n-1;++i){ 
            cin>>a;
            if(now==a)mx++;
            else{ 
                ans=max(ans,mx);
                mx=1;
                now=a;
            }
        }
        ans=max(ans,mx);
        cout<<ans<<"\n";
    }
    return 0;
}
