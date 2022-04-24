#include<bits/stdc++.h>

using namespace std;
char s[25];
int a[25],n;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--){
      scanf("%s",s+1);
      scanf("%d",&n);  
      int len=strlen(s+1);
      for(int i=1;i<=len;++i)
          a[i]=s[i]-'0';  
      for(int i=2;i<=len;++i)
          a[i]+=a[i-1];
      if()  
   } 
   return 0; 
}
