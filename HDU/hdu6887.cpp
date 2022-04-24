#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct Node{ 
    int id,w;
    bool operator<(const Node&a){ 
        if(w==a.w)return id<a.id;
        return w>a.w;
    }
}a[105];
int t,n,m,k;
int main()
{
   int t;
   scanf("%d",&t); 
   while(t--){ 
       scanf("%d%d%d",&n,&m,&k);
       for(int i=1;i<=n;++i)
          scanf("%d",&a[i].w),a[i].id=i;
       if(k!=0)sort(a+1,a+1+n);
       for(int i=1;i<=n-1;++i)
           printf("%d ",a[i].id);
       printf("%d\n",a[n].id);
   }
   return 0; 
}
