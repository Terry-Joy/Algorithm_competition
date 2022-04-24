#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   { 
   int x1,y1,x2,y2;
   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   printf("%lld\n",1ll*abs(x1-x2)*abs(y1-y2)+1);   
   }
   return 0; 
}
