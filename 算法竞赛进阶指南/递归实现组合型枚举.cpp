#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
vector<int>chosen;
void calc(int x)
{
	if(chosen.size()>m||chosen.size()+n-x+1<m)
	return;
	if(x==n+1)
	{
		for(int i=0;i<chosen.size();++i)
			printf("%d ",chosen[i]);
		putchar('\n');
		return ;
	}
	chosen.push_back(x);//ѡ 
	calc(x+1);//��������� 
	chosen.pop_back(); //����ʱ��ԭ�ֳ�
	calc(x+1); 
}
int main()
{
	scanf("%d%d",&n,&m);
	calc(1);
}
