#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int main()
{
   scanf("%d",&n);
   for(int i=0;i<n;++i)
      scanf("%d",&a[i]);
   bool is=0;
   for(int i=1;i<n;++i)
   { 
      if(a[i]<a[i-1]&&is==0)is=1;
      if(is)
      if(a[i]>a[i-1])
        {
           puts("NO");
           return 0; 
        } 
   }
   puts("YES");
   return 0; 
}
