#include<iostream>
#include<cstdlib>
#define size 5
using namespace std;
struct circularbuffer{
	int rear,front,count;
	int items[size];
};
void initialize(circularbuffer *cq1)
{
	cq1->count=0;
	cq1->front=0;
	cq1->rear=-1;
};
int isF(circularbuffer *cq1)
{
	if(cq1->count==size)
	return 1;
	else
	return 0;
};
int isE(circularbuffer *cq1)
{
	if(cq1->count==0)
	return 1;
	else
	return 0;
};
void insert(circularbuffer *cq1,int x)
{
	if(isF(cq1))
	{
		cout<<"overflow! The queue is full! "<<endl;
		exit(1);
	}
	else
	{
    cq1->rear=(cq1->rear+1)%size;
    cq1->items[cq1->rear]=x;
	cq1->count+=1;		
	}

};
int remove(circularbuffer *cq1)
{
	int x;
	if(isE(cq1))
	{
		cout<<"underflow! The queue is empty!"<<endl;
		exit(1);
	}
	else
	{
		x=cq1->items[cq1->front];
		cq1->front=(cq1->front+1)%size;
		cq1->count-=1;
		return x;
	}
};
void print(circularbuffer *cq1)
{
	while(!isE(cq1))
	cout<<remove(cq1)<<endl;
};
int main(void)
{
    circularbuffer queue; int x;
    initialize(&queue);
	for(int i=0;i<5;i++)
	{
		cout<<"enter element number "<<i<<" : ";
		cin>>x;
		insert(&queue,x);
		}	
		print(&queue);
	return 0;
}

//circular buffer is a static circular queue