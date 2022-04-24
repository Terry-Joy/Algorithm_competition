#include<bits/stdc++.h>
#define pb push_back
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
char s[maxn];
int shou[maxn];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n); 
      scanf("%s",s+1);
      int m=0;
      for(int i=1;i<n;++i)
          if(s[i]=='1'&&s[i+1]=='0')
              shou[++m]=i;
      if(m==0)
      {
         for(int i=1;i<=n;++i)
            putchar(s[i]);
         puts(""); 
      } 
      else
      {
         int b=0;
         for(int i=1;i<=n;++i)
         {
            if(s[i]=='1')
            {
               b=i;
               break; 
            } 
         }
         for(int i=1;i<b;++i)
            putchar(s[i]);
            putchar('0');
        int k=shou[m]+1;
        while(k<=n&&s[k]=='0')
        { 
            k++;
        }
        for(int i=k;i<=n;++i)
            putchar(s[i]);
        puts("");
      }
   }
   return 0; 
}
