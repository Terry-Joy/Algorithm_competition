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
	calc(x+1);//��ѡ 
	chosen.push_back(x);//ѡ 
	calc(x+1);//��������� 
	chosen.pop_back(); //����ʱ��ԭ�ֳ� 
}
int main()
{
	scanf("%d",&n);
	calc(1);
}
