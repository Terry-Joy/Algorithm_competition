#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;
int dp[17][1<<15],t,n,cost[17][17];//cost[i][j]表示在j前面接上i
string str[20],ans;
const int INF=0x3f3f3f3f;
void init()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(i!=j&&str[i].find(str[j])!=string::npos)
                str[j]=str[i];
    stable_sort(str,str+n);
    n=unique(str,str+n)-str;//去重
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            cost[i][j]=cost[j][i]=0;
    for(int i=0;i<n;++i)                                //预处理接在头上面的价值
        for(int j=0;j<n;++j) 
        {
            if(i==j)continue;
            int len=min(str[i].length(),str[j].length());
            for(int k=0;k<=len;++k)
                if(str[i].substr(str[i].length()-k)==str[j].substr(0,k))
                    cost[i][j]=str[i].length()-k;
        }
    int f=1<<n;
    for(int i=0;i<=n;++i)
        for(int j=0;j<f;++j)
            dp[i][j]=INF; 
    for(int i=0;i<n;++i)
        dp[i][1<<i]=str[i].length();
}
void dfs(int id,int s)//逐个拼凑
{
   if(s==0)return;
   string tmp;int nid=-1;
   for(int i=0;i<n;++i) 
   {
      if(id==i)continue;
      if(s&(1<<i)) 
      {
         if(dp[id][s]==dp[i][s^(1<<id)]+cost[id][i])//满足最短长度
         {
            string t=str[i].substr(str[id].length()-cost[id][i]);
            if(nid==-1||tmp>t)//满足最小字典序
            {
               nid=i;
               tmp=t; 
            }
         }   
      }
   }
   ans+=tmp;
   dfs(nid,s^(1<<id));
}
int main()
{
    scanf("%d",&t);
    int e=0;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            cin>>str[i];
        init();     
        if(n>1)
        { 
            int f=(1<<n)-1;
            for(int s=0;s<=f;++s)
                for(int i=0;i<n;++i)
                {
                    if(s&(1<<i)) 
                    {
                        if(dp[i][s]==INF)continue;
                        for(int j=0;j<n;++j)
                            if(!(s&(1<<j)))
                                dp[j][s|(1<<j)]=min(dp[j][s|(1<<j)],dp[i][s]+cost[j][i]);
                    }
                } 
            int id=0;
            for(int i=1;i<n;++i)
                if(dp[id][f]>dp[i][f])
                    id=i;
            ans=str[id];
            dfs(id,f);
        }
        else ans=str[0];
        printf("Scenario #%d:\n",++e);
        cout<<ans<<"\n";
        puts("");
    } 
    return 0; 
}
