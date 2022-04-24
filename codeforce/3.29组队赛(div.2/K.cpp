#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<vector>
#define ll long long
using namespace std;
int main()
{
   vector<int>s;
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      s.clear();
      string a,b;
      cin>>a>>b;
      for(int i=0;i<n;++i)
          if(a[i]!=b[i])
              s.push_back(i);
      bool flag=1;
      int len=s.size();
      for(int i=0;i<len;++i)
      {
         if(b[s[i]]!=a[s[(i+1)%len]])
         {
            flag=0;
            break;
         } 
      }
      if(flag)
          puts("YES");
      else 
          puts("NO");
   }
   return 0; 
}

