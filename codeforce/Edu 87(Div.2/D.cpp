#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
int c[maxn],n,q;

void add(int x,int y)
{
   while(x<=n)
   {
      c[x]+=y;
      x+=x&-x; 
   } 
}

int ask(int x)
{
   int ans=0;
   while(x)
   {
      ans+=c[x];
      x-=x&-x; 
   } 
   return ans;
}

int main()
{
   scanf("%d%d",&n,&q);
   int a,r=-1,l=INF,l2=INF;
   for(int i=1;i<=n;++i)
   {
      scanf("%d",&a);
      l=l2=min(a,l);
      add(a,1); 
   }
   for(int i=1;i<=q;++i)
   {
       scanf("%d",&a);
       if(a>0){ 
          add(a,1);
          l2=min(l2,a);
       }
       else
       { 
			l=1,r=n; 
            a=-1*a;
            while(l<r)
            {
              int mid=l+r>>1;
              if(ask(mid)<a)l=mid+1;
                else r=mid;  
            }
            add(r,-1);
       }
   }
   for(int i=l2;i<=n;++i)
       if(ask(i)-ask(i-1)>=1)
       { 
           printf("%d",i);
           return 0; 
       }
   puts("0");
   return 0;
}
