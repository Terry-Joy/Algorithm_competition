#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
int main()
{
   int t,n,mx;
   scanf("%d",&t);
   while(t--)
   {
       mx=-1;
       scanf("%d",&n);
       int sum=0;
       for(int i=1;i<=n;++i)
       { 
           scanf("%d",&a[i]);
           mx=max(mx,a[i]);
           sum+=a[i];
       }
       if(mx>sum-mx)puts("T");
       else cout<<((sum&1)?"T\n":"HL\n");
   } 
   return 0; 
}
