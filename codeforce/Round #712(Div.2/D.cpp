#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+5;
int n,t,p;
typedef pair<int,int>P;
bool v[maxn];
P a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        ll ans=0;
        cin>>n>>p;
        for(int i=1;i<=n;++i)cin>>a[i].fi,a[i].se=i;
        for(int i=1;i<=n;++i)v[i]=0;
        sort(a+1,a+1+n);
        int cnt=0;
        for(int i=1;i<=n;++i){
            int pos=a[i].se,val=a[i].fi;
            if(val>=p)break;
            for(int j=pos-1;j>=1;--j){
                if(v[j])break;
                if(a[j].fi%val)break;
                else{
                    ans+=val;
                    v[j]=1;
                }   
            }
            for(int j=pos+1;j<=n;++j){
                if(v[j])break;
                if(a[j].fi%val)break;
                else{
                    ans+=val;
                    v[j]=1;
                }
            }
        }
        for(int i=1;i<n;++i)
        if(!v[i])
            ans+=p;
        cout<<ans<<'\n';
    }
    return 0;
}
