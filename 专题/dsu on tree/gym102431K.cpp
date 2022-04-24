#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int son[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],sz[maxn],cnt[maxn],ans[maxn],sum,T,x,y,tot,hs,n;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs1(int x,int f){
    sz[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs1(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
}
void cal(int x,int f,int val){
    cnt[x]+=val;
    if(x<n&&x>1){
        if(cnt[x-1]&&cnt[x+1])sum-=val;
        else if(cnt[x-1]==0&&cnt[x+1]==0)sum+=val;
    }else if(x==n){
        if(!cnt[x-1])sum+=val;
    }else if(x==1){
        if(!cnt[x+1])sum+=val;
    }
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
    ans[x]=sum;
    hs=0;
    if(!op)cal(x,f,-1);
}
int main(){
    scanf("%d",&T);
    int t=0;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)cnt[i]=0,son[i]=0,head[i]=0;//多组数据重儿子也得清空
        sum=tot=0;
        for(int i=1;i<n;++i){
            scanf("%d%d",&x,&y);
            add(x,y);add(y,x);
        }
        dfs1(1,0);
        dsu(1,0,0);
        printf("Case #%d:",++t);
        for(int i=1;i<=n;++i)
            cout<<" "<<ans[i];
        puts("");
    }
    return 0;
}