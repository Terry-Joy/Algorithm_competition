struct Node{int son[30];int v;}tr[30*N]//26��Сд��ĸʱ,v��������ǰ׺�������㣬�ַ����ظ����ִ������㣬��ֹ��� 
//tot��¼�ܹ����ٸ��ڵ㣬��ʼ��Ϊ1
int tot=1;
void add(char*s)
{
	int now=1;//now��ʾ��ǰλ���ĸ��ڵ�;
	int n=strlen(s);
	for(int i=0;i<n;++i)
	{
		if(tr[now].son[s[i]-'a']==0)//û��,����һ�� 
			tr[now].son[s[i]-'a']=++tot;
			now=tr[now].son[s[i]-'a']//�ڼ������ 
	} 
	++tr[now].v//����	
} 
int find(char*s)
{
	int now=1,n=strlen(s);
	for(int i=0;i<n;++i)
	{
		if(tr[now].son[s[i]-'a']==0)return 0;
			now=tr[now].son[s[i]-'a'];
	}
	return tr[now].v//s���ֵĴ��� 
}
