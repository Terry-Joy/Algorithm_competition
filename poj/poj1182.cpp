#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a,b,c,fa[160000];
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
void emerge(int x,int y)
{
   fa[find(x)]=find(y); 
}
int main()
{ 
    scanf("%d%d",&n,&k);
    for(int i=1;i<=3*n;++i)
        fa[i]=i;
    int ans=0;
    for(int i=1;i<=k;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(b<1||b>n||c<1||c>n)
            ans++;
        else if(a==1)
        {
            if(find(b)==find(c+n)||find(b)==find(c+2*n))
                ans++;
            else
            {
               emerge(b,c);
               emerge(b+n,c+n);
               emerge(b+2*n,c+2*n); 
            }
        }
        else
        {
           if(b==c||find(b)==find(c)||find(b)==find(c+n))
              ans++;
           else
           {
              emerge(b,c+2*n);
              emerge(b+n,c);
              emerge(b+2*n,c+n); 
           } 
        }
    }
    printf("%d\n",ans);
    return 0;
}
