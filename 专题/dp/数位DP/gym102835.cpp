#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int type;
ull dp[2][23][(1<<16)+5];
int a[100];
ull dfs(int pos,int st,bool limit){
    if(pos==-1)return 1;
    bool tx=(type==10)?0:1;
    if(!limit&&dp[tx][pos][st]!=-1)return dp[tx][pos][st];
    ull ans=0;
    int up=limit?a[pos]:type-1;
    for(int i=0;i<=up;++i){
        if((1<<i)&st)continue;
        ans+=dfs(pos-1,(st==0&&i==0)?0:(st|(1<<i)),limit&&i==up);
    }
    if(!limit)dp[tx][pos][st]=ans;
    return ans;
}
char s[2];
ull solve(ull x){
    int pos=0;
    while(x){
        a[pos++]=x%type;
        x/=type;
    }
    return dfs(pos-1,0,1);
}
void input(ull&x){
    x=0;
    char s[22];
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;++i){
        if(s[i]<='9'&&s[i]>='0')x=x*type+s[i]-'0';
        else x=x*type+s[i]-'a'+10;
    }
}
void print(ull x){
    if(!x){puts("0");return;}
    if(type==10)cout<<x<<"\n";
    else{
        vector<int>ans;
        while(x){
            int p=x%type;
            x/=type;
            ans.push_back(p);
        }
        for(int i=ans.size()-1;i>=0;--i){
            if(ans[i]>=10)printf("%c",ans[i]-10+'a');
            else printf("%c",ans[i]+'0');
        }
        puts("");
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        if(s[0]=='d')type=10;
        else type=16;
        int op;
        scanf("%d",&op);
        if(!op){
            ull a,b;
            input(a);input(b);
            ull ans=solve(b);
            if(a>0)
            ans-=solve(a-1);
            print(ans);
        }else{
            ull x;
            input(x);
            if(x<10){
                cout<<x-1<<"\n";
                continue;
            }
            ull l=0,r=0,ans=0;r--;
            if(solve(r)<x){
                printf("-\n");
                continue;
            }
            while(l<r){
                ull mid=(l+r)/2;
                if(solve(mid)>=x)r=mid;
                else l=mid+1;
            }
            print(r);
        }
    }
    return 0;
}