#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll *f[maxn],*g[maxn],tmp[maxn*3],*id=tmp,ans;
int md[maxn],dep[maxn],hson[maxn],head[maxn],next1[maxn<<1],ver[maxn<<1],tot,n;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs1(int x,int f){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs1(y,x);
        if(md[y]>md[hson[x]])hson[x]=y;
    }
    md[x]=md[hson[x]]+1;//md表示x的高度 叶子为1
}
void dfs(int x,int fa){
    if(hson[x])
        f[hson[x]]=f[x]+1,g[hson[x]]=g[x]-1,dfs(hson[x],x);
    f[x][0]=1;ans+=g[x][0];//重儿子统计
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa||y==hson[x])continue;
        f[y]=id;id+=md[y]<<1;g[y]=id;id+=md[y];
        dfs(y,x);
        for(int j=0;j<md[y];++j){
            if(j)
            ans+=f[x][j-1]*g[y][j];//轻儿子在此统计了g[y][1]即对g[x][0]的贡献 
            ans+=g[x][j+1]*f[y][j];//最多到md[y]-1
        }
        for(int j=0;j<md[y];++j){
        	g[x][j+1]+=f[x][j+1]*f[y][j];
            if(j)
            g[x][j-1]+=g[y][j];
			f[x][j+1]+=f[y][j];//最多可以更新到md[y]
        }
    }
}
int main(){
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs1(1,0);
    f[1]=id;id+=md[1]<<1;
    g[1]=id;id+=md[1];
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}