#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char s[1010];
int a[1010],b[1010],a1[1010],b1[1010],INF=0x3f3f3f3f;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%s",s+1);
       int n=strlen(s+1);
       for(int i=1;i<=n+1;++i)
       {
          a[i]=b[i]=a1[i]=b1[i]=0; 
       }
       for(int i=1;i<=n;++i)
       {
          if(s[i]=='1')
             a[i]++;
          else
             b[i]++;
          a[i]+=a[i-1];
          b[i]+=b[i-1]; 
       } 
       for(int i=n;i>=1;--i)
       {
            if(s[i]=='1')
                a1[i]++;
            else
                b1[i]++;
            a1[i]+=a1[i+1];
            b1[i]+=b1[i+1];
       }
       int ans=INF;
       for(int i=1;i<=n;++i)
       {
           ans=min(ans,min(b[i]+a1[i]-1,a[i]+b1[i]-1));
       }
       printf("%d\n",ans);
   }
   return 0; 
}
