#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int deg;
int main()
{
   int t,n,k;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&n,&k);
      deg=0;
      for(int i=1;i<n;++i)
      {
         int a,b;
         scanf("%d%d",&a,&b);
         if(a==k||b==k)deg++;
      }
      if(deg<=1)
          puts("Ayush");
      else
      {
         if((n-1)%2==0)
            puts("Ashish");
         else
            puts("Ayush"); 
      }
   }
   return 0; 
}
