#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=25,maxm=531442;
const ll INF=1000000000000ll;
int p[maxn],cnt[maxm][3],a[maxm][13],t,m,n,k;//cnt[i][j]表示i状态下0/1/2个数 a[i][j]表示i状态下第j位
ll fac[maxn],ans[maxn];
char s[maxn][maxn];
ll dp[maxn][maxm];
struct dashu{int n,a[1000];};
void output(const dashu& a)    
{
    if(a.n==0){printf("0\n");return;}
    for(int i=a.n-1;i>=0;i--)printf("%d",a.a[i]);
    printf("\n");
}
dashu change(ll x)
{
    dashu now;
    int len=0;
    if(x==0)now.a[len++]=0;
    while(x)now.a[len++]=x%10,x/=10;
    now.n=len;
    return now;
}
dashu mul(const dashu& a,const dashu& b)
{
    dashu c;
    memset(c.a,0,sizeof c.a);
    for(int i=0;i<a.n;i++)
        for(int j=0;j<b.n;j++)
            c.a[i+j]+=a.a[i]*b.a[j];
    for(int i=0;i<a.n+b.n;i++)
    {
        if(c.a[i]>=10)c.a[i+1]+=c.a[i]/10;
        c.a[i]%=10;
    }
    c.n=a.n+b.n;
    while(c.n>=0&&c.a[c.n]==0)c.n--;
    if(c.n<0)c.n=0;
    while(c.a[c.n]>0)c.n++;
    return c;
}
void init()
{
    p[0]=fac[0]=1;
    for(int i=1;i<=12;++i)
        p[i]=p[i-1]*3;
    for(int i=1;i<=20;++i)
        fac[i]=fac[i-1]*i;
    for(int i=0;i<p[12];++i)
    {
        int tmp=i;
       for(int j=0;j<12;++j) 
        {  
            a[i][j]=tmp%3; 
            cnt[i][tmp%3]++;
            tmp/=3;
        }
    }
}
int main()
{
   init(); 
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d%d%d",&m,&n,&k); 
       for(int i=0;i<m;++i)
          scanf("%s",s[i]+1); 
       for(int i=1;i<=n;++i)
           for(int j=0;j<p[m];++j)dp[i][j]=0;
       for(int i=1;i<=k;++i)
           ans[i]=0;
       dp[0][0]=1;
       for(int i=1;i<=n;++i)
       {
          for(int j=0;j<p[m];++j)  
          {
             int st=j;                   //状态 
             if(dp[i-1][j]==0)continue;
             if(cnt[j][1]>n-i+1)continue;//剩下的扎不完
             for(int f=0;f<m;++f)       //整列不扎
                 if(a[j][f]==0&&s[f][i]=='Q')
                    st+=p[f];
             dp[i][st]+=dp[i-1][j];
             for(int f=0;f<m;++f)
             {
                if(a[j][f]!=2&&s[f][i]=='Q') //选一个扎掉
                {
                   st=j+(2-a[j][f])*p[f];
                   dp[i][st]+=dp[i-1][j]; 
                }
             }
          }
       }
       for(int s=0;s<p[m];++s)
           if(dp[n][s]&&cnt[s][1]==0 )
               ans[cnt[s][2]]+=dp[n][s];
       //for(int i=1;i<=k;++i)
       //cout<<ans[i]<<">>>>"<<endl;
       /*for(int i=1;i<=k;++i)
           printf("%lld\n",ans[i]*fac[i]);*/
      for(int i=1;i<=k;++i)
      {
         dashu x1=change(ans[i]);
         dashu x2=change(fac[i]);
         output(mul(x1,x2)); 
      } 
   }
   return 0; 
}
