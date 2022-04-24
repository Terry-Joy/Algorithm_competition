#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s[1010];
int a[1010];
int main()
{
   int t,f=0;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%s",s);
      int len=strlen(s);
      int sum=0,cnt1=0,cnt2=0,cnt3=0;   //%3==1 ==2 ==0
      bool flag=0;
      for(int i=0;i<len;++i)
      { 
          a[i]=s[i]-'0';
          sum+=a[i];
          if(a[i]%3==0)cnt3++;
          else if(a[i]%3==1)cnt1++;
          else cnt2++;
      }
      if(sum%3==0)
      {
          if(cnt3&1)
              printf("Case %d: S\n",++f);
          else
              printf("Case %d: T\n",++f);
      } 
      else if(sum%3==1)
      {
         if(cnt1==0)
            printf("Case %d: T\n",++f);
         else
         {
            if(cnt3&1) 
                printf("Case %d: T\n",++f);
            else
                printf("Case %d: S\n",++f);
         } 
      }
      else if(sum%3==2)
      {
         if(cnt2==0)
            printf("Case %d: T\n",++f);
         else
         {
            if(cnt3&1) 
                printf("Case %d: T\n",++f);
            else
                printf("Case %d: S\n",++f);
         } 
      }
   }
   return 0; 
}
