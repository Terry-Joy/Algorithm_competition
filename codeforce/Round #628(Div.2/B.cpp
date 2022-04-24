#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int a[100010];
int main()
{
   int t,n;
   cin>>t;
   while(t--)
   {
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
      sort(a+1,a+1+n);
      int m=unique(a+1,a+1+n)-(a+1);
      cout<<m<<endl; 
   }
   return 0; 
}
