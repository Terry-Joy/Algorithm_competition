#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int head[maxn],edge[maxn<<1],next1[maxn<<1],ver[maxn<<1],tot;
bool vis[maxn];
void add(int x,int y,int z){
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
struct Node{
    int id;
    ll cnt;
};
int n,m,u,v,w,c,d,e;
bool check(int mid){
    for(int i=1;i<=n;++i)vis[i]=0;
    vis[1]=1;
    queue<Node>q;
    ll dis=1ll*mid*d;
    q.push({1,1ll*e*mid});
    while(!q.empty()){
        Node p=q.front();
        q.pop();
        int x=p.id;
        if(x==n)return 1;
        else{
            for(int i=head[x];i;i=next1[i]){
                int y=ver[i],z=edge[i];
                if(z>dis||vis[y]||!p.cnt)continue;
                vis[y]=1;
                q.push({y,p.cnt-1});
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>c>>d>>e;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    int l=0,r=maxn,mid=0;
    while(l<r){
        mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<1ll*r*c;
    return 0;
}