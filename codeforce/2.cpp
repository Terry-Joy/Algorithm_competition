#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>
#define LL long long
using namespace std;
const int N=2005;
string s[10]={"1110111","0010010","1011101","1011011",
"0111010","1101011","1101111","1010010","1111111","1111011"};
int n;          //������s����0-9
string a[N];    //��a���������
bool flag=0,st[N][N];  //flag�ж��Ƿ��Ѿ��н�,��st[]�治�Ϸ������,�����ظ�����
int ans[N];     //��ans�����
void dfs(int pos,int k)    //pos��ʾö�ٵ��˵ڼ�������k��ʣ���޸Ĵ���
{
	if(flag||k<0) return;  //����н���޸Ĵ���Ϊ�������
	if(pos==n)
	{   //���ö����n������ʣ���޸Ĵ�������Ϊ0��������𰸲���¼
		if(k==0)
		{
			flag=true;
			for(int i=0;i<n;i++) cout<<ans[i];
			cout<<endl;
			return;
		}
		else return;
	}
    if(st[pos][k]) return;  //�Ѿ�����˸�״̬���Ϸ�������
	for(int i=9;i>=0;i--)   //��ΪҪ�����ֵ�����ԴӴ�Сö��
	{
		int cnt=0;       //��¼a[pos]�޸ĳ���i��Ҫ�Ĵ���
		bool state=false;//��¼a[pos]�ܷ��޸ĳ���i
		for(int j=0;j<7;j++)  //ö��ÿһλ
		if(a[pos][j]=='0'&&s[i][j]=='1') cnt++; //�޸���Ҫ�򿪸õƹ�������޸�
		else if(a[pos][j]=='1'&&s[i][j]=='0') 
		{   //�޸���Ҫ�رոõƹܣ��򲻿��޸ģ����ԣ�a[pos]���ܸ�Ϊ��i
			state=true;
			break;
		}
		
		if(state) continue;
		ans[pos]=i;        //�����޸�����ans��¼
		dfs(pos+1,k-cnt);  //����ö����һ����
	}
	if(!flag) st[pos][k]=true;  //���ö����ϻ�û�еõ��⣬˵���������
}                               //�Ϸ�����st�����¼
int main()
{
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    dfs(0,k);
    
    if(!flag) puts("-1");   //���û�н����-1
    return 0;
}
