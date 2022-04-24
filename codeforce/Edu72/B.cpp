#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   { 
      int n,x;
      scanf("%d%d",&n,&x);
   int max1=0,max2=0;
   for(int i=1;i<=n;++i)
   {
       int a,b;
      scanf("%d%d",&a,&b);
 
      max1=max(max1,a);
        max2=max(max2,a-b);
   }
   if(max1>=x)
       printf("1\n");
   else

       if(max2<=0)
        puts("-1");
    else
    {  
        cout<<1+(x-max1+max2-1)/max2<<endl;    
    }
   }
   return 0; 
}
