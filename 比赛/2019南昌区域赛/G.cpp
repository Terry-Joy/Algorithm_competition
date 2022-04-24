#include <bits/stdc++.h>

using namespace std;

const int MOD = 998857459;

int num[3005];
int pos[3005], t;
int a[100005], sum[100005];
int len[100005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	num[1] = 1;
	for (int i = 2; i <= 2803; i++)
		num[i] = 1ll * num[i - 1] * i % MOD;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= 2803) a[i] = 0;
		else
			pos[++t] = i, a[i] = num[a[i]];
	}
	for (int i = 1; i <= n; i++)
		sum[i] = (sum[i - 1] + a[i]) % MOD;
	for (int i = 1; i <= t; i++) {
		for (int j = i; j <= t; j++) {
			int l = pos[i], r = pos[j], ll = pos[i - 1];
			len[r - l + 1] = max(len[r - l + 1], ((sum[r] - sum[ll]) % MOD + MOD) % MOD);
		}
	}
	for (int i = 1; i <= n; i++)
		len[i] = max(len[i], len[i - 1]);
	int k;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);
		if (len[n] < k)	{
			printf("-1\n");
			continue;
		}
		int l = 1, r = n, mid;
		while (l < r) {
			mid = l + r >> 1;
			if (len[mid] >= k)
				r = mid;
			else l = mid + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}