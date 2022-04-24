#include<bits/stdc++.h>
using namespace std;
int n,cnt,l,r,now;
bool x[400];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>l>>r;
        for(int j=l;j<=r;++j)
            x[i]=1;
    }
    int ans=0;
    for(int i=1;i<=365;++i)
        ans+=x[i];
    cout<<ans<<"\n";
    return 0;
}