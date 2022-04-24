#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      if(a>b)
          swap(a,b);
      if(a==0||b==0)
      { 
          puts("0");
          continue;
      }
      printf("%d\n",min(a,(a+b)/3));
   }
   return 0; 
}
