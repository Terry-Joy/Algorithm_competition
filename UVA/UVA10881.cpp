
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=10000+5;

struct ant{
    int id;
    int pos;
    int dir;
    bool operator < (const ant &a)const{
        return pos<a.pos;
    }
}before[maxn],after[maxn];

const char dirName[][10]={"L","Turning","R","Fell off"};

int order[maxn];

int main()
{
    int K;
    scanf("%d",&K);
    for(int kase=1;kase<=K;kase++){
        int L,T,n;
        printf("Case #%d:\n",kase);
        scanf("%d%d%d",&L,&T,&n);
        for(int i=0;i<n;i++){
            int p,d;
            char c;
            scanf("%d %c",&p,&c);
            d=(c=='L'?-1:1);
            before[i]=(ant){i,p,d};
            after[i]=(ant){0,p+T*d,d};
        }
        
        sort(before,before+n);
        sort(after,after+n);
        
        for(int i=0;i<n;i++)order[before[i].id]=i;
        
        for(int i=0;i<n-1;i++)
            if(after[i].pos==after[i+1].pos)after[i].dir=after[i+1].dir=0;
        
        for(int i=0;i<n;i++){
            int a=order[i];
            if(after[a].pos<0||after[a].pos>L)printf("%s\n",dirName[3]);
            else printf("%d %s\n",after[a].pos,dirName[after[a].dir+1]);
        } 
        printf("\n");
    }
    return 0;
}