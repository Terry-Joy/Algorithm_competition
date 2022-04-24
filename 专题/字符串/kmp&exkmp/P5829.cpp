#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int m,fail[maxn],fa[maxn][22],d[maxn],lg[maxn];
bool v[maxn];
void getKmp(){ 
    d[0]=1;d[1]=2;
    fail[1]=0;
    fa[1][0]=0;
    for(int i=2,j=0;i<=m;++i){ 
        while(j&&s[i]!=s[j+1])j=fail[j];
        if(s[i]==s[j+1])j++;
        fail[i]=j;
        fa[i][0]=j;
        d[i]=d[j]+1;
    }
    for(int i=1;i<=21;++i){ 
        for(int j=1;j<=m;++j)
            fa[j][i]=fa[fa[j][i-1]][i-1];
    }
}
int lca(int x,int y){ 
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])
        x=fa[x][lg[d[x]-d[y]]-1];
    if(x==y)return x;
    for(int i=lg[d[y]]-1;i>=0;--i)
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int main(){
    scanf("%s",s+1);
    m=strlen(s+1);
    getKmp();
    for(int i=1;i<=m;++i)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    int n,a,b;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){ 
        scanf("%d%d",&a,&b);
        int LCA=lca(a,b);
        if(LCA!=a&&LCA!=b)
            cout<<LCA<<"\n";
        else
            cout<<fail[LCA]<<"\n";
    }
    return 0;
}

