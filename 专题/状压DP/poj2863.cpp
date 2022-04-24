#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int dp[1<<15],x[17],y[17],area[225],state[225];
int main()
{
   int n;
   while(~scanf("%d",&n)&&n)
   {
       for(int i=0;i<n;++i)
           scanf("%d%d",&x[i],&y[i]);
       int cnt=0;
       for(int i=0;i<n;++i)
           for(int j=i+1;j<n;++j)           //枚举矩形
           {
              state[++cnt]=(1<<i)|(1<<j);
              for(int k=0;k<n;++k)          //看看内部有没有点 
                  if((x[k]-x[i])*(x[k]-x[j])<=0&&(y[k]-y[i])*(y[k]-y[j])<=0)
                      state[cnt]|=(1<<k);
              if(x[i]==x[j])area[cnt]=abs(y[i]-y[j]);
              else if(y[i]==y[j])area[cnt]=abs(x[i]-x[j]);
              else area[cnt]=abs(x[i]-x[j])*abs(y[i]-y[j]);
           }
       int k=1<<n;
       memset(dp,0x3f,sizeof(dp));
       dp[0]=0;
       for(int i=0;i<k;++i) //阶段状态
          for(int j=1;j<=cnt;++j)//决策
          {
             dp[i|state[j]]=min(dp[i|state[j]],dp[i]+area[j]);
          }
       printf("%d\n",dp[k-1]);
   } 
   return 0; 
}
