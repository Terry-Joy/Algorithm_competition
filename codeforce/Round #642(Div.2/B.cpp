#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>

using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n,a;
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
      {
         scanf("%d",&a);  
         q.push(a);
      } 
      int ans=0,cnt=0,max_cnt=0;
         int x=q.top();
         q.pop();
         cnt++;
         if(cnt==x)
         { 
             ans++;
             cnt=0;
         }
         else 
             max_cnt=x;
         while(q.size())
         {
            int y=q.top();
            q.pop();
            if(y>max_cnt)max_cnt=y;
            cnt++;
            if(cnt==max_cnt)
            {
               ans++;
               cnt=0; 
            }
         }
         printf("%d\n",ans);
   }
   return 0; 
}
