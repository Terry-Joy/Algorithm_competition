#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
struct Node{int a[30];int flag;}tree[500000*26];
vector<string>q;
int tot=1;
void insert(string str)
{
	int now=1,len=str.size();
	for(int i=0;i<len;++i)
	{
		if(tree[now].a[str[i]-'a']==0) 
			tree[now].a[str[i]-'a']=++tot;
		now=tree[now].a[str[i]-'a'];	
	} 
	tree[now].flag=1;
}
bool find(string str)
{
	int now=1,len=str.size();
	for(int i=0;i<len;++i)
	{
		if(!tree[now].a[str[i]-'a'])return false;
		now=tree[now].a[str[i]-'a'];
	}
	if(tree[now].flag)return true;
}
int main()
{
	string str,str1,str2;
	while(cin>>str)
	{
		q.push_back(str);
		insert(str);
	}
	for(int i=0;i<q.size();++i)
	{
		str=q[i];
		int len=str.size();
		for(int j=0;j<len;++j)
		{
			str1=str.substr(0,j);
			str2=str.substr(j,len-j);
			if(find(str1)&&find(str2))
			{
				cout<<str<<"\n";
				break;
			}
		}
	}
	return 0;
}

