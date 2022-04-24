#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=2e4+5;
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
ll sum[maxn];
int a[maxn],q[maxn],t,h;
ll solve(int n,int m)
{
   ll ans=0;
   h=1;t=0;
   for(int i=1;i<=n;++i){
   	  while(h<=t&&sum[i]<=sum[q[t]])t--;
	  q[++t]=i;
	  while(h<=t&&i-q[h]>m)h++;
	  ans=max(ans,sum[i]-sum[q[h]]);  		
   }
   return ans;
}
int main()
{
   int t,n,m,k,f=0;
   ll s,ans;
   scanf("%d",&t);
   while(t--){
      ans=0;
      scanf("%d%lld%d%d",&n,&s,&m,&k);
      for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
      int GCD=gcd(n,k);
      int len=n/GCD;
      for(int i=0;i<GCD;++i){ 
          for(int j=1,t=i;j<=2*len;t=(t+k)%n,++j)sum[j]=sum[j-1]+a[t];
          if(sum[len]<=0)ans=max(ans,solve(2*len,min(m,len)));
          else{ 
              ll res=m/len*sum[len]+solve(2*len,m%len);//能走几圈就走几圈，然后走剩下的 
              ans=max(res,ans);
               //还剩1圈+上模的 不如自己在一圈走几步 
              res=sum[len]*(m/len-1)+solve(2*len,len);
              ans=max(ans,res);  
          }
      }  
      printf("Case #%d: %lld\n",++f,max(0ll,s-ans));
   } 
   return 0; 
}
