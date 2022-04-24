#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() 
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int l,r,d;
      scanf("%d%d%d",&l,&r,&d);
      if(l>d)
         cout<<d<<endl;
      else
         cout<<((r/d)+1)*d<<endl; 
   } 
   return 0; 
}
