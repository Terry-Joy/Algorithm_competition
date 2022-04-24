#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
   int t,x,n;
   scanf("%d",&t);
   while(t--)
   {
      bool flag=0;
      scanf("%d%d",&n,&x);
      int len1=0,len2=0;
      int a;
      for(int i=1;i<=n;++i)
      {
        scanf("%d",&a);
        if(a%2==0)
            len1++;
        else
            len2++;
      } 
      if(len2==0)
          puts("No");
      else if(len1==0)
      {
         if(x%2==0)
            puts("No");
         else
            puts("Yes"); 
      }
      else
      {
           for(int i=1;i<=len2;i+=2)
          {
              if(len1>=(x-i)) 
             {
                flag=1;
                break; 
             }
          }
           if(flag)
               puts("Yes");
           else
               puts("No");
      }
   }
   return 0; 
}
