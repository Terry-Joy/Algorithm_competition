#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int n, m, cnt;
long long ans, a[20];

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b,a%b);
}
//cur��ʾ��ǰ����
//lcm��ʾ��С������
//id��ʾѡ�˼�������������ӣ�ż�����
void dfs(int cur, long long lcm, int id)
{
    lcm = a[cur]/gcd(a[cur],lcm)*lcm;
    if(id&1)
        ans += (n-1)/lcm;
    else ans -= (n-1)/lcm;
    for(int i = cur + 1; i < cnt; i++)
    {
        dfs(i,lcm,id+1);
    }
}
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        cnt = 0;
        for(int i = 0; i < m; ++i)
        {
            int x;
            scanf("%d", &x);
            if(x!=0) a[cnt++]=x; 		//ע���������Ϊ��
        }
        ans = 0;
        for(int i = 0; i < cnt; ++i)
        {
            dfs(i,a[i],1);
        }
        cout << ans << endl;
    }
    return 0;
}

