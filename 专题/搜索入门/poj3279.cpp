#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=0x7FFFFFFF;
///Map������̣�turn���ÿ�����ӣ��ذ壩��ת��״̬����ת���Σ�
///ans������Ҫ�����ÿ���ذ巭ת�Ĵ�����cnt��¼��ת�ذ���ܴ���
///res�����С�ķ�ת����,M����������N��������
int map[17][17],turn[17][17],ans[17][17],cnt,res,M,N;
int dir[5][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};
int getcolor(int x,int y)
{
	int temp=map[x][y];
	for(int i=0;i<5;++i)
	{
		int xi=x+dir[i][0];
		int yi=y+dir[i][1];
		if(xi>=0&&xi<M&&yi>=0&&yi<N)temp+=turn[xi][yi];
	}
	return temp%2;//����Χ4��������䱾��������ж��Լ���ɫ�Ƿ�ı� 
}
void dfs()
{
	for(int i=1;i<M;++i)
	{
		for(int j=0;j<N;++j)
		{
			if(getcolor(i-1,j))turn[i][j]=1,cnt++;//turn��ʾ�Ƿ�Ҫ��� 
			if(cnt>res)return;					//��֦ 
		}
	}
	for(int j=0;j<N;++j)
		if(getcolor(M-1,j))return;
	if(cnt<res)memcpy(ans,turn,sizeof(turn)),res=cnt;
}
int main()
{
	while(~scanf("%d%d",&M,&N))
	{
		res=maxn;
		for(int i=0;i<M;++i)
			for(int j=0;j<N;++j)
				scanf("%d",&map[i][j]);
		for(int i=0;i<(1<<N);++i)
		{
			cnt=0;
			memset(turn,0,sizeof(turn));	
			for(int j=0;j<N;++j)
			{
				turn[0][N-j-1]=i>>j&1;
				if(turn[0][N-j-1])cnt++;
			}
			dfs();
		}
		if(res==maxn)printf("IMPOSSIBLE\n");
		else
		{
			for(int i=0;i<M;++i)
			{
				for(int j=0;j<N;++j)
				{
					if(j>0)printf(" ");
					printf("%d",ans[i][j]);
				} 
				putchar('\n'); 
			}
		}	
	}
	return 0;
} 
