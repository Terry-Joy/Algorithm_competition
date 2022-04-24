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
char a[1010],b[1010];
int main()
{
   int len=0;
   scanf("%s",a+1);
   len=strlen(a+1);
   for(int i=1;i<=len;++i)
       b[i]=a[i];
   sort(b+1,b+1+len);
   for(int i=1;i<=len;++i)
   {
      if(a[i]!=b[i])
      {
         for(int j=i+1;j<=len;++j)
         {
            if(b[j]==a[i])
            { 
               if(b[i]>b[j])printf("%d %d\n",i,j);
               else printf("%d %d\n",j,i);
               swap(b[i],b[j]);
               break;
            }
         } 
      } 
   }
   return 0; 
}
