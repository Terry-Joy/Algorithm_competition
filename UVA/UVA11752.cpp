#include<iostream>
#include<cstring>
#include<set>
#include<cstdio>
#include<cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
bool v[70];
int p[70],cnt=0;
void init()
{ 
   memset(v,0,sizeof(v)); 
   for(int i=2;i<=64;++i){ 
        if(v[i]){ 
            p[++cnt]=i;
            continue;
       }
       for(int j=i+i;j<=64;j+=i)
           v[j]=1;
   } 
}
int main()
{
   init();
   set<ull>ans;
   ans.insert(1);
   ull up=(1ll)<<16;//底数上限 指数最小4
   for(ull i=2;i<up;++i)
   {
      int mx=ceil((64*log(2))/log(i))-1; //枚举 指数上限
      ull tmp=i*i*i*i;
      ans.insert(tmp);
      for(int j=2;p[j]<=mx;++j)
      {
         tmp*=((p[j]-p[j-1])==1?i:i*i);//4以后合数差为2 2 1 1 2 2 1 1分布
         ans.insert(tmp); 
      }
   }
   for(auto &v:ans)
       printf("%llu\n",v);
   return 0; 
}
