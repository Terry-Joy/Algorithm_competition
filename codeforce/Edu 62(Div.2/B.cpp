#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+10;
char s[maxn];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      scanf("%s",s);
      if(n==1)
      {
         puts("0");
         continue; 
      } 
       int nl=0,nr=n-1,x=0,y=0;
       while(s[nl]=='<')nl++,x++;
       while(s[nr]=='>')nr--,y++;
       int m=x<y?x:y;
       printf("%d\n",m);
   }
   return 0; 
}
