#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string s="lovely";
string s1="LOVELY";
int main()
{
   string h;
   cin>>h; 
   bool flag=1;
   for(int i=0;i<6;++i)
      if((h[i]!=s[i]&&h[i]!=s1[i])) 
        flag=0;
   if(flag)puts("lovely");
   else puts("ugly");
   return 0; 
}
