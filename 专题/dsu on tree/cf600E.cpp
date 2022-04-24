#include<bits/stdc++.h>
using namespace std;.
typedef long long ll;
const int maxn=3e5+5;
int sz[maxn],son[maxn],hs,tot,head[maxn],next1[maxn<<1],ver[maxn<<1],cnt[maxn],a[maxn],n,mx;
ll ans[maxn],nowans;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int f){
    sz[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
}
void cal(int x,int f,int val){
    if(val==1){
        cnt[a[x]]++;
        if(cnt[a[x]]>mx)mx=cnt[a[x]],nowans=a[x];
        else if(cnt[a[x]]==mx)nowans+=a[x];
    }else cnt[a[x]]--;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==hs)continue;
        cal(y,x,val);
    }
}
void dsu(int x,int f,bool op){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==son[x])continue;
        dsu(y,x,0);
    }
    if(son[x])dsu(son[x],x,1),hs=son[x];
    cal(x,f,1);
    ans[x]=nowans;
    hs=0;
    if(!op)cal(x,f,-1),mx=nowans=0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1,0);
    dsu(1,0,0);
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}