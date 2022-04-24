#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
   int n;
   string a;
   cin>>n;
   cin>>a;
   bool flag=0;
   for(int i=0;i<n-1;++i)
   {
      if(a[i]>a[i+1])
      {
         puts("YES");
         printf("%d %d\n",i+1,i+2);
         flag=1;
         break; 
      } 
   }
   if(!flag)
       puts("NO");
   return 0; 
}
