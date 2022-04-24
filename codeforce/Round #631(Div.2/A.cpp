#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 
using namespace std;
int flag[1005];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      memset(flag,0,sizeof(flag));
      int n,x;
      cin>>n>>x;
      int a;
      for(int i=1;i<=n;++i)
      {
         cin>>a;
         flag[a]=1;
      }
      for(int i=1;;++i)
      { 
        if(!flag[i])
        {     
            flag[i]=1;
            x--;
        }
        if(x==0)
            break;
      } 
      int ans;
      for(int i=1;i<=1005;++i)
          if(!flag[i])
          {
              ans=i-1;
              break;
          }
      cout<<ans<<endl;
   }
   return 0; 
}
