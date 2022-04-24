#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
int j,n1,n2;
ll a[20],low,high,ans;
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b)
{
   if((double)a/gcd(a,b)*b>high)return high+1;
   return a/gcd(a,b)*b; 
}
void dfs(int pos,ll sum,int cnt,ll num,bool flag)
{
	sum=lcm(sum,a[pos]);
	if(sum>num)return; 
	if(flag){
		if(cnt&1){
			ans+=(num/sum);	
		}
		else ans-=(num/sum);
	}
	else{
		if(cnt&1)ans-=(num/sum);
		else ans+=(num/sum);
	}
	for(int i=pos+1;i<=n1;++i)
		dfs(i,sum,cnt+1,num,flag);
}
int main()
{
   while(~scanf("%d%d%lld%lld",&n1,&n2,&low,&high))
   {
   	  if(n1==0&&n2==0&&low==0&&high==0)break;
      ans=0; 
      ll LCM=1; 
      for(int i=1;i<=n1;++i)
         scanf("%lld",&a[i]);
      ll b;
      for(int j=1;j<=n2;++j)
      {
          scanf("%lld",&b);
          LCM=lcm(LCM,b);  
      } 
      for(int i=1;i<=n1;++i)
      	  dfs(i,a[i],1,high,1);
      for(int i=1;i<=n1;++i)
      	  dfs(i,a[i],1,low-1,0);
      for(int i=1;i<=n1;++i)
          a[i]=lcm(a[i],LCM);
      for(int i=1;i<=n1;++i)
      	  dfs(i,a[i],1,high,0);
      for(int i=1;i<=n1;++i)
      	  dfs(i,a[i],1,low-1,1);
      printf("%lld\n",ans);
   }
   return 0; 
}