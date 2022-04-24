#include<bits/stdc++.h>
using namespace std;
char s[305];
int main(){
   int q,n;
   scanf("%d",&q);
   while(q--){
      scanf("%d",&n);
      scanf("%s",s);
      if(n==2){
         if(s[0]>=s[1])puts("NO");
         else{
            puts("YES");
            puts("2");
            cout<<s[0]<<" "<<s+1<<"\n";
         }
      }else{
         puts("YES");
         puts("2");
         cout<<s[0]<<" "<<s+1<<"\n";
      }
   }
   return 0;
}