#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
const int mod=1e6;
int c[210][210];

int main()
{
   c[0][0]=1;
   for(int i=1;i<=200;++i)
   {
      c[i][0]=1; 
      for(int j=1;j<=i;++j)
         c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
   }
   int n,m;
   while(~scanf("%d%d",&n,&m)&&n&&m)
        printf("%d\n",c[n+m-1][m-1]);
   return 0; 
}
