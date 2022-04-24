#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
int n,t;
const int maxn=1e5+5;
vector<int>a[maxn];
int cnt[maxn],ans[maxn],m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int k,b;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)cnt[i]=0;
        for(int i=1;i<=m;++i)ans[i]=0,a[i].clear();
        for(int i=1;i<=m;++i){
            cin>>k;
            for(int j=1;j<=k;++j){
                cin>>b;
                a[i].pb(b);
            }
            ans[i]=b;
            cnt[b]++;
        }
        for(int i=1;i<=m;++i){
            if(cnt[ans[i]]>(m+1)/2){
                if(a[i].size()>=2){
                    cnt[ans[i]]--;
                    ans[i]=a[i][0];
                }
            }
        }
        bool f=1;
        for(int i=1;i<=m;++i){
            if(cnt[ans[i]]>(m+1)/2){
                f=0;break;
            }
        }
        if(f){
            cout<<"YES"<<"\n";
            for(int i=1;i<=m;++i){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}