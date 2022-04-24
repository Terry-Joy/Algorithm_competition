#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define ll long long 

using namespace std;
int n,a;
double ans;
int main()
{
   scanf("%d",&n);
   while(n--)
   { 
       scanf("%d",&a);
       if(a==0)ans+=2;
       else if(a==1)ans+=1;
       else if(a==2)ans+=0.5;
       else if(a==4)ans+=0.25;
       else if(a==8)ans+=0.125;
       else if(a==16)ans+=0.0625;
   }
   printf("%.6lf",ans);
   return 0; 
}
