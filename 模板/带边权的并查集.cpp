//带边权的并查集 d[x]表示x前面的点的个数 size[x}表示每个集合元素个数 
//边权位为1的情况 
int fa[maxn],d[maxn],size[maxn],t,b,c;
char a; 
int find(int x)
{
	if(x==fa[x])return x;
	int root=find(fa[x]);		//递归计算集合代表 
	d[x]+=d[fa[x]];				//维护d数组-边权求和 
	return fa[x]=root;			//路径压缩 
}
void init(int x,int y)
{
	int f1=find(x),f2=find(y);
	fa[f1]=f2;d[f1]=size[f2];
	size[f2]+=size[f1];
}

	for(int i=1;i<=30000;++i)
	{
		fa[i]=i;
		size[i]=1;				
	}
