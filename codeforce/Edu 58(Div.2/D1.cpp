#include<iostream>
#include<cstdio>
#include<cstring> 

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int dp[maxn][8],head[maxn],next1[maxn<<1],ver[maxn<<1],tot,prime[maxn],cnt,a[maxn],y[maxn][8],ans=1;
bool v[maxn];
void init(){
    v[1]=1;
    for(int i=2;i<=maxn-5;++i){ 
        if(!v[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j){ 
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void add(int x,int y){ 
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int now,int fa){
   for(int i=head[now];i;i=next1[i]){ 
       int z=ver[i];
       if(z==fa)continue;
       dfs(z,now);
       for(int j=1;j<=y[now][0];++j){ 
          for(int k=1;k<=y[z][0];++k){ 
              if(y[now][j]==y[z][k]){               	  
                   ans=max(ans,dp[now][j]+dp[z][k]);
                   dp[now][j]=max(dp[now][j],dp[z][k]+1); 
              } 
          }
       } 
   } 
}
int main()
{
   init();
   int n,u,v;
   scanf("%d",&n);
   bool flag=0;
   for(int i=1;i<=n;++i){ 
     scanf("%d",&a[i]);
     if(a[i]!=1)flag=1;
   }
   for(int i=1;i<n;++i){
       scanf("%d%d",&u,&v);
       add(u,v);add(v,u); 
   }  
   if(!flag){ 
       puts("0");
       return 0;
   }
   for(int i=1;i<=n;++i){ 
       y[i][0]=0;
       for(int j=1;prime[j]*prime[j]<=a[i];++j){ 
           if(a[i]%prime[j]==0){ 
              y[i][++y[i][0]]=prime[j],dp[i][y[i][0]]=1;
              while(a[i]%prime[j]==0)a[i]/=prime[j];
           }
       }
       if(a[i]>1)y[i][++y[i][0]]=a[i],dp[i][y[i][0]]=1;
   }
   dfs(1,-1);
   printf("%d\n",ans);
   return 0; 
}
