#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double pi=3.14159265395;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      double n;
      scanf("%lf",&n);
      printf("%.9lf\n",cos(pi/(4*n))*1.0/(sin(pi/(2.0*n)))); 
   }
   return 0; 
}
