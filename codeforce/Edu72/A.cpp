#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      int k=(b+c-a)/2;
      if(b+c-a<0)
          printf("%d\n",c+1);
      else{ 
        if(k==0)
            printf("%d\n",c);
        else if(k>0&&k<c)
            printf("%d\n",c-k);
        else if(k>=c)
            printf("0\n");
      }
   }
   return 0; 
}
