#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#define ll long long
using namespace std;

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n,a,b,c,d;
      scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
      if(n*(a+b)<c-d||n*(a-b)>c+d)
          puts("No");
      else 
          puts("Yes");
   }
   return 0; 
}
