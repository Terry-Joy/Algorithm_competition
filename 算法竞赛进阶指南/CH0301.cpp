#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int>chosen;
void calc(int x)
{
	if(x==n+1)
	{
		for(int i=0;i<chosen.size();++i)
			printf("%d ",chosen[i]);
		putchar('\n');
		return ;
	}
	calc(x+1);//不选 
	chosen.push_back(x);//选 
	calc(x+1);//求解子问题 
	chosen.pop_back(); //回溯时还原现场 
}
int main()
{
	scanf("%d",&n);
	calc(1);
}
