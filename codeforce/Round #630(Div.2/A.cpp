#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#define ll long long
using namespace std;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int a,b,c,d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      int x,y,x1,y1,x2,y2;
      scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
      if((c>0||d>0)&&(y1==y2)||((a>0||b>0)&&(x1==x2)))
          puts("NO");
      else
          if((x-a+b>=x1)&&(x-a+b<=x2)&&(y-c+d>=y1)&&(y-c+d<=y2))
         puts("YES");
      else
         puts("NO"); 
   }
   return 0; 
}
