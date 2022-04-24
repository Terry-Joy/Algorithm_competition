#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   string s;
   cin>>s;
   int len=s.length(),ans=0,mx=0,pos=-1;
   for(int i=0;i<len;++i)
       if(s[i]=='['){ 
            pos=i;break;
       }
   int pos2=-1;
   for(int i=len-1;i>=0;--i){ 
        if(s[i]==']')
        {
           pos2=i;break; 
        }
   }
   int pos3=-1;
   if(pos2==-1||pos==-1){ 
      cout<<-1<<endl;return 0;
   }
   for(int i=pos;i<=pos2;++i)
   {
      if(s[i]==':'){ pos3=i;break;} 
   }
   int pos4=-1;
   for(int i=pos2;i>=pos;--i)
       if(s[i]==':'){ 
            pos4=i;break;
       }
   if(pos3<pos4&&(pos!=-1)&&(pos2!=-1)&&(pos3!=-1)&&pos4!=-1){ 
        ans+=4;
        for(int i=pos3;i<=pos4;++i)
            if(s[i]=='|')ans++;
        cout<<ans<<endl;
   }
   else puts("-1");
   return 0; 
}
