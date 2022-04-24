#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=1e5+5;   
int st[maxn];
int main()
{
   int n,f=0;
   while(~scanf("%d",&n))
   {
      int x,top=0,ans=0;
      for(int i=1;i<=n;++i)
      { 
         scanf("%d",&x);
         while(top!=0&&st[top]>x)
              ans++,top--;
         if(top==0||st[top]<x)
             if(x!=0)
              st[++top]=x;
      }
      while(top!=0)
          top--,ans++;
      printf("Case %d: %d\n",++f,ans);
   } 
   return 0; 
}
