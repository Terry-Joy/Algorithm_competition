#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N=3e5;
const int M=3e5;
vector<int>div1[N+5],mul[N+5];
int cnt[N],a,n,m;
ll ans=0;
inline int read(){ 
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
void init(){ 
    for(int i=2;i<=N;++i){ 
        for(int j=i;j<=N;j+=i)
            div1[j].pb(i);
    } 
}
void work(int x){ 
    for(auto&v:div1[x])
        mul[v].pb(x);
}
void add(int x){ 
    if(!cnt[x])return;
    ans+=cnt[x];
    if(x+1<=N&&!cnt[x+1])work(x+1);
    cnt[x+1]+=cnt[x];
    cnt[x]=0;
}
void solve(){ 
    for(int i=2;i<=M;++i)
        if(cnt[i])work(i);
    for(int i=1;i<=m;++i){ 
        a=read();
        for(auto&v:mul[a]){ 
            add(v);
        }
        mul[a].clear();
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;++i){ 
        a=read();
        cnt[a]++;
    }
    solve();
    cout<<ans<<"\n";
    return 0;
}
