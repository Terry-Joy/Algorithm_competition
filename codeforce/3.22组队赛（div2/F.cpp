#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
#define ll long long 
int a[10010];
using namespace std;
int main()
{
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       int mid=0,lt=0,rt=0,ls=0,rs=0;
       for(int i=1;i<=n;++i)
       {
          scanf("%d",&a[i]);
          if(a[i]==1)
            mid=i;
       }
       if(n==1)
       {
          puts("Alice");
          continue; 
       }
       int i;
       for(i=mid-1;i>=1;--i)
       {
          if(a[i]>a[i+1])
             lt++;
          else break; 
       }
        while(i>0&&a[i]<a[i+1])
        {
           ls++;
           i--; 
        }
        for(i=mid+1;i<=n;++i)
        {
           if(a[i]>a[i-1])
              rt++;
           else break; 
        }
        while(i<=n&&a[i]<a[i-1])
        {
           rs++;i++; 
        } 
        if(lt==0)
        {
            if(rt==1)
            {
               if(((n-2-rs)&1)==0)puts("Bob");
               else puts("Alice"); 
            }
            else 
                if(((n-1)&1)==0)puts("Alice");
                else puts("Bob");
        }
        else if(rt==0)
        {
           if(lt==1)
           {
              if(((n-2-ls)&1)==0)puts("Bob");
              else puts("Alice"); 
           } 
           else if(((n-1)&1)==0)puts("Alice");
           else puts("Bob");
        }
        else if(lt==1&&rt==1)
        {
           if(((n-lt-ls)&1)==0)puts("Alice");
           else if(((n-rt-rs)&1)==0)puts("Alice");
           else puts("Bob"); 
        }
        else { 
            if(n&1)puts("Alice");
            else puts("Bob");
        }
   }
   return 0;
} 
