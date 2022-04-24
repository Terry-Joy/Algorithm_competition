#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll sum=0,n,i;
int p[]={ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
void dfs(int pos,int num,int res)
{
   if(res==0){ 
      int ans=pow(n,1.0/num);
      if(pow(ans,1.0*num)>n)ans--;
      ans--;//减掉1
      if(ans>0)
      { 
        if(i&1)
            sum+=ans;
        else sum-=ans;
      }
      return;
   }
   if(pos==17)return;
   if(p[pos]*num<60)dfs(pos+1,num*p[pos],res-1);//选
   dfs(pos+1,num,res);//不选
   return;
}
int main()
{
   while(~scanf("%lld",&n))
   {
      sum=0;
      for(i=1;i<=3;++i)
         dfs(0,1,i);
      printf("%lld\n",sum+1);  
   } 
   return 0; 
}
