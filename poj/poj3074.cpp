#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s[100],str[10][10];
int r[9],c[9],grid[9],cnt[512],num[512];

inline int g(int x,int y)
{
   return 3*(x/3)+y/3; 
}
void change(int x,int y,int z)
{
   r[x]^=(1<<z);
   c[y]^=(1<<z);
   grid[g(x,y)]^=(1<<z); 
}

bool dfs(int now)
{
   if(now==0)return 1;
   int temp=10,x,y;
   for(int i=0;i<9;++i)
      for(int j=0;j<9;++j)
      {
         if(str[i][j]!='.')continue;
         int rest=r[i]&c[j]&grid[g(i,j)];
         if(!rest)return 0;
         if(cnt[rest]<temp)//每次找最少的
         {
            temp=cnt[rest];
            x=i;y=j; 
         } 
      } 
   int val=r[x]&c[y]&grid[g(x,y)];
   for(;val;val-=val&-val)
   {
      int k=num[val&-val];
      str[x][y]=k+'1';
      change(x,y,k);
      if(dfs(now-1))return 1;
      str[x][y]='.';
      change(x,y,k);  
   }
   return 0;
}

int main()
{
   for(int i=0;i<1<<9;++i)
      for(int j=i;j;j-=j&-j)
        cnt[i]++;               //i有多少个1
   for(int i=0;i<9;++i)
       num[1<<i]=i;             //log2x
   while(~scanf("%s",s)&&s[0]!='e')
   {
      for(int i=0;i<9;++i)
         for(int j=0;j<9;++j)
            str[i][j]=s[i*9+j];
      for(int i=0;i<9;++i)
         r[i]=c[i]=grid[i]=(1<<9)-1; 
      int tot=0;
      for(int i=0;i<9;++i)
          for(int j=0;j<9;++j)
          {
             if(str[i][j]!='.')change(i,j,str[i][j]-'1');
             else tot++; 
          }
      dfs(tot);
      for(int i=0;i<9;++i)
          for(int j=0;j<9;++j)
              s[i*9+j]=str[i][j];
      puts(s);
   }
   return 0; 
}
