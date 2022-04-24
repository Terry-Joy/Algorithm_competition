#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
    char s[2010];
	cin>>s;
	int len=strlen(s);
	int len1=0,len2=0;
	for(int i=0;i<len;++i)
	{
		if(s[i]=='1')len1++;
		else len2++;
	} 
	if(len1==len2)
	{
		if(s[0]=='0')
		{
			cout<<1;
			for(int i=1;i<=len-1;++i)
			{
				if(s[i]=='1')
					cout<<0;
				else
					cout<<s[i];
			}
		}
		else
		{
			cout<<0;
			for(int i=1;i<=len-1;++i)
			{
				if(s[i]=='0')
					cout<<1;
				else
					cout<<s[i];
			}
		}
	}
	else
	{
		if(len1>len2)
		{
			for(int i=0;i<len;++i)
				if(s[i]=='1')
					cout<<0;
				else
					cout<<s[i];
		}
		else{
				for(int i=0;i<len;++i)
				if(s[i]=='0')
					cout<<1;
				else
					cout<<s[i];
			}
	}
    return 0;
}
