#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#define ll long long

using namespace std;

int main()
{
   int t=0;
   double a;
   cin>>t;
   while(t--)
   {
      cin>>a;
      a*=1.15;
      printf("%.2lf\n",a);
   }
   return 0; 
}
