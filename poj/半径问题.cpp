#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int candy[1010];
int main()
{
	int R,N;
	while(scanf("%d%d",&R,&N)!=EOF)
	{
		if(R==-1&&N==-1)
		break;
		for(int i=0;i<N;++i)
			scanf("%d",&candy[i]);
		sort(candy,candy+N);
		int i=0,sum=0,temp;
		while(i<N)
		{
			temp=candy[i++];
			while(i<N&&candy[i]-temp<=R)
			++i;
			int p=candy[i-1];
			while(i<N&&candy[i]-p<=R)
			++i;
			sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
