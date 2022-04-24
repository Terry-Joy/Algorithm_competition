#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#define ll long long
using namespace std;
int ma[70][70];
bool is[70][70];
int x1[2505],y1[2505];
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
      {
         cin>>ma[i][j]; 
      } 
   bool flag=1;
   int ans=0;
   for(int i=1;i<n;++i)
       for(int j=1;j<m;++j)
       {
           if(ma[i][j]&&ma[i+1][j]&&ma[i][j+1]&&ma[i+1][j+1])
           {
               x1[++ans]=i;
               y1[ans]=j;
               is[i][j]=is[i+1][j]=is[i][j+1]=is[i+1][j+1]=1; 
               continue;
           }
           if(ma[i][j]&&!is[i][j])
           {
              flag=0;
              break; 
           }
       }
   for(int i=1;i<=m;++i)
       if(ma[n][i]&&!is[n][i])
       {
          flag=0;
          break; 
       }
   for(int j=1;j<=n;++j)
       if(ma[j][m]&&!is[j][m])
       {
          flag=0;
          break; 
       }
   if(!flag)
       puts("-1");
   else
   { 
       printf("%d\n",ans);
       for(int i=1;i<=ans;++i)
         printf("%d %d\n",x1[i],y1[i]);
   }
   return 0;
}
