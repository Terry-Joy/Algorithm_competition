#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[60][60],t,hang[60],lie[60];
const int INF=0x3f3f3f3f;
int main()
{
   cin>>t;
   while(t--)
   {
      int ans1=0,ans2=0,ans;
      int n,m;
      cin>>n>>m; 
      for(int i=1;i<=n;++i)
          hang[i]=0;
      for(int j=1;j<=m;++j)
          lie[j]=0;
      for(int i=1;i<=n;++i)
         for(int j=1;j<=m ;++j)
         {   
             cin>>a[i][j];
             if(a[i][j]==1)
                 hang[i]=1,lie[j]=1;
         }
      for(int i=1;i<=n;++i)
         if(hang[i]==0)
            ans1++;
      for(int j=1;j<=m;++j)
          if(lie[j]==0)
              ans2++;
    ans=min(ans1,ans2);
    if(ans%2==0)
        puts("Vivek");
    else
        puts("Ashish");
   } 
   return 0; 
}
