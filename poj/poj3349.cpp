#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
const int maxn=1e5+10;
const int mod=999983;
using namespace std;
int n,tot,head[mod+10],next[maxn],v[maxn][6];
int Hash(int id)
{
	int val=0;
	for(int i=0;i<6;++i)
		val=(val%mod+v[id][i]%mod)%mod;
	return val;
}
void addhead(int val)
{
	next[tot]=head[val];
	head[val]=tot++;
}
bool compare(int id,int x) {
	for(int i=0; i<6; i++) { //顺时针 比较
		int f=0;
		for(int st=i,j=0; j<6; j++,st= st+1 >= 6 ? 0 : st+1) {
			if(v[id][st]==v[x][j])f++;
			else break;
		}
		if(f==6)return true;
	}
	for(int i=0; i<6; i++) { //逆时针
		int f=0;
		for(int st=i,j=5; j>=0; j--,st= st+1 >= 6 ? 0 : st+1) {
			if(v[id][st]==v[x][j])f++;
			else break;
		}
		if(f==6)return true;
	}
	return false;
}
bool pd(int id)
{
	int hashval=Hash(id);
	for(int i=head[hashval];i!=-1;i=next[i])
		if(compare(id,i))return true;
		addhead(hashval);
		return false;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	bool flag=false;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<6;++j)
			scanf("%d",&v[i][j]);
			if(flag)continue;
			if(pd[i])flag=true; 
	}
	if(flag)cout<<"Twin snowflakes found."<<"\n";
	else cout<<"No two snowflakes are alike."<<"\n";
	return 0;
} 
