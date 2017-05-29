#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void siftDown(int *a,int n,int currentPos);
void minHeap(int*a,int n);
int main(int argc, char** argv) {
	int a[8]={53,17,78,9,45,65,87,23};
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	minHeap(a,8);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

void minHeap(int*a,int n)
{
	int size=n;
	int currentPos=(size-2)/2;
	while(currentPos>=0)
	{
		siftDown(a,n,currentPos);
		currentPos--;
	}
}

void siftDown(int *a,int n,int currentPos)
{
	int i=currentPos;
	int j=2*i+1;
	int temp=a[i];
	while(j<n)
	{
		if((j<n-1)&&a[j]>a[j+1])
		j++;
		if(temp<=a[j])
		break;
		else
		{
			a[i]=a[j];i=j;j=2*j+1;
		}
	}
	a[i]=temp;
}
