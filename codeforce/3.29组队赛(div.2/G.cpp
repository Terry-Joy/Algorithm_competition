#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int lw[510][510],rw[510][510],ld[510][510],rd[510][510];
int t,n,m;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
        scanf("%d%d",&n,&m);
        memset(lw,0,sizeof(lw));
        memset(rw,0,sizeof(rw));
        memset(ld,0,sizeof(ld));
        memset(rd,0,sizeof(rd));
        for(int i=1;i<=n;++i) 
            for(int j=1;j<=m;++j)
            {
               int a;
               scanf("%d",&a);
               lw[i][j]=rw[i][j]=ld[i][j]=rd[i][j]=a; 
            }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                lw[i][j]=max(lw[i][j],max(lw[i-1][j],lw[i][j-1]));

        for(int i=1;i<=n;++i)
            for(int j=m;j>=1;--j)
                rw[i][j]=max(rw[i][j],max(rw[i-1][j],rw[i][j+1]));
        
        for(int i=n;i>=1;--i)
            for(int j=1;j<=m;++j)
                ld[i][j]=max(ld[i][j],max(ld[i+1][j],ld[i][j-1]));
        for(int i=n;i>=1;--i)
            for(int j=m;j>=1;--j)
                rd[i][j]=max(rd[i][j],max(rd[i][j+1],rd[i+1][j]));
        int ans=INF;
       for(int i=2;i<n;++i) 
            for(int j=2;j<m;++j)
            {
                int min1=INF,max1=-1;
                max1=max(max1,lw[i-1][j-1]);
                max1=max(max1,rw[i-1][j+1]);
                max1=max(max1,ld[i+1][j-1]);
                max1=max(max1,rd[i+1][j+1]);
                min1=min(min1,lw[i-1][j-1]);
                min1=min(min1,rw[i-1][j+1]);
                min1=min(min1,ld[i+1][j-1]);
                min1=min(min1,rd[i+1][j+1]);
                ans=min(ans,max1-min1);
            }
       printf("%d\n",ans);
   }
   return 0; 
}

