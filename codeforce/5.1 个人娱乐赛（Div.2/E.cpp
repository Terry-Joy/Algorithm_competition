#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define ll long long 

using namespace std;
int n,m,s[5010],p[5010],r[5010],a[5010],ans[5010];
bool cmp(int a,int b)
{
   return s[a]<s[b]; 
}
int main()
{
   int n,m,i,j;
   scanf("%d%d",&n,&m);
   for(i=1;i<=n;++i)
       scanf("%d",&s[i]),a[i]=i;
   for(i=1;i<=m;++i)
       scanf("%d",&p[i]);
   for(i=1;i<=m;++i)
       scanf("%d",&r[i]);
   sort(a+1,a+1+n,cmp);
   int k;
   for(i=n;i>=1;--i)
   {    
       int mx=0x3f3f3f3f;
       k=0;
       for(j=1;j<=m;++j)
        { 
            if(p[j]>=s[a[i]])
            {
               if(r[j]<mx)
                  mx=r[j],k=j; 
            }
        } 
       if(!k){ 
            puts("impossible");
            return 0;
       }
       p[k]=-1;    
       ans[a[i]]=k;
   }
   for(i=1;i<=n;++i)
       printf("%d ",ans[i]);
   return 0; 
}
