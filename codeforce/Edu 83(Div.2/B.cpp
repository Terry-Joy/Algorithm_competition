#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int k[110];
int main()
{ 
   int t,a;
   scanf("%d",&t);
   for(int i=1;i<=t;++i)
   {
      scanf("%d",&a);
      for(int i=1;i<=a;++i)
         scanf("%d",&k[i]);
     sort(k+1,k+1+a);
     for(int i=a;i>=1;--i) 
        cout<<k[i]<<" ";
        cout<<endl;
   }
   return 0; 
}
