#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 0x3f3f3f3f
#define min(a,b) a>b?b:a 
double G[311][311];
int subx[311],suby[311],stop_number,hx,hy,sx,sy;
double time[311];
void dijkstra()
{
	int mark[311] = {0};
	int i,j,pos;
	double min;
	for(i = 1; i <= stop_number; i++)
	{
		time[i] = G[0][i];
	} 
 
	mark[0] = 1;
	
	for(i = 1; i <= stop_number + 1; i++)
	{
		min = MAX;
		for(j = 1; j <= stop_number; j++)
		{
			if(!mark[j] && time[j] < min)
			{
				pos = j;
				min = time[j];
			}
		}
		
		mark[pos] = 1;
		
		if(min == MAX)
			break;
		
		for(j = 1; j <= stop_number; j++)
		{
			if(!mark[j] && time[j] > time[pos] + G[pos][j])
			{
				time[j] = time[pos] + G[pos][j];
			}
		}
	}
}
 
int main()
{
	int k = 1, i, x, y, j;
	double len;
	memset(subx,-1,sizeof(subx));
	memset(suby,-1,sizeof(suby));
	for(i=0;i<311;i++)
		for(j=0;j<311;j++)
			G[i][j]=MAX;
	scanf("%d%d%d%d", &hx, &hy, &sx, &sy); 
	i = 1;
	while(scanf("%d%d",&x,&y)!=EOF)//读入地铁 
	{
		subx[i] = x;
		suby[i++] = y;
		while(scanf("%d%d",&x,&y) == 2)
		{
			if(x == -1 && y == -1)
				break;			
			len = sqrt( (x - subx[i - 1]) * (x - subx[i - 1]) + (y - suby[i - 1]) * (y - suby[i - 1]) );
			G[i - 1][i] = G[i][i - 1] = min(G[i - 1][i], len * 3.0 / 2000.0);
			
			subx[i] = x;
			suby[i] = y;
			i++;
		}
	}
	stop_number = i;
	for(i = 1; i < stop_number - 1; i++)//地铁线路数目
	{
		for(j = 1; j < stop_number; j++)//某条线路的某个站点 
		{
			len = sqrt( (subx[i] - subx[j]) * (subx[i] - subx[j]) + (suby[i] - suby[j]) * (suby[i] - suby[j]) );
			G[i][j] = G[j][i] = min(G[i][j], len * 3.0 / 500.0);
		}
	} 
	for(i = 1;i < stop_number; i++)
	{
		G[0][i] = G[i][0] = sqrt( (hx - subx[i]) * (hx - subx[i]) + (hy - suby[i]) * (hy - suby[i]) ) * 3.0 / 500.0;
	}
	for(i = 1;i < stop_number; i++)
	{
		G[stop_number][i] = G[i][stop_number] = sqrt( (sx - subx[i]) * (sx - subx[i]) + (sy - suby[i]) * (sy - suby[i]) ) * 3.0 / 500.0;
	}
	G[0][stop_number] = G[stop_number][0] = sqrt( (hx - sx) * (hx - sx) + (hy - sy) * (hy - sy) ) * 3.0 / 500.0;
	dijkstra(); 
	printf("%d\n",(int)(time[stop_number] + 0.5) );
}

