#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#define ll long long

using namespace std;

const int N=2010;
string s[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
int n,k,ans[N];
string a[N];
bool is[N][N],flag;

void dfs(int pos,int k)
{
   if(flag||k<0)return;//剪枝
   if(pos==n)           //枚举完了
   {
      if(k==0)
      {
         flag=1;
         for(int i=0;i<n;++i) 
             printf("%d",ans[i]);
         putchar('\n');
         return;
      }
      else return;
   } 
   if(is[pos][k])return;//记搜剪枝
   for(int i=9;i>=0;--i)
   {
      int q=0;
      bool state=false;
      for(int j=0;j<7;++j)
         if(a[pos][j]=='0'&&s[i][j]=='1')q++;
      else if(a[pos][j]=='1'&&s[i][j]=='0')
      {
         state=1;           //改不了
         break; 
      }
     if(state)continue; 
     ans[pos]=i;
     dfs(pos+1,k-q);
   }
   if(!flag)is[pos][k]=1;    
}

int main()
{
   flag=0;
   scanf("%d%d",&n,&k);
   for(int i=0;i<n;++i)
       cin>>a[i];
   dfs(0,k);
   if(!flag)puts("-1");
   return 0; 
}
