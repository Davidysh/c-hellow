#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
}Node,*List;

void CreateList(List &L,int n)
{
	Node *s,*r;
	int x;
	L=new Node;
	L->next=NULL;
	r=L;
    int i = 1;
	while(i <= n)
	{
        cin>>x;
		s=new Node;
		s->data=x;
		r->next=s;
		r=s;
		i++;
	}
	r->next=NULL;
}

int main()
{
    List L;
    int n,m;
    cin>>n>>m;
    CreateList(L,m);

    int i = 1,max = 0,num = 1;
    Node *r,*s;
    r = L->next;
    s = L->next;
    max = r->data;
    while(s != NULL)
    {
        int dmax = s->data;
        s = s->next;
        if(max < dmax)
        {
            max = dmax;
            r = s;
            num = i;
        }
        i++;
    }
    cout<<"max="<<max<<" "<<"num="<<num;
}