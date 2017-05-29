#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void merge(int*a,int*b,int left,int mid,int right)
{
	for(int i=left;i<=right;i++)
		b[i]=a[i];
	int t1=left,t2=mid+1,sign=left;
	while(t1<=mid&&t2<=right)
		if(b[t1]<b[t2])
		{
			a[sign]=b[t1];
			sign++;
			t1++;
		}
		else
		{
			a[sign]=b[t2];
			sign++;
			t2++;
		}
	while(t1<=mid)
		{
			a[sign]=b[t1];
			sign++;
			t1++;
		}
	while(t2<=right)
		{
			a[sign]=b[t2];
			sign++;
			t2++;
		}
			
}
void mergeSort(int *a,int *b,int left,int right)
{
	if(left>=right)
		return;
	int mid=(left+right)/2;
	mergeSort(a,b,left,mid);
	mergeSort(a,b,mid+1,right);
	merge(a,b,left,mid,right);
}
int main(int argc, char** argv) {
	int a[9]={9,8,7,6,5,4,3,2,1};
	int b[9];
	mergeSort(a,b,0,8);
	for(int i=0;i<9;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
