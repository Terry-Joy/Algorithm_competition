//����Ȩ�Ĳ��鼯 d[x]��ʾxǰ��ĵ�ĸ��� size[x}��ʾÿ������Ԫ�ظ��� 
//��ȨλΪ1����� 
int fa[maxn],d[maxn],size[maxn],t,b,c;
char a; 
int find(int x)
{
	if(x==fa[x])return x;
	int root=find(fa[x]);		//�ݹ���㼯�ϴ��� 
	d[x]+=d[fa[x]];				//ά��d����-��Ȩ��� 
	return fa[x]=root;			//·��ѹ�� 
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
