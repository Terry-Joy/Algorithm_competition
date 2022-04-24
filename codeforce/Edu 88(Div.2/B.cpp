#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char s[105][1010];
int n,m,x,y;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   { 
       scanf("%d%d%d%d",&n,&m,&x,&y);
       bool f=0;
       for(int i=1;i<=n;++i)
           scanf("%s",s[i]+1);
       if(2*x>y)f=1;
       int ans=0;
       for(int i=1;i<=n;++i)
       {
          int k1=0;
          int j=1;
             while(j<=m)
            { 
                k1=0;
                while(s[i][j]!='.'&&j<=m)
                    j++;
                while(s[i][j]=='.'&&j<=m)
                {
                    j++;
                    k1++; 
                } 
                if(f)
                { 
                   ans=ans+k1/2*y;
                   k1=k1-k1/2*2; 
                   ans=ans+x*k1;
                }
                else
                {
                    ans=ans+k1*x;
                    k1=0;
                }
                continue;
          }
       }
       printf("%d\n",ans);
   } 
   return 0; 
}
