#include<bits/stdc++.h>
#define pb push_back
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      if(n%4==0)
         puts("YES");
      else puts("NO");
   } 
   return 0; 
}
