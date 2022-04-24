#include<iostream>
#include<cstdio>
#include<cmath> 

using namespace std;
typedef long long ll;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n,m,k;
      scanf("%d%d%d",&n,&m,&k);
      int a=n/k;
      if(m<=a)
         printf("%d\n",m);
      else
      {
         m-=a;
         if(m/(k-1)==0)
         	cout<<a-1<<"\n";
         else
         	cout<<a-ceil(1.0*m/(k-1))<<"\n";
      } 
   }
   return 0; 
}
