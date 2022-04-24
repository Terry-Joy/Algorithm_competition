#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <deque>
#include <iterator>
#define pi 2*acos(0)
using namespace std;

const int maxn = 1001 + 10;
struct node
{
    int x,y;
} nodes[maxn];

int father[maxn];
double dis[maxn][maxn];
bool isok[maxn];
int n,d;

void init()
{
    for(int i = 0; i <= n; i++)
    {
        father[i] = i;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            dis[i][j] = sqrt((double)(nodes[i].x-nodes[j].x) * (nodes[i].x-nodes[j].x) + (double)(nodes[i].y-nodes[j].y) * (nodes[i].y-nodes[j].y));
            dis[j][i] = sqrt((double)(nodes[i].x-nodes[j].x) * (nodes[i].x-nodes[j].x) + (double)(nodes[i].y-nodes[j].y) * (nodes[i].y-nodes[j].y));
        }
    }

    memset(isok,false,sizeof(isok));//��ʼ�����еĵ��Զ��ǻ��ġ�
}

int find(int x)
{
    if(x == father[x])
        return x;
    int y = find(father[x]);
    return father[x] = y;
}

void unin(int a,int b)
{
    int fa = find(a);
    int fb = find(b);

    father[fa] = fb;

}


int main()
{
    scanf("%d%d",&n,&d);

        int a,b;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%*c",&nodes[i].x,&nodes[i].y);
        }

        init();
        int num1,num2;
        char ch;
        while(~scanf("%c",&ch))
        {
            if(ch == 'O')
            {
                scanf("%d%*c",&num1);
                isok[num1] = true;
                //ÿ���޺�һ̨���ԣ��ͱ������еĵ��ԣ����ݾ����ж��Ƿ���Խ�����ϵ�����Եĺϲ���������
                for(int i = 1; i <= n; i++)
                {
                    if(isok[i] && i != num1)
                    {
                        if((dis[num1][i] <= (double)d) || (dis[i][num1] <= (double)d) )
                        {
                            if(find(num1) != find(i))
                            {
                                unin(num1,i);
                            }
                        }
                    }

                }


            }
            else if(ch == 'S')
            {
                scanf("%d%d%*c",&num1,&num2);
                if(find(num1) == find(num2))//��ѯ��������ڵ���ͬ���Ϳ�����ϵ��
                    printf("SUCCESS\n");
                else
                    printf("FAIL\n");
            }
        }
}

