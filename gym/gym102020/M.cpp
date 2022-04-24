#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=1e5+10;
int a[maxn],b[maxn];
char s[maxn];
int main()
{
   scanf("%s",s+1);
   int len=strlen(s+1);
   int ka=0,kb=0;
   if(len&1)
       puts("NO");
   else
   {
      for(int i=1;i<=len;++i)
      {
         if(s[i]=='A')
            a[i]++,ka++;
         else b[i]++,kb++;
         a[i]+=a[i-1];
         b[i]+=b[i-1]; 
      } 
      if(ka%2==1||kb%2==1){ 
          puts("NO");
          return 0;
      }
      int l,r;
      int k=len/2+1;
      int k2=len/2;
      int ans1,ans2;
      for(l=2;l<=k;++l)
      {
         r=l+k2-1;
         if((b[r]-b[l-1])==(kb-(b[r]-b[l-1]))&&(a[r]-a[l-1])==(ka-(a[r]-a[l-1])))
         {
            ans1=l;
            if(r==len)ans2=1;
            else ans2=r+1; 
         } 
      }
      puts("YES");
      printf("%d %d",ans1,ans2);
   } 
   return 0; 
}
