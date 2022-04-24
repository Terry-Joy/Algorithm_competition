#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int dfn[maxn],times,fa[maxn],cir[maxn],circnt,cirval[maxn];
bool cirsign[maxn];
int tot,head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],cost[maxn];
int n,a,b,c;
ll d[maxn],ans,pre[maxn],pre1[maxn],suf[maxn],suf1[maxn];
void add(int x,int y,int z){ 
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x){ 
    dfn[x]=++times;
    for(int i=head[x];i;i=next1[i]){ 
        int y=ver[i];
        if(y==fa[x])continue;
        if(!dfn[y]){ 
            fa[y]=x;cost[y]=edge[i];
            dfs(y);
        }else if(dfn[y]>dfn[x]){//回溯找到环 
            for(;y!=x;y=fa[y]){ 
                cirsign[y]=1;
                cir[++circnt]=y;
                cirval[circnt]=cost[y];
            }
            cirsign[x]=1;
            cir[++circnt]=x;
            cirval[circnt]=edge[i];
        }
    }
}
void dp(int x,int fa){ 
    for(int i=head[x];i;i=next1[i]){ 
        int y=ver[i];
        if(!cirsign[y]&&y!=fa){//找环上每一个点的子树的直径 
            dp(y,x);
            ans=max(ans,d[x]+d[y]+edge[i]);
            d[x]=max(d[x],d[y]+edge[i]);
        } 
    }
}
int main(){ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i){ 
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1);//处理环
    for(int i=1;i<=circnt;++i)dp(cir[i],0);
    ll sum=0,mx=0;
    for(int i=1;i<=circnt;++i){ //正序求一遍
        sum+=cirval[i-1];
        pre[i]=max(pre[i-1],sum+d[cir[i]]);
        pre1[i]=max(pre1[i-1],mx+sum+d[cir[i]]);
        mx=max(mx,d[cir[i]]-sum);
    }
    sum=mx=0;
    ll num=cirval[circnt];
    cirval[circnt]=0;
    for(int i=circnt;i>=1;--i){                  //逆序求一遍
        sum+=cirval[i];
        suf[i]=max(suf[i+1],sum+d[cir[i]]);
        suf1[i]=max(suf1[i+1],mx+sum+d[cir[i]]);//顺序要看清楚
        mx=max(mx,d[cir[i]]-sum);
    }
    ll ans1=pre1[circnt],tmp=0;                       //枚举断边
    for(int i=1;i<circnt;++i){
        tmp=0;
        tmp=max(pre1[i],suf1[i+1]);
        tmp=max(tmp,pre[i]+suf[i+1]+num);
        ans1=min(ans1,tmp);
    }
    ans=max(ans,ans1);
    printf("%.1lf",ans/2.0);
    return 0;
}
