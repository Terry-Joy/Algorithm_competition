#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s[12][12];
int mp[10][10];
bool r[10][10],c[10][10],g[10][10],flag;

bool check(int k,int x,int y)
{
    if(r[x][k]==1)return false;
    if(c[y][k]==1)return false;
    int f=3*((x-1)/3)+(y-1)/3+1;
    if(g[f][k]==1)return false;
    return true;
}

void dfs(int x,int y)
{
    if(flag||x==10)
    {
        flag=1;
        return; 
    }
    while(mp[x][y])
    {
        if(y==9)x++,y=1;
        else y++;
        if(x==10)
        {
            flag=1;
            return; 
        } 
    }
    int k=3*((x-1)/3)+(y-1)/3+1; 
    for(int i=1;i<=9;++i)
    {
        if(check(i,x,y))
        {
            mp[x][y]=i;
            r[x][i]=1;
            c[y][i]=1;
            g[k][i]=1;    
            if(y==9)dfs(x+1,1);
            else dfs(x,y+1);
            if(flag)return;
            mp[x][y]=0;
            r[x][i]=0;
            c[y][i]=0;
            g[k][i]=0;
        } 
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        memset(g,0,sizeof(g));
        for(int i=1;i<=9;++i)
            for(int j=1;j<=9;++j)
            { 
            	cin>>s[i][j];
                    mp[i][j]=s[i][j]-'0';
                if(mp[i][j])
                { 
                    int k=3*((i-1)/3)+(j-1)/3+1;
                    r[i][mp[i][j]]=1;
                    c[j][mp[i][j]]=1;
                    g[k][mp[i][j]]=1;
                }
            }
        flag=0;
        dfs(1,1); 
        for(int i=1;i<=9;++i)
        {
            for(int j=1;j<=9;++j)
                printf("%d",mp[i][j]);
            puts(""); 
        }
    } 
    return 0; 
}
