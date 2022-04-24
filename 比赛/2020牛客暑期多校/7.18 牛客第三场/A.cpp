#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e6+5;
int t,n;
char s[maxn];
int main()
{
   scanf("%d",&t);
   while(t--)
   {
       int ans=0,cnt=0,n;
       scanf("%d%s",&n,s);
       for(int i=0;i<n;++i){ 
            if(s[i]=='0'){ 
                if(cnt)cnt--,ans++;
            }
            else if(s[i]=='1')cnt++;
            else ans++;
       }
       printf("%d\n",ans+cnt/2);
   } 
   return 0; 
}
