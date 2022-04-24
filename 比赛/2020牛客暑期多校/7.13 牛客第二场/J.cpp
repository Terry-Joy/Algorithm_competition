#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn],ans[maxn],x,y;
bool v[maxn];
int exgcd(int a,int b,int &x,int &y){
   if(!b){ x=1,y=0;return a;}
   int d=exgcd(b,a%b,x,y);
   int z=x;x=y;y=z-y*(a/b);
   return d; 
}
int inv(int k,int size){
    exgcd(k,size,x,y);
    return (x%size+size)%size;
}
int main()
{ 
   int n,k;
   scanf("%d%d",&n,&k);
   for(int i=1;i<=n;++i)
      scanf("%d",&a[i]);
   for(int i=1;i<=n;++i){
      if(v[i])continue;
      vector<int>tmp;
      tmp.pb(i);v[i]=1;
      int now=a[i];
      while(now!=i){ 
          tmp.pb(now);v[now]=1;
          now=a[now];  
      } 
      int sz=tmp.size();
      int ni=inv(k,sz);
      for(int i=0;i<sz;++i)
         ans[tmp[i]]=tmp[(i+ni)%sz]; 
   } 
   for(int i=1;i<=n;++i)
       printf("%d ",ans[i]);
   return 0; 
}
