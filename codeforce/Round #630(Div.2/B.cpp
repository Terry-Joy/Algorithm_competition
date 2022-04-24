#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#define ll long long
using namespace std;
int c[1010],a[1010];
int gcd(int a,int b)
{
   return b?gcd(b,a%b):a; 
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   { 
       int n;
       scanf("%d",&n);
   	for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
   	for(int i=1;i<=n;++i)
       c[i]=1;
   int ans=0;
   for(int i=1;i<=n;++i)
       for(int j=i+1;j<=n;++j){ 
           if(gcd(a[i],a[j])==1&&c[i]==c[j])
           {   
               c[j]++;
               
           }
           ans=max(ans,c[j]);
	} 
   printf("%d\n",ans);
   for(int i=1;i<n;++i)
       printf("%d ",c[i]);
    printf("%d\n",c[n]);
   }
   return 0; 
}
