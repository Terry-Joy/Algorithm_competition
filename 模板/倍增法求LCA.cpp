#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=5e5+5;
int f[maxn][21],t,n,m,d[maxn],tot=0,lg[maxn],s;
int head[maxn],ver[maxn<<1],next1[maxn<<1];
void add(int x,int y){
	ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){
    d[x]=d[fa]+1;//d[1]=1必须
    f[x][0]=fa;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=next1[i]){
    	int v=ver[i];
        if(v==fa)continue;
        dfs(v,x);
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])
    	x=f[x][lg[d[x]-d[y]]-1];
    if(x==y)return x;
    for(int i=lg[d[y]]-1;i>=0;--i)
        if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    int a,b;
    for(int i=1;i<=n;++i)		//预处理log2(n)+1 
    	lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=n-1;++i){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(s,0);
    for(int i=1;i<=m;++i){
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
    return 0;
}
