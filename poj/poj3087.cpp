#include<iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;
 
int main(int i,int k)
{
    int test,c;
    int t=0;
    cin>>test;
    while(++t<=test)
    {
        cin>>c;
        char s1[201];   //�ƶ�1
        char s2[201];   //�ƶ�2
        char s12[401];  //Ԥ�����յ��ƶ�״̬
        cin>>s1>>s2>>s12;
 
        map<string,bool>vist;   //��¼���ֹ���ϴ��״̬(mapȱʡֵΪ0)
        vist[s12]=true;
 
        int step=0;  //ϴ�ƴ���
        while(true)
        {
            char s[201];  //��ǰs1��s2ϴ�ƺ��״̬
            int ps=0;  //s[]ָ��
            for(i=0;i<c;i++)    //s1��s2ϴ��
            {
                s[ps++]=s2[i];
                s[ps++]=s1[i];
            }
            s[ps]='\0';
 
            step++;
             
            if(!strcmp(s,s12))   //��ϴ�ƺ��״̬�ܴﵽԤ��״̬ʱ�����
            {
                cout<<t<<' '<<step<<endl;
                break;
            }
            else if(vist[s] && strcmp(s,s12))  //��ǰϴ�ƺ�״̬ �� ǰ����ֹ���״̬�ظ��ˣ�����״̬����Ԥ��״̬
            {                                  //˵��Ԥ���״̬�޷��ﵽ
                cout<<t<<' '<<-1<<endl;
                break;
            }
 
            vist[s]=true;   //״̬��¼
 
            for(i=0;i<c;i++)   //�ֲ��s1��s2
                s1[i]=s[i];
            s1[i]='\0';
 
            for(k=0;i<2*c;i++,k++)
                s2[k]=s[i];
            s2[i]='\0';
        }
    }
    return 0;
}
