int nxt[maxn],f[maxn]//nxt[i]=max(j) s[1..j]=s[i-j+1,i] f[i]=max(j) s[1,j]=b[i-j+1,i]
char s[maxn],b[maxn];//ǰ��ģʽ��s[1,m]�������ı���b[1,n]
void getKmp{
	nxt[1]=0;
	for(int i=2,j=0;i<=m;++i){//i��j+1ƥ��
		while(j&&a[i]!=a[j+1])j=nxt[j];
		if(a[i]==a[j+1])j++;
		nxt[i]=j;
	}
}
void getf(){
	for(int i=1,j=0;i<=n;++i){
		while(j&&(j==m||b[i]!=a[j+1]))j=nxt[j];
		if(b[i]==a[j+1])j++;
		f[i]=j;
	}
}
