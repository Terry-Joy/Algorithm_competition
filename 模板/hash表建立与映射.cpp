#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#include<deque>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
#define MID(x,y) ((x+y)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const double PI=acos(-1.0);
int fact[10]= {1,1,2,6,24,120,720,5040,40320,362880};
const int mod = 999983;
const int maxn = 100005;
int tot = 0,n,head[mod+5],v[maxn][6],next[maxn];


int gethash(int id) { //�õ���ϣֵ  ÿλ��������ȡ��
	int hashval=0;
	for(int i=0; i<6; i++) {
		hashval=(hashval%mod+v[id][i]%mod)%mod;
	}
	return hashval;
}
void addvhead(int hashval) { //�ڽӱ�
	next[tot]=head[hashval];//head��ʾ  ��λ���ܺ�Ϊ hashval�����һ��Ԫ�صı��    next[i]��ʾi����һ����ʾ��ʲô
	head[hashval]=tot++;//����head   tot���ǵ�ǰ�����id
}
bool compare(int id,int x) {
	for(int i=0; i<6; i++) { //˳ʱ�� �Ƚ�
		int f=0;
		for(int st=i,j=0; j<6; j++,st= st+1 >= 6 ? 0 : st+1) {
			if(v[id][st]==v[x][j])f++;
			else break;
		}
		if(f==6)return true;
	}
	for(int i=0; i<6; i++) { //��ʱ��
		int f=0;
		for(int st=i,j=5; j>=0; j--,st= st+1 >= 6 ? 0 : st+1) {
			if(v[id][st]==v[x][j])f++;
			else break;
		}
		if(f==6)return true;
	}
	return false;
}
bool pd(int id) {
	int hashval=gethash(id);
	for(int i=head[hashval]; i!=-1; i=next[i]) { //������ϣֵ��ͬ��ѩ��
		if(compare(id,i))return true;
	}
	addvhead(hashval);

	return false;
}
int main() {
	memset(head,-1,sizeof(head));
	cin>>n;
	bool flag=false;
	for(int i=0; i<n; i++) {
		for(int j=0; j<6; j++)scanf("%d",&v[i][j]);
		if(flag)continue;
		if(pd(i))flag=true;

	}
	if(flag)cout<<"Twin snowflakes found."<<endl;
	else cout<<"No two snowflakes are alike."<<endl;
}
