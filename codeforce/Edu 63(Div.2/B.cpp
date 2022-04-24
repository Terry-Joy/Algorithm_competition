#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e5+10;
char s[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   cin>>s;
   int cnt=0,ne=0;
   for(int i=0;i<n;++i)
   {
      if(s[i]-'0'==8)cnt++;
      else  ne++;
      if(cnt>(n-11)/2)break;
   }
   if(ne>(n-11)/2)
       puts("NO");
   else puts("YES");
   return 0; 
}
