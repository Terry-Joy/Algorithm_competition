#include<iostream>
#include<algorithm>
#include<cstring>
const int N=1e7+5;
int prime[NN];
bool vis[N];
int cnt=0;
void is_prime()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    vis[1]=vis[0]=1;
    for(int i=2;i<=N;i++)//题目给的根号n 
    {
        if(!vis[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=N;++j)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
    }
}
 
ll gcd(ll a, ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
 
int main()
{
    ll t, p = 0;
    ll n;
    is_prime();
    cin>>t;
    while(t--)
    {
        bool judge=false;
        p++;
        cin>>n;
        if(n<0){
            n=-n;
            judge=true;
        }
        ll x, ans = 0;
        for(ll i = 1 ; i <=cnt && prime[i] * prime[i] <= n ; i++)
        {
            if(n % prime[i] == 0)
            {
                x = 0;
                while(n % prime[i] == 0)
                {
                    x++;
                    n /= prime[i];
                }
                if(ans == 0)
                    ans = x;
                else
                    ans = gcd(ans, x);
            }
        }
        if(n > 1)//质数 
            ans = 1;
        if(judge){
            while(ans%2==0){
                ans/=2;
            }
        }
        cout<<"Case "<<p<<": "<<ans<<"\n";
    }
    return 0;
}

