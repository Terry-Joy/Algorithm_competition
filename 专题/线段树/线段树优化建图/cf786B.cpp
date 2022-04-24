#include<bits/stdc++.h>
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
#define ls p << 1
#define rs p << 1 | 1
#define eb emplace_back
using namespace std;
int n, q, Out[maxn<<2], In[maxn<<2], tot;//tot = n
vector<pair<int, int>> edge[maxn * 8 + 5];
void build(int p, int l, int r) { 
    if (l == r) { 
        Out[p] = In[p] = l;
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    Out[p] = ++tot;
    In[p] = ++tot;
    edge[Out[ls]].eb(0, Out[p]);
    edge[Out[rs]].eb(0, Out[p]);
    edge[In[p]].eb(0, In[ls]);
    edge[In[p]].eb(0, In[rs]);
}
void updateIn(int p, int l, int r, int L, int R, int from, int cost) { 
    if (L <= l && r <= R) { 
        edge[from].eb(cost, In[p]);
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        updateIn(lson, L, R, from, cost);
    if (R > mid) 
        updateIn(rson, L, R, from, cost);
}
void updateOut(int p, int l, int r, int L, int R, int from, int cost) { 
    if (L <= l && r <= R) { 
        edge[Out[p]].eb(cost, from);
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        updateOut(lson, L, R, from, cost);
    if (R > mid)
        updateOut(rson, L, R, from, cost);
}
int main(){ 
    
    return 0;
}
