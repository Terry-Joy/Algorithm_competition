#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;

char s[110];
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       scanf("%d",&n);
       scanf("%s",s+1);
       int flag=0;
       for(int i=1;i<=n;++i)
        {
            if(s[i]=='8')
            {
               flag=i;
               break; 
            }
        }
       if(n<11)
       {
          puts("NO");
          continue; 
       } 
       else if(n==11)
       {
          if(s[1]=='8')
          {
             puts("YES");
             continue; 
          } 
          else { 
              puts("NO");
              continue;
          }
       }
       else if(n>11)
       {
          if(!flag)
          {
             puts("NO");
             continue; 
          } 
          else
          {
             if(n-flag+1<11)
             {   
                 puts("NO"); 
                 continue;
             }
             else
             {
                puts("YES");
                continue; 
             }
          }
       }
    }
    return 0;
}
