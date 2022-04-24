#include <bits/stdc++.h>
#define ME(x , y) memset(x , y , sizeof(x))
#define SF(n) scanf("%d" , &n)
#define rep(i , n) for(int i = 0 ; i < n ; i ++)
#define INF  0x3f3f3f3f
#define mod 1000000007
#define PI acos(-1)
using namespace std;
typedef unsigned long long ll ;
int tree[32*1009][2] , vis[32*1009] , num[32*1009];//num记录结点出现次数用于更新 
int a[1009];
int tol ;
 
void insert(int x )
{
    int u = 0 ;
    for(int i = 31 ; i >= 0 ; i--)
    {
        int p = (x >> i)&1;
        if(!tree[u][p]) tree[u][p] = ++ tol ;
        u = tree[u][p];
        num[u]++;
    }
    vis[u] = x ;								//记录答案 
}
 
void update(int x , int add)
{
    int u = 0 ;
    for(int i = 31 ; i >= 0 ; i--)
    {
        int p = (x >> i) & 1 ;					//取出每一位 
        u = tree[u][p];
        num[u] += add;
    }
}
 
int research(int x)
{
    int u = 0 ;
    for(int i = 31  ; i >= 0 ; i--)
    {
        int p = (x >> i) & 1 ;
        if(tree[u][p^1] && num[tree[u][p^1]]) u = tree[u][p^1];
        else u = tree[u][p];
    }
    return x ^ vis[u];							//直接返回答案 
}
 
void init()
{
    memset(vis, 0 , sizeof(vis));
    memset(tree , 0 , sizeof(tree));
    memset(num , 0 , sizeof(num));
    tol = 0 ;
}
int main()
{
    int t ;
    scanf("%d" , &t);
    while(t--)
    {
        init();
        int n ;
        scanf("%d" , &n);
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d" , &a[i]);
            insert(a[i]);
        }
        int ma = -INF ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                update(a[i] , -1);
                update(a[j] , -1);
                ma = max(ma , research(a[i]+a[j]));
                update(a[i] , 1);
                update(a[j] , 1);
            }
        }
        cout << ma << endl ;
    }
    return 0;
}
