#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int main()
{
   int k;
   int a,b,t;
   scanf("%d",&k);
   while(k--)
   { 
       scanf("%d%d%d",&a,&b,&t);
       if(2*t==(a+b)&&a!=t){	//特判一下 
       		puts("2");
       		continue;
	   } 
       int s=max(1,(a-b)/(2*t-(a+b)));
       double ans=INF;
       int num;
       	 /*  cout<<s<<"\n";*/ 
       if(a==t){
       		puts("1");
       		continue;
	   }

       else for(int i=s-2;i<=s+2;++i)
       {
       		if(i%2==1)
       		{ 
            	double sum=fabs(t-(a+b)*1.0/2-1.0*(a-b)/2/i);	//计算奇数绝对值差 
            	if(ans>sum)
            	{
                	ans=sum;
                	num=i; 
            	}
			} 
       } 
       if((fabs(t-1.0*(a+b)/2)<ans)||(fabs(t-1.0*(a+b/2))==ans&&num>1))//偶数绝对值差 
       {
            num=2; 
       }
       printf("%d\n",num);
   }
   return 0; 
}
