#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
char s[200];
int main()
{
   cin>>s;
   int lenc=0,lens=0;
   int len=strlen(s);
   for(int i=0;i<len;++i)
   {
        if(s[i]=='C')
        {
           lens=0;
           lenc++;
           if(lenc==3)
             {  
               cout<<"P";
               lenc=0;
             }
           else
               cout<<"B";
        }
        else
        {
           lenc=0;
           lens++;
           if(lens==3)
           {
              cout<<"T";
              lens=0; 
           }
           else 
              cout<<"D";
        }
   }
   return 0; 
}
