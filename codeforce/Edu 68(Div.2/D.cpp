#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main()
{
   int t,n,k;
   cin>>t;
   while(t--)
   {
      cin>>n>>k;
      if(!n)puts("Bob");
      else
      {
         if(k%3==0)
            n%=(k+1);
         if(n==k||n%3==2||n%3==1)
            puts("Alice");
         else
            puts("Bob"); 
      } 
   }
   return 0; 
}
