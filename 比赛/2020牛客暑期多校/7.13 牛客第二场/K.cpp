#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const double pi=acos(-1);
const int t=399;
int T;
double r[4],si[1010],co[1010];  
void solve()
{
   scanf("%lf%lf%lf",&r[1],&r[2],&r[3]);
   sort(r+1,r+4);
   double ans=0;
   for(int i=0;i<t;++i)
      for(int j=0;j<t;++j)
         ans+=abs((r[3]*co[j]-r[1])*r[2]*si[i]-(r[2]*co[i]-r[1])*r[3]*si[j]);
   printf("%.1f\n",ans/2.0/(double)t/(double)t);
}
int main()
{
   double a=0,v=2.0*pi/(double)t;
   for(int i=0;i<=t;++i,a+=v)si[i]=sin(a),co[i]=cos(a);
   scanf("%d",&T);
   while(T--) 
       solve(); 
   return 0; 
}
