#include<bits/stdc++.h>
using namespace std;
class RedIsGood{ 
public:
    double dp[2][5005];
    double getProfit(int R,int B){ 
        dp[0][0]=0;
        for(int i=0;i<=R;++i){ 
            for(int j=0;j<=B;++j){ 
                if(i==0&&j==0)continue;
                if(i==0)dp[i&1][j]=0;
                else if(j==0)
                    dp[i&1][j]=dp[(i-1)&1][j]+1;
                else
                    dp[i&1][j]=max(0.0,(dp[(i-1)&1][j]+1)*1.0*i/(i+j)+(dp[i&1][j-1]-1)*1.0*j/(i+j));
            }
        }
        return dp[R&1][B];
    }
};
