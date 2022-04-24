#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
bool dp[maxn][maxn][5],g[5][5][5];
int mp[200];
char s[maxn];
int main(){ 
    int W,I,N,G;
    cin>>W>>I>>N>>G;
    mp['W']=1;mp['I']=2;mp['N']=3;mp['G']=4;
    for(int i=1;i<=W;++i){ 
        scanf("%s",s);
        g[mp[s[0]]][mp[s[1]]][1]=1;
    }
    for(int i=1;i<=I;++i){ 
        scanf("%s",s);
        g[mp[s[0]]][mp[s[1]]][2]=1;
    }
    for(int i=1;i<=N;++i){ 
        scanf("%s",s);
        g[mp[s[0]]][mp[s[1]]][3]=1;
    }
    for(int i=1;i<=G;++i){ 
        scanf("%s",s);
        g[mp[s[0]]][mp[s[1]]][4]=1;
    }
    scanf("%s",s+1);
    int L=strlen(s+1);
    for(int i=1;i<=L;++i){ 
        dp[i][i][mp[s[i]]]=1;
    }
    for(int len=2;len<=L;++len){ 
        for(int i=1;i+len-1<=L;++i){ 
            int j=i+len-1;
            for(int k=1;k<=4;++k){ 
                for(int f=1;f<=4;++f)
                    for(int w=1;w<=4;++w)
                        for(int d=i;d<j;++d){ 
                            if(dp[i][d][f]&&dp[d+1][j][w]&&g[f][w][k])
                                dp[i][j][k]=1;
                        }
            }
        }
    }
    int cnt=0;
    if(dp[1][L][1])cout<<'W',cnt++;
    if(dp[1][L][2])cout<<'I',cnt++;
    if(dp[1][L][3])cout<<'N',cnt++;
    if(dp[1][L][4])cout<<'G',cnt++;
    if(!cnt)cout<<"The name is wrong!";
    return 0;
}
