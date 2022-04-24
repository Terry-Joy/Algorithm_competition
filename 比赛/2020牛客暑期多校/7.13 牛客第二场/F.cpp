#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5005;
int a[maxn][maxn],q[maxn],head,tail,f[maxn][maxn];
int gcd(int a,int b){return  b?gcd(b,a%b):a;}
int main()
{
   int n,m,k;
   scanf("%d%d%d",&n,&m,&k); 
   for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
          if(!a[i][j])
              for(int k=1;k*i<=n&&k*j<=m;++k)
                  a[k*i][k*j]=k;
   for(int i=1;i<=n;++i)
       for(int j=1;j<=m;++j)
           a[i][j]=i*j/a[i][j];
   int cnt=0; 
   for(int j=1;j<=m;++j)
   {
      cnt=0; 
      head=1,tail=0;
      for(int i=1;i<=n;++i)
      {   
          while(head<=tail&&a[i][j]>=a[q[tail]][j])tail--;
          q[++tail]=i;
          if(i-q[head]+1>k)head++;
          if(i>=k)f[++cnt][j]=a[q[head]][j];
      } 
   } 
   ll ans=0;
   for(int i=1;i<=cnt;++i)
   {
      head=1,tail=0;
      for(int j=1;j<=m;++j)
      {
         while(head<=tail&&f[i][j]>=f[i][q[tail]])tail--;
         q[++tail]=j;
         if(j-q[head]+1>k)head++;
         if(j>=k)ans+=f[i][q[head]]; 
      } 
   }
   printf("%lld\n",ans);
   return 0; 
}
