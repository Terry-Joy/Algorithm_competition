#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
int c[30][30],ans,cnt;
int k,s;
int a[]={ 0,2,3,5,7,11,13,17,19,23};
void dfs(int pos,int sum,int li)
{
    sum=a[pos]*sum;
    if(s/sum<k)return;
    if(li&1)
        ans+=(c[s/sum][k]);
    else
        ans-=(c[s/sum][k]);
    if(ans>10000)return;
    for(int i=pos+1;i<=cnt;++i)
        dfs(i,sum,li+1);
}
int main()
{
   c[0][0]=1;
   for(int i=1;i<=26;++i)
   {
      c[i][0]=c[i][i]=1;
      for(int j=1;j<i;++j)	
         c[i][j]=c[i-1][j-1]+c[i-1][j]; 
   } 
   scanf("%d%d",&k,&s);
   for(int i=9;i>=1;--i)
   {
       if(s/a[i]>=k){ 
            cnt=i;
            break;
       }
   } 
   for(int i=1;i<=cnt;++i)
       dfs(i,1,1);
   if(ans>10000)
       puts("10000");
   else 
       printf("%d\n",ans);
   return 0; 
}
