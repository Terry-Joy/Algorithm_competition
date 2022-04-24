#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int n,t,k;
int ans[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i)ans[i]=0;
        if(n<=2*k)cout<<-1<<"\n";
        else{
            int cnt=n;
            for(int i=2;i<=n,cnt>=n-k+1;i+=2,cnt--){
                ans[i]=cnt;
            }
            for(int i=1;i<=n;++i){
                if(!ans[i])ans[i]=cnt,cnt--;
            }
            for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
            cout<<"\n";
        }
    }
    return 0;
}