#include<iostream>
#include<stdlib.h>
using namespace std;
int getShort(int *a,int *dist,int length);
void updateShort(int *a,int *dist,int (*edge)[5],int length,int position);
int main()
{
	int edge[5][5]={{0,10,99999,30,100},{99999,0,50,99999,99999},{999999,99999,0,99999,10},{99999,99999,20,0,60},{99999,99999,99999,99999,0}};
	int a[5]={1,1,1,1,1};
	a[0]=0;
	int dist[5];
	for(int i=0;i<5;i++)
		dist[i]=edge[0][i];
	for(int i=0;i<3;i++)
	{
		int position=getShort(a,dist,5);
		a[position]=0;
		cout<<"position:"<<position<<endl;
		updateShort(a,dist,edge,5,position);
		for(int i=1;i<5;i++)
		cout<<dist[i]<<" ";
		cout<<endl<<endl;
	}
	for(int i=1;i<5;i++)
		cout<<dist[i]<<" ";
	cout<<endl<<endl;
	system("pause");
}
int getShort(int *a,int *dist,int length)
{
	int mini=1000000;
	int position=-1;
	for(int i=0;i<length;i++)
	{
		if(a[i]==0)
			continue;
		if(dist[i]<=mini)
		{
			mini=dist[i];
			position=i;
		}
	}
	return position;
}
void updateShort(int *a,int *dist,int (*edge)[5],int length,int position)
{
	for(int i=0;i<length;i++)
	{
		if(a[i]==0)
			continue;
		dist[i]=min(dist[i],dist[position]+edge[position][i]);
	}
}