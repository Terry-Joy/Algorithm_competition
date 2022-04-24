#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
   int n,a,p;
   scanf("%d%d%d",&n,&a,&p);
   printf("%.9lf",(0.02*p-1)*a+n);
   return 0; 
}
