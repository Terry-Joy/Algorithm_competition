#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=2e6+10;
int a[maxn],q[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
       scanf("%d",&a[i]),a[i+n]=a[i];
   int l=1,r=1;
   q[1]=1;
   int ans=0;
   for(int i=2;i<=2*n;++i)
   {
      while(l<=r&&(i-n/2)>q[l])l++;             //队头限制
      ans=max(ans,a[i]+a[q[l]]+i-q[l]);
      while(l<=r&&a[i]-i>=a[q[r]]-q[r])r--;     //及时排除不可能的解
      q[++r]=i;
   }
   printf("%d\n",ans);
   return 0; 
}
