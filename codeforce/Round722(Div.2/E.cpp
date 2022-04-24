#include<bits/stdc++.h>
#define pb push_back
#define fi first 
#define se second 
using namespace std;
typedef pair<int,int>P;
const int maxn=3e5+5;
vector<int>G1[maxn],G2[maxn];
int t,n,fa,in[maxn],ti,out[maxn],ans=0;
set<P>s;
void dfs2(int x){
    in[x]=++ti;
    for(auto&v:G2[x]){
        dfs2(v);
    }
    out[x]=ti;
}
void dfs1(int x){
    bool del=0,add=0;
    auto it=s.lower_bound({in[x],out[x]});
    P a;
    if(it==s.end()||out[x]<(*it).fi){
        if(it!=s.begin()){
            it--;
            if(in[x]<=(*it).se){
                a=*it;
                s.erase(it);
                del=1;
            }
        }
        s.insert({in[x],out[x]});
        add=1;
    }
    ans=max(ans,(int)s.size());
    for(auto&v:G1[x]){
        dfs1(v);
    }
    if(add)s.erase({in[x],out[x]});
    if(del)s.insert(a);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        s.clear();
        for(int i=1;i<=n;++i)G1[i].clear(),G2[i].clear();
        for(int i=2;i<=n;++i){
            scanf("%d",&fa);
            G1[fa].pb(i);
        }
        for(int i=2;i<=n;++i){
            scanf("%d",&fa);
            G2[fa].pb(i);
        }
        ti=0;
        dfs2(1);
        dfs1(1);
        cout<<ans<<"\n";
    }
    return 0;
}