#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int t,n,m,a[maxn],b[maxn],c[maxn];
vector<int>G[maxn],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        int num=0;
        cin>>n>>m;
        for(int i=1;i<=n;++i)G[i].clear();
        ans.clear();
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i)cin>>b[i];
        for(int i=1;i<=m;++i)cin>>c[i];
        int is=0;
        for(int i=1;i<=n;++i){ 
            if(b[i]==c[m]){ is=i;break;}
        }
        if(!is){ 
            cout<<"NO\n";continue;
        }
        for(int i=1;i<=n;++i){ 
            if(a[i]!=b[i])G[b[i]].pb(i),num++;
        }
        for(int i=m;i;--i){ 
            if(G[c[i]].empty()){ 
                if(i==m)ans.pb(is);
                else ans.pb(ans[0]);
                continue;
            }
            ans.pb(G[c[i]].back());
            G[c[i]].pop_back();
            num--;
        }
        if(num){ cout<<"NO\n";continue;}
        else{ 
            cout<<"YES\n";
            reverse(ans.begin(),ans.end());
            for(auto&v:ans){ 
                cout<<v<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
