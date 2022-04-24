#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = N * 4;

int n, m, x, y, q, z;

struct Edge {
	int x, y, z;
	void input() {
		scanf("%d%d%d", &x, &y, &z);
	}
}E[M];

int fa[N], vis[M], fir[N], ne[M], to[M], C[M], cnt = 1, Tr[N], D[N];

void add(int x, int y, int z) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
	C[cnt] = z;
}

void link(int x, int y, int z) {
	add(x, y, z);
	add(y, x, z);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int getf(int x) {
	return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

void dfs(int x, int f) {
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		Tr[V] = Tr[x] ^ C[i];
		dfs(V, x);
	}
}

void add(int x) {
	for(int i = 30; i >= 0; -- i) {
		if((x >> i) & 1) {
			if(D[i]) x ^= D[i];
			else {
				D[i] = x; return;
			}
		}
	}
}

int Q(int x) {
	for(int i= 30; i >= 0; -- i) {
		int now = ((x >> i) & 1);
		if(now) continue;
		else x = x ^ D[i];
	}
	return x;
}

int S[31][N], Cc[31];

int Q(int l, int r) {
	int ans = 0, cnt = r - l + 1;
	long long All = 1LL * cnt * (cnt - 1) / 2;
	for(int i = 30; i >= 0; -- i) {
		Cc[i] = 1LL * (S[i][r] - S[i][l - 1]) * (cnt - S[i][r] + S[i][l - 1]);
		if(D[i]) {
			ans ^= (1LL * (cnt - 1) * cnt / 2) % 2 * (1 << i);
		} else {
			ans ^= (Cc[i] & 1) * (1 << i);
			for(int j = i + 1; j <= 30; ++ j) {
				if((D[j] >> i) & 1) {
					ans ^= ((All - Cc[j]) & 1) * (1 << i);
				}
			}
		}
	}
	return ans;
}

int main() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	for(int i = 1; i <= m; ++ i) E[i].input();
	for(int i = 1; i <= m; ++ i) {
		if(getf(E[i].x) == getf(E[i].y)) continue;
		link(E[i].x, E[i].y, E[i].z);
		fa[getf(E[i].x)] = getf(E[i].y);
		vis[i] = 1;
	}
	dfs(1, 0);
	for(int i = 1; i <= m; ++ i) {
		if(!vis[i]) add(Tr[E[i].x] ^ Tr[E[i].y] ^ E[i].z);
	}
	for(int j = 0; j <= 30; ++ j)
	for(int i = 1; i <= n; ++ i) {
		S[j][i] = S[j][i - 1] + ((Tr[i] >> j) & 1);
	}

	for(int j = 30; j >= 0; -- j) {
		for(int i = j - 1; i >= 0; -- i) {
			if((D[j] >> i) & 1) D[j] ^= D[i];
		}
	}

	for(; q --;) {
		scanf("%d%d", &x, &y);
		printf("%d\n", Q(x, y));
	}
}