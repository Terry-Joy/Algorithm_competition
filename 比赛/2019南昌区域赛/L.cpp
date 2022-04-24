#include <bits/stdc++.h>
using namespace std;
struct node
{
    int num,score,goal;//净胜球数
}team[110];
bool cmp(node a,node b)
{
    if(a.score==b.score)
        return a.goal>b.goal;
    return a.score>b.score;
}
int pic[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&pic[i][j]);
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        team[i].num=i;
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(pic[i][j]>pic[j][i])
            {
                team[i].score+=3;
                team[i].goal+=(pic[i][j]-pic[j][i]);
            }
            else if(pic[i][j]==pic[j][i])
                team[i].score++;
            else if(pic[i][j]<pic[j][i])
                team[i].goal+=(pic[i][j]-pic[j][i]);
        }
    }
    sort(team+1,team+1+n,cmp);
    if(team[1].score==team[2].score&&team[1].goal==team[2].goal)
        printf("play-offs\n");
    else
        printf("%d\n",team[1].num);
    return 0;
}
