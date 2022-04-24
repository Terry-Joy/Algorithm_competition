#include<bits/stdc++.h>
using namespace std ;
const int maxn = 5e5 + 10 ;
int n , q , dp[maxn][22] , k,l,r; 
int main () 
{
    scanf ("%d %d" ,&n,&q) ;
    for (int i = 1 ; i <= n ; i++) 
    {
        scanf ("%d %d" ,&l,&r) ;
        dp[l][0] = max (dp[l][0],r) ;
        k = max (k,r) ;
    }
    for(int i = 1 ; i <= k ; i++) dp[i][0] = max (dp[i][0],dp[i - 1][0]) ;
    for (int i = 1 ; i <= 20 ; i++)
        for (int j = 0 ; j <= k ; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
    while (q--)
    {
        int ans =0;
        scanf ("%d %d" ,&l,&r) ;
        for (int i = 20 ; i >= 0 ; i--)
            if (dp[l][i]<r) 
            {
                ans += 1 << i ;
                l = dp[l][i] ;
            }
        printf ("%d\n" ,dp[l][0]>= r?ans+1:-1) ;
    }
    return 0 ;
}
