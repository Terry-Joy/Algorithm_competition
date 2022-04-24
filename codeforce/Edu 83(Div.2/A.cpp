#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{ 
   int t;
   scanf("%d",&t);
   for(int i=1;i<=t;++i){ 
    int a,b;
    scanf("%d%d",&a,&b);
    if(a%b==0)
        puts("YES");
    else puts("NO");
   }
   return 0; 
}
