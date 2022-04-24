#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
int tot,ver[maxn<<1],head[maxn],edge[maxn<<1],next1[maxn<<1];
ll dp[maxn][2],sum;
int t,n,k,a,b,c;
bool cmp(int x,int y){
    return dp[x][0]>dp[y][0];
}
void add(int x,int y,int z){
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void dfs(int now,int fa){
    vector<int>son;
    for(int i=head[now];i;i=next1[i]){
        int y=ver[i],z=edge[i];
        if(y==fa)continue;
        dfs(y,now);
        son.push_back(y);
        dp[y][0]+=1ll*z;dp[y][1]+=1ll*z;
    }
    sort(son.begin(),son.end(),cmp);
    ll ans=0;
    for(int &v:son)ans+=dp[v][0];
    sum=max(sum,ans);//本身大于k
    if(son.size()<=k){
        ll del=0;
        for(int &v:son) del=max(del,dp[v][1]-dp[v][0]);
        sum=max(sum,ans+del);   
    }else{
        ans=0;
        for(int i=0;i<k;++i)ans+=dp[son[i]][0];
        ll del=0;
        for(int i=0;i<k;++i)del=max(del,dp[son[i]][1]-dp[son[i]][0]);
        for(int i=k;i<son.size();++i)del=max(del,dp[son[i]][1]-dp[son[k-1]][0]);
        sum=max(sum,ans+del);
    }
    //要跟父亲连接
    dp[now][0]=dp[now][1]=0;
    if(son.size()<k){
        ll del=0;
        for(int&v:son)dp[now][0]+=dp[v][0],del=max(del,dp[v][1]-dp[v][0]);
        dp[now][1]=max(dp[now][0]+del,dp[now][0]);
    }else{
        if(k==1){
            for(int&v:son)dp[now][1]+=dp[v][0];
            return;
        }
        ll del=0;
        for(int i=0;i<k-1;++i)dp[now][0]+=dp[son[i]][0];
        dp[now][1]=dp[now][0];
        for(int i=k-1;i<son.size();++i)dp[now][1]+=dp[son[i]][0];
        for(int i=0;i<k-1;++i)del=max(del,dp[son[i]][1]-dp[son[i]][0]);
        for(int i=k-1;i<son.size();++i)del=max(del,dp[son[i]][1]-dp[son[k-2]][0]);
        dp[now][1]=max(dp[now][1],dp[now][0]+del);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        tot=sum=0;
        for(int i=1;i<=n;++i)head[i]=0;
        for(int i=1;i<n;++i){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        if(!k)printf("%lld\n",sum);
        else{
            dfs(1,0);
            printf("%lld\n",sum);
        }
    }
    return 0;
}