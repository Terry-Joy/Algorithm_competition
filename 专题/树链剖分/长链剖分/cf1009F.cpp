#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
typedef long long ll;
ll *f[maxn],tmp[maxn],*id=tmp,g[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1];
int md[maxn],hson[maxn],tot,ans[maxn],a,b,n;
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
    md[x]=md[hson[x]]+1;
}
void dfs(int x,int fa){
    if(hson[x]){
        f[hson[x]]=f[x]+1;dfs(hson[x],x);ans[x]=ans[hson[x]]+1;
    }
    f[x][0]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa||y==hson[x])continue;
        f[y]=id;id+=md[y];
        dfs(y,x);
        for(int j=1;j<=md[y];++j){
            f[x][j]+=f[y][j-1];
            if(f[x][j]>f[x][ans[x]]||(f[x][j]==f[x][ans[x]]&&ans[x]>j))
                ans[x]=j;
        }
    }
    if(f[x][ans[x]]==1)ans[x]=0;//特判最大值为1的时候 因为前面ans赋值最多为0
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs1(1,0);
    f[1]=id;id+=md[1];
    dfs(1,0);
    for(int i=1;i<=n;++i)cout<<ans[i]<<"\n";
    return 0;
}