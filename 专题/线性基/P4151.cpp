#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+5;
const int maxm=1e5+5;
int head[maxn],ver[maxm<<1],next1[maxm<<1],tot;
ll edge[maxm<<1],d[65],val[maxn];
bool v[maxn];
void add(int x,int y,ll z){
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void insert(ll x){
    for(int i=63;i>=0;--i){
        if(x&(1ll<<i)){
            if(d[i])x^=d[i];
            else{
                d[i]=x;break;
            }
        }
    }
}
ll ask(ll x){
    ll ans=x;
    for(int i=63;i>=0;--i){
        if((ans^d[i])>ans)ans^=d[i];
    }
    return ans;
}
void dfs(int now,ll x){
    val[now]=x;v[now]=1;
    for(int i=head[now];i;i=next1[i]){
        int y=ver[i];
        if(!v[y])dfs(y,x^edge[i]);
        else insert(x^edge[i]^val[y]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,y;
    ll z;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    cout<<ask(val[n])<<"\n";
    return 0;
}