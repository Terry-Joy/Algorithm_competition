//#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<map>
#include<set>

using namespace std;

char a[100], b[100], tmp[100];
int dp[100][100], pos1[100][100], pos2[100][100];
set<string> ans;
int lena, lenb;

void solve(int len1, int len2, int len)
{
    if(len <= 0){
        string str=tmp + 1;
        ans.insert(str);
        return;
    }
    if(len1 > 0 && len2 > 0){
        for(int i = 0; i < 26; i++){
            int p1 = pos1[len1][i];
            int p2 = pos2[len2][i];
            if(dp[p1][p2] == len){
                tmp[len] = i + 'a';
                solve(p1 - 1, p2 - 1, len - 1);
            }
        }
    }
}

int main()
{
    while(~scanf("%s%s", a + 1, b + 1)){
        lena = strlen(a + 1);
        lenb = strlen(b + 1);
        for(int i = 0; i <= lena; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= lenb; j++)
            dp[0][j] = 0;
        for(int i = 1; i <= lena; i++){
            for(int j = 1; j <= lenb; j++){
                dp[i][j] = max(dp[i][j], max(dp[i-1][j],dp[i][j-1]));
                if(a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
        memset(pos1, -1, sizeof(pos1));
        memset(pos2, -1, sizeof(pos2));
        for(int i = 1; i <= lena; i++)
            for(int j = 0; j < 26; j++){
                if(a[i] == j +'a')
                    pos1[i][j] = i;
                else
                    pos1[i][j] = pos1[i - 1][j];
            }
        for(int i = 1; i <= lenb; i++)
            for(int j = 0; j < 26; j++){
                if(b[i] == j + 'a')
                    pos2[i][j] = i;
                else
                    pos2[i][j] = pos2[i - 1][j];
            }
        solve(lena, lenb, dp[lena][lenb]);
        set<string>::iterator iter;
        for(iter = ans.begin(); iter != ans.end(); iter++){
            cout<<*iter<<"\n";
        }
    }
    return 0;
}
