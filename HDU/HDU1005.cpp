#include<cstdio>
#include<iostream> 
using namespace std;
const int max_1 = 1e7;
int fn[50]={0,1,1};

int main()
{
	int a, b, n;
	while (scanf("%d%d%d", &a, &b, &n) != EOF && (a + b + n) != 0)
	{
		for (int i = 3; i <= 48; ++i)
			fn[i] = (a * fn[i - 1] % 7 + b * fn[i - 2] % 7) % 7;
		if(n%48==0)
		printf("%d\n",fn[48]);
		else printf("%d\n",fn[n%48]);
		
	}
	return 0;
}
