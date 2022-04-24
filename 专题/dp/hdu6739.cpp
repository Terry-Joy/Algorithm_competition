#include<bits/stdc++.h>

using namespace std;
int c[6][3]={{0,1,2},{0,2,1},{1,2,0},{2,1,0},{1,0,2},{2,0,1}};
map<char,string>mp;
const int maxn=1e5+5;
int dp[maxn][7];
char s[maxn];
int cal(string s1,string s2,int x,int y){
    int ans=0;
    if(s1[c[x][0]]==s2[c[y][0]]&&s1[c[x][1]]==s2[c[y][1]]&&s1[c[x][2]]==s2[c[y][2]])ans=0;
    else if(s1[c[x][1]]==s2[c[y][0]]&&s1[c[x][2]]==s2[c[y][1]])ans=1;
    else if(s1[c[x][2]]==s2[c[y][0]])ans=2;
    else  ans=3;
    return ans; 
}
int main(){
    mp['Y']="QQQ";mp['V']="QQW";mp['G']="QQE";
    mp['C']="WWW";mp['X']="QWW";mp['Z']="WWE";
    mp['T']="EEE";mp['F']="QEE";mp['D']="WEE";
    mp['B']="QWE";
    scanf("%s",s+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=5;++i)
        dp[1][i]=4;
    int len=strlen(s+1);
    for(int i=2;i<=len;++i){
        for(int j=0;j<=5;++j){
            for(int k=0;k<=5;++k){
                dp[i][j]=min(dp[i][j],dp[i-1][k]+cal(mp[s[i]],mp[s[i-1]],j,k)+1);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<=5;++i)
        ans=min(ans,dp[len][i]);
    cout<<ans<<endl;
    return 0;
}