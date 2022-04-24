
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		int n, i, max1, max2, a;
		scanf("%d", &n);
		max1 = max2 = 1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a);
			if (max1 < a)
			{
				max2 = max1;
				max1 = a;
			}
			else if (max2 < a)
			{
				max2 = a;
			}
		}
		printf("%d\n", max2 - 1 < n - 2 ? max2 - 1 : n - 2);
	}
	return 0;
}
 

