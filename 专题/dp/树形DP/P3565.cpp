#include<bits/stdc++.h>

using namespace std;
const int maxn=5005;
int f[maxn][maxn],g[maxn][maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,n,ans;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){
    f[x][0]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
        for(int j=0;j<n;++j){
            ans+=f[x][j]*g[y][j+1];
            if(j)
                ans+=g[x][j]*f[y][j-1];//g[x][0]已计算
        }
        for(int j=0;j<n;++j){
            g[x][j+1]+=f[x][j+1]*f[y][j];
            g[x][j]+=g[y][j+1];
            if(j)
                f[x][j]+=f[y][j-1];
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}