#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
#include<map>
#define ll long long 
using namespace std;
const int N=70;
struct Node
{
   int x,y,z;
   string name; 
}node[N];
double d[N][N];
map<string,int>mp;
int main()
{
    int t,f=1;
    scanf("%d",&t);
    while(t--)
    {
       int num=0;
       int a,b;
       scanf("%d",&a);
       for(int i=1;i<=a;++i)
       { 
          cin>>node[i].name>>node[i].x>>node[i].y>>node[i].z;
            mp[node[i].name]=++num;
        }
       scanf("%d",&b);
       for(int i=1;i<=a;++i)
           for(int j=1;j<=a;++j)
               d[i][j]=d[j][i]=sqrt((double)(node[i].x-node[j].x)*(node[i].x-node[j].x)+(double)(node[i].y-node[j].y)*(node[i].y-node[j].y)+double(node[i].z-node[j].z)*(node[i].z-node[j].z));
       for(int i=1;i<=b;++i)
       {
        string s1,s2;
          cin>>s1>>s2;
          int k1=mp[s1],k2=mp[s2];
          d[k1][k2]=0; 
       }
       for(int k=1;k<=a;++k)
        for(int i=1;i<=a;++i)
             for(int j=1;j<=a;++j)
                   d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
       printf("Case %d:\n",f++);
       int q;
       scanf("%d",&q);
       for(int i=1;i<=q;++i)
       {
       string s1,s2;
          cin>>s1>>s2;
          int k1=mp[s1],k2=mp[s2];
           printf("The distance from %s to %s is %.0f parsecs.\n",s1.c_str(),s2.c_str(),d[k1][k2] );
   		 }
	}
}
