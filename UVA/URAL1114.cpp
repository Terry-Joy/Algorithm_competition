#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long 
using namespace std;
typedef long long ll;
ull c[55][55];
int main()
{
   for(int i=0;i<50;++i)
   {
      c[i][0]=c[i][i]=1;
      for(int j=1;j<i;++j)
         c[i][j]=(c[i-1][j]+c[i-1][j-1]); 
   }
   int n,a,b;
   cin>>n>>a>>b;
   ull ans1=0,ans2=0;
   ans1=c[n+a][n];
   ans2=c[n+b][n];
   cout<<ans1*ans2<<endl;
   return 0; 
}
