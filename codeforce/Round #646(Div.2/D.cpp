#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
const int N = 1005;
vector<int> v[N];
int res[N];
 
int query(int x)
{
	printf("? ");
	printf("%d ", x);
	for (int i = 1; i <= x; ++i)
	{
		printf("%d ", i);
	}
	printf("\n");
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}
 
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= k; ++i)
		{
			v[i].clear();
			int sz;//集合的大小
			scanf("%d", &sz);
			int u;
			for (int j = 1; j <= sz; ++j)
			{
				scanf("%d", &u);
				v[i].push_back(u);
			}
		}
		int mx = query(n);
		int l = 1, r = n;
		int pos = 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (query(mid) == mx) 
				r = mid;
			else 
				l = mid + 1;
		}
		pos = l;
		for (int i = 1; i <= k; ++i)
		{
			bool flag = false;
			map<int, int> mp;
			for (int j = 0; j < v[i].size(); ++j)
			{
				if (v[i][j] == pos)
					flag = true;
				mp[v[i][j]] = 1;//这个位置是不行的
			}
			if (!flag)
				res[i] = mx;
			else
			{
				printf("? ");
				printf("%d ", n - v[i].size());
				for (int i = 1; i <= n; ++i)
				{
					if (mp[i]) continue;
					printf("%d ", i);
				}
				printf("\n");
				fflush(stdout);
				int p = 0;
				scanf("%d", &p);
				res[i] = p;
			}
		}
		printf("! ");
		for (int i = 1; i <= k; ++i)
			printf("%d ", res[i]);
		printf("\n");
		fflush(stdout);
		char s[20];
		scanf("%s", s);
	}
	return 0;
}
