#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,a[305][305];
int main()
{
   int t,n,k;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&n,&k);
      for(int i=1;i<=n;++i)
         for(int j=1;j<=n;++j)
            a[i][j]=0;
      cout<<(k%n==0?0:2)<<'\n';
      int f=k%n,m=k/n;
      for(int i=1;i<=f;++i)
        for(int j=i;j<=i+m;++j)
            if(j!=n)
                 a[i][(j%n)]=1;
            else
                 a[i][j]=1;
      for(int i=f+1;i<=n;++i)
        for(int j=i;j<=i+m-1;++j)
            if(j!=n)
                a[i][j%n]=1;  
            else 
                a[i][j]=1;
      for(int i=1;i<=n;++i)
      {
         for(int j=1;j<=n;++j)
            printf("%d",a[i][j]);
        puts(""); 
      }
   } 
   return 0; 
}
