#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#define ll long long 
using namespace std;
vector<int>v[27];
int a[27];
int main()
{
    int n,m,q;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
       v[s[i]-'a'].push_back(i); 
    }
    cin>>q;
    while(q--)
    {
       memset(a,0,sizeof(a));
       string x;
       cin>>x;
       int ans=0;
       for(int i=0;i<x.size();++i)
       {
          ans=max(ans,v[x[i]-'a'][a[x[i]-'a']]+1);
          a[x[i]-'a']++;
       } 
       cout<<ans<<"\n";
    }
    return 0;
}
