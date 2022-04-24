#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
string s;
int main()
{
   int n;
   cin>>n;
   cin>>s;
   int ans=0;
   for(int j=26;j>=1;--j)
       for(int i=0;i<s.size();++i)
       {
          if(s[i]!='a'+j)
             continue;
          if(i>0)
          {
             if(s[i-1]=='a'+j-1)
             {
                s.erase(i,1);
                ans++; 
             } 
          } 
          if(i<s.size()-1)
          {
             if(s[i+1]=='a'+j-1)
             {
                s.erase(i,1);
                ans++; 
             } 
          }
       }
   printf("%d\n",ans);
   return 0; 
}
