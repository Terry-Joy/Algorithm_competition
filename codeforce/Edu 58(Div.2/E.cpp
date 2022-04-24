#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char s[5];
int main()
{
   int n,l,r,x=0,y=0;
   scanf("%d",&n);
   for(int i=1;i<=n;++i){ 
       scanf("%s%d%d",s,&l,&r);
       if(l>r)swap(l,r);
       if(s[0]=='+'){ 
         x=max(x,l);
         y=max(y,r);
       }
       else{ 
          if(x<=l&&y<=r)
              puts("YES");
          else puts("NO");
       } 
   }
   return 0; 
}
