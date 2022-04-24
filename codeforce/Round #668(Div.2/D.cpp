#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int head[maxn],ver[maxn<<1],next1[maxn<<1],tot,t,n,a,b,da,db,mx,d[maxn],id;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int now,int fa){
    if(fa!=-1)d[now]=d[fa]+1;
    for(int i=head[now];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,now);
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        tot=0;
        for(int i=1;i<=n;++i)d[i]=head[i]=0;
        scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
        int x,y;
        for(int i=1;i<=n-1;++i){
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        dfs(1,-1);
        mx=-1;
        for(int i=1;i<=n;++i)
            if(d[i]>mx)
                mx=d[i],id=i;
        for(int i=1;i<=n;++i) d[i]=0;
        dfs(id,-1);
        for(int i=1;i<=n;++i)
            if(d[i]>mx)
                mx=d[i];
        for(int i=1;i<=n;++i)d[i]=0;
        dfs(a,-1);
        if(da>=d[b]){
            puts("Alice");
            continue;
        }
        if(2*da>=min(mx,db)){
            puts("Alice");
            continue;
        }
        else puts("Bob");
    }
    return 0;
}