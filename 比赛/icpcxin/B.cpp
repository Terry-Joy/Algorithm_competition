#include<bits/stdc++.h>

using namespace std;
const int maxn=5e5+5;
int col[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,n,m;
int ok=0;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int c){
    if(col[x]){
        if(col[x]+c==3)ok=1;
        return;
    }
    col[x]=c;
    for(int i=head[x];i;i=next1[i]){
        dfs(ver[i],3-c);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;++i){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        if(!col[i])dfs(i,1),ans++;
    }
    if(!ok)ans++;
    cout<<ans-1<<"\n";
    return 0;
}