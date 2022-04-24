#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[27];
int main()
{
   int t,n;
   cin>>t;
   while(t--){ 
       string s;
       scanf("%d",&n);
       memset(mp,0,sizeof(mp));
       int ans=0;
       for(int i=1;i<=n;++i)
       {
          cin>>s;
          ans+=s.size();
          for(int i=0;i<s.size();++i)
          {
             mp[s[i]-'a']++;
          }
       }
       if(ans%n!=0)puts("NO");
       else{ 
          bool f=1;
          for(int i=0;i<26;++i)
          {
             if(mp[i]%n!=0){
                f=0;
                break; 
             } 
          }  
          if(f)puts("YES");
          else puts("NO");
       }
   }
   return 0; 
}
