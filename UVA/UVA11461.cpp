#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
int q[maxn];
int main()
{
   int a,b;
   for(int i=1;i<=100000;++i)
       q[i]=sqrt(i);
   while(~scanf("%d%d",&a,&b)&&(a|b))
   {
      printf("%d\n",q[b]-q[a-1]);
   }
   return 0; 
}
