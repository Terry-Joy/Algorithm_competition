#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#define ll long long
using namespace std;
char s[200010];
int a[200010][27];
int main()
{
   int t;
   scanf("%d",&t);
   int n,k;
   while(t--)
   {
   	  
      scanf("%d%d",&n,&k);
      int k1;
      if(k&1)
          k1=(k/2)+1;
      else 
	  		k1=k/2;
      scanf("%s",s+1);
      for(int i=1;i<=k;++i)
      {
      	for(int j=i;j<=n;j+=k)
      	{
      		a[i][s[j]-'a'+1]++;
		  }
	  }
	  int ans=n;
	  	for(int i=1;i<=k1;++i)
	 	 {
	  	   	 int sum=0;
				int j=k+1-i;
				for(int f=1;f<=26;++f)
				{
					if((k&1)&&i==k1)
						sum=max(sum,a[i][f]);
					else
					sum=max(sum,a[i][f]+a[j][f]);	
				}	  	
			ans-=sum;
	 	 }
	 	 printf("%d\n",ans);
	 	 for(int i=1;i<=k;++i)
      {
      	for(int j=i;j<=n;j+=k)
      	{
      		a[i][s[j]-'a'+1]--;
		  }
	  }
    }
   return 0; 
}
