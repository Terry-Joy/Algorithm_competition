struct Node{int son[30];int v;}tr[30*N]//26个小写字母时,v可用来当前缀次数计算，字符串重复出现次数计算，终止标记 
//tot记录总共多少个节点，初始化为1
int tot=1;
void add(char*s)
{
	int now=1;//now表示当前位于哪个节点;
	int n=strlen(s);
	for(int i=0;i<n;++i)
	{
		if(tr[now].son[s[i]-'a']==0)//没有,建立一个 
			tr[now].son[s[i]-'a']=++tot;
			now=tr[now].son[s[i]-'a']//第几个结点 
	} 
	++tr[now].v//次数	
} 
int find(char*s)
{
	int now=1,n=strlen(s);
	for(int i=0;i<n;++i)
	{
		if(tr[now].son[s[i]-'a']==0)return 0;
			now=tr[now].son[s[i]-'a'];
	}
	return tr[now].v//s出现的次数 
}
