#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=0x7FFFFFFF;
///Map存放棋盘，turn存放每个棋子（地板）翻转的状态（翻转几次）
///ans存放最后要输出的每个地板翻转的次数，cnt记录翻转地板的总次数
///res存放最小的翻转次数,M代表行数，N代表列数
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
	return temp%2;//用周围4个方块和其本身的数字判断自己颜色是否改变 
}
void dfs()
{
	for(int i=1;i<M;++i)
	{
		for(int j=0;j<N;++j)
		{
			if(getcolor(i-1,j))turn[i][j]=1,cnt++;//turn表示是否要点击 
			if(cnt>res)return;					//剪枝 
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
