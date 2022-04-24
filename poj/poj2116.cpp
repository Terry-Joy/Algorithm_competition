#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
#define esp 1e-13
const int N=1e4+10,M=1e6+50000,inf=1e9+10,mod=1000000007;
string s1,s2,s3;
ll a[N];
void init()
{
    a[0]=1;
    a[1]=2;
    for(int i=2;i<=50;i++)
    a[i]=a[i-1]+a[i-2];
}
ll getnum(string aa)
{
    int x=aa.size();
    ll sum=0;
    for(int i=0;i<x;i++)
    if(aa[i]=='1')
    sum+=a[i];
    return sum;
}
void check(ll x,string &str)
{
    int i;
    for(i=50;i>=0;i--)
    if(x>=a[i])
    break;
    for(int t=i;t>=0;t--)
    if(x>=a[t])
    {
        str+='1';
        x-=a[t];
    }
    else
    str+='0';
    if(i<0)
    str+='0';
}
int main()
{
    int x,y,i,z,t;
    init();
    while(cin>>s1>>s2)
    {

        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        ll num1=getnum(s1);
        ll num2=getnum(s2);
        ll num3=num1+num2;
        s1.clear();
        s2.clear();
        s3.clear();
        check(num1,s1);
        check(num2,s2);
        check(num3,s3);
        printf("  ");for(i=0;i<s3.size()-s1.size();i++)printf(" ");cout<<s1<<endl;
        printf("+ ");for(i=0;i<s3.size()-s2.size();i++)printf(" ");cout<<s2<<endl;
        printf("  ");for(i=0;i<s3.size();i++)printf("-");cout<<endl;
        printf("  ");cout<<s3<<endl;
        cout<<endl;
    }
    return 0;
}
