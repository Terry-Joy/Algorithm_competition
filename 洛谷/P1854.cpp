#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
int dp[105][105];
int path[105][105];
int a[105][105];
const ll INF=-0x3f3f3f3f;
void print(int x,int y)
{
    if(path[x][y]==y){ printf("%d ",y);return;}
    print(x-1,path[x][y]);
    printf("%d ",y);
}
int main()
{
   int f,v;
   scanf("%d%d",&f,&v);
   for(int i=1;i<=f;++i)
      for(int j=1;j<=v;++j)
         scanf("%d",&a[i][j]);
   for(int i=1;i<=f;++i)
       for(int j=1;j<=v;++j)
           dp[i][j]=INF;
   for(int i=1;i<=v-f;++i)
      dp[1][i]=a[1][i],path[1][i]=i;//先赋值第一层作为递归终点
   for(int i=2;i<=f;++i)
      for(int j=i;j<=v-(f-i);++j)
          for(int k=i-1;k<j;++k)
             if((dp[i][j]<dp[i-1][k]+a[i][j])&&dp[i-1][k]!=INF)
             {
                dp[i][j]=dp[i-1][k]+a[i][j];
                path[i][j]=k;
             } 
   int ans=INF;
   int cnt=0;
   for(int i=1;i<=v;++i)
   { 
       if(ans<dp[f][i])
       {
          ans=dp[f][i];
          cnt=i; 
       }
   }
   printf("%d\n",ans);
   print(f,cnt);
   return 0; 
}
