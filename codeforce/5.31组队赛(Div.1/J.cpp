#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int>fac;
const int maxn=1e5+10;
char s[maxn];
bool vis[maxn];
int k,ans=0;
bool is(int i,int j)
{
    int pos=i;
    while(1)
    {
       pos=(pos+j)%k;
       if(s[pos]=='P')return false;
       if(pos==i)return true; 
    }

}
int main()
{
   scanf("%s",s);
   k=strlen(s);
   for(int i=1;i<k;++i)
      if(k%i==0)fac.push_back(i);
   //for(auto&v:fac)
   //cout<<v<<" ";
   for(int i=0;i<fac.size();++i)
   {
      for(int j=0;j<fac[i];++j)
      {
         if(s[j]=='R'&&is(j,fac[i]))
         {
            for(int f=1;f*fac[i]<k;++f)
            {
               if(!vis[f*fac[i]])
               {
                  vis[f*fac[i]]=1;
                  ans++; 
               } 
            } 
            break;
         } 
      } 
   }
   printf("%d\n",ans);
   return 0; 
}
