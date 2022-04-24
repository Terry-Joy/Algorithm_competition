#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define ll long long 

using namespace std;
int n,a[100],ans,sum;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
       scanf("%d",&a[i]);
   scanf("%d",&sum);
   ans=a[1];
   for(int i=2;i<=n;++i)
   {
      if(sum%a[i]<sum%ans)
         ans=a[i]; 
   }
   cout<<ans<<endl;
   return 0; 
}
