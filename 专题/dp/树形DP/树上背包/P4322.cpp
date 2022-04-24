#include<bits/stdc++.h>
#define double float
using namespace std;
typedef float db;
const int maxn=2505;
const db INF=1e9;
int n,k,s[maxn],p[maxn],r[maxn],head[maxn],ver[maxn],next1[maxn],sz[maxn],tot,sz2[maxn];
db dp[maxn][maxn],eps=5e-4;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,db ans){
    sz[x]=1;
    dp[x][1]=p[x]-s[x]*ans;
    dp[x][0]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        dfs(y,ans);
        for(int j=min(sz[x],k+1);j>=1;--j){
            for(int d=min(k+1-j,sz[y]);d>=1;--d){
                dp[x][j+d]=max(dp[x][j+d],dp[x][j]+dp[y][d]);
                //dp[x][j]=max(dp[x][j],dp[x][j]+0)
            }
           // dp[x][j][1]=max(dp[x][j][1],dp[x][j][1]+dp[y][0][0]);
        }
        sz[x]+=sz[y];
    }
}
inline int read(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch)){ch=getchar();}
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+ch-'0',ch=getchar();
	return ret;
}
db check(db x){
    dfs(0,x);
    return dp[0][k+1]>0;
}
void dfs1(int x){
    sz2[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        dfs1(y);
        sz[x]+=sz[y];
    }
}
int main(){
    k=read();n=read();
    for(int i=1;i<=n;++i){
        s[i]=read();p[i]=read();r[i]=read();
        add(r[i],i);
    }
    db l=0,r=1e4,mid;
    dfs1(0);
    while(r-l>eps){
        for(int j=0;j<=n;++j){
            for(int f=0;f<=sz[j];++f)  
                dp[j][f]=-INF;
        }
        mid=(l+r)/2.0;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.3f\n",l);
    return 0;
}