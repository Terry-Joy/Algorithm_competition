#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
   int a,b,c,d;
   scanf("%d%d%d%d",&a,&b,&c,&d);
   if(a==d)
   {
      if((a==0&&c!=0)||(d==0&&c!=0))cout<<0<<endl;
      else cout<<1<<endl; 
   }
   else cout<<0<<endl;
   return 0; 
}
