#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
const int N =1e6+10;
const LL mod = 1e9 + 7;
char s[N];
int fac[N];
LL ksm(LL a, LL b) 
{ 
	LL ans =1;
	while(b) 
	{ 
		if(b & 1) 
		ans = ans * a % mod;
	 	a = a * a % mod;
	 	b >>= 1;
	}  
	 	return ans; 
}
void init(int n) {
    fac[0] = 0;
    for(int i=1;i<=n;++i) 
	{
        fac[i] = fac[i - 1];
        int k = i;
        while(k % 2 == 0) 
		{
            fac[i]++;
            k/=2;
        }
    }
}

int C(int n, int m) 
{
    return fac[n] - fac[m] - fac[n - m];
}
int main()
{
	int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    bool flag0 = 0, flag1 = 0, flag2 = 0;
    for(int i=1;i<=n;++i) 
	{
        s[i]--;
        if(s[i] == '0') flag0 = 1;
        if(s[i] == '1') flag1 = 1;
        if(s[i] == '2') flag2 = 1;
    }
    if(flag0 + flag1 + flag2 <= 1) 
	{
        puts("0"); return 0;
    }
    init(n);
    int ans = 0;
    if(flag1) 
	{
        for(int i=1;i<=n;++i) 
            if(s[i] == '1') 
                if(C(n - 1, i - 1) == 0) ans ^= 1;
    }
    else 
	{
        for(int i=1;i<=n;++i) 
		{
            if(s[i] == '2') 
			{
                if(C(n - 1, i - 1) == 0) ans ^= 1;
            }
        }
        ans = ans * 2;
    }
    printf("%d\n", ans);
    return 0;
}

