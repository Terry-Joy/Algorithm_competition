#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int a[110],b[110];
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;++i)
   {
      cin>>a[i]; 
   }
   int s1=0,s2=0;
   for(int i=1;i<=n;++i)
   {
      cin>>b[i];
      if(a[i]>b[i])s1++;
      else if(a[i]<b[i])s2++;
   }
   if(s1==0)
       puts("-1");
   else
      if(s1>s2) 
        puts("1");
   else 
       if(s1==s2)
           puts("2");
   else
      cout<<((s2)/s1)+1;
   return 0; 
}
