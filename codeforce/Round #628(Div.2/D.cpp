#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int main()
{
    ll u,v,x,y;
    cin>>u>>v;
    if(u>v)
    {  
        cout<<"-1"<<endl;
        return 0;
    }
    if(u==0&&v==0)
    {  
        cout<<"0"<<endl;
        return 0;
    }
    if(u==v)
    {  
        cout<<1<<"\n"<<u<<endl;
        return 0;
    }
    x=(v-u)/2;
    if((v-u)&1)
    { 
        cout<<-1<<endl;
        return 0;
    }
    if((x&u)==0)
    {
       cout<<2<<"\n"<<u+x<<" "<<x;
       return 0; 
    }
    cout<<3<<"\n";
    cout<<u<<" "<<x<<" "<<x<<endl;
    return 0; 
}
