#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      string s;
      cin>>s;
      int a=-1,b=-1,c=-1;
      int ans=0,sum=0x3f3f3f3f;
      for(int i=0;i<s.size();++i)
      {
         if(s[i]=='1')a=i;
         if(s[i]=='2')b=i;
         if(s[i]=='3')c=i;
         if(a!=-1&&b!=-1&&c!=-1)
         {
            ans=i-min(a,min(b,c))+1;
            sum=min(sum,ans);
         } 
      } 
      if(sum==0x3f3f3f3f)
          puts("0");
      else
          printf("%d\n",sum);
   }
   return 0; 
}
