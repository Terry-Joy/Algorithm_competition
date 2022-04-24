#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
int main()
{
	int x;
	Node *head,*end,*p;
	head=new Node;
	end=head;
	cin>>x;
	while(x!=-1)
	{
		p=new Node;
		p->data=x;
		p->next=NULL;
		end->next=p;
		end=p;
		cin>>x;
	}
	int i;
	cin>>i;
	p=head;
	int j=0;
	while(p->next!=NULL&&j!=i-1)
	{
		p=p->next;
		j++;
	}
    if(p->next==NULL)
    cout<<"no this position";
    else 
    {
    	Node *s=new Node;
    	s=p->next;
    	p->next=p->next->next;
    	delete s;
	} 
	p=head->next;
	while(p->next!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
	cout<<p->data<<endl;
	return 0;
}
