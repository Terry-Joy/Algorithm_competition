#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
   int n,m;
   while(~scanf("%d%d",&n,&m))
    {
       double res,ans=0;
       for(int i=1;i<=n;++i)
       {
           res=(double)i/n*(n+m);    //映射到n+m长的数轴上
           ans+=fabs(res-floor(res+0.5));//在位置相差1的时候可以使用的接近最近的点的技巧
       } 
       ans/=(n+m);
       printf("%.4lf\n",ans*10000);
    }
   return 0;
}
