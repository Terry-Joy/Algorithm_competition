#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=510;
struct Node
{
   int a,b; 
   bool operator<(const Node&x)
   {
       return a<x.a;
   }
}node[maxn];
vector<int>mp;
int a1[maxn],b1[maxn];
int main()
{
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       mp.clear();
       for(int i=1;i<=n;++i)
            scanf("%d",&node[i].a),mp.push_back(node[i].a);
       int s=0;
       for(int i=1;i<=n;++i)
            scanf("%d",&node[i].b),s+=node[i].b;
       sort(mp.begin(),mp.end());
       bool flag=1;
       for(int i=0;i<mp.size();++i)
       {
           if(node[i+1].a!=mp[i])
           {
              flag=0;
              break; 
           } 
       }
       if(flag) 
        {
           puts("Yes");
           continue; 
        }
       else
       { 
            if(s==n||s==0)
                puts("No");
            else
                puts("Yes");
       }
   }
   return 0; 
}
