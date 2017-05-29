#include <iostream>
using namespace std;
int combination[10000000][13];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void getAllCombination(int * a,int * tag,int * temp,int (*combination)[13],int length,int currentLength,int&num);
bool compare(int * a,int(*edg)[13],int(*edg2)[13],int length);
int main(int argc, char** argv) {
	int a[12];
	int tag[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	int edg[13][13];
	int edg2[13][13];
	int temp[12];
	int length;
	int num=0;
	cout<<"请输入节点个数:"<<endl;
	cin>>length;
	for(int i=0;i<length;i++)
		a[i]=i;
	cout<<"请输入第一个图:"<<endl;
	for(int i=0;i<length;i++) 
		for(int j=0;j<length;j++)
		{
			cin>>edg[i][j];
		}
		cout<<endl; 
	cout<<"请输入第二个图:"<<endl;	
	for(int i=0;i<length;i++) 
		for(int j=0;j<length;j++)
		{
			cin>>edg2[i][j];
		}
		
	getAllCombination(a,tag,temp,combination,length,0,num);
//	cout<<"num:"<<num<<endl;
	bool s=false;
	for(int i=0;i<num;i++)
	{
		int b[12];
		for(int j=0;j<length;j++)
		{
//			cout<<combination[i][j];
			b[j]=combination[i][j];
		}
		cout<<endl;
		s=compare(b,edg,edg2,length);
		if(s==true)
			break;
	
	}
	cout<<endl;
	if(s)
		cout<<"这两个图是同一个图";
	else
		cout<<"这两个图不是同一个图";
	return 0;
}
void getAllCombination(int * a,int * tag,int * temp,int (*combination)[13],int length,int currentLength,int&num)
{
	if(currentLength>=length)
	{
		for(int i=0;i<length;i++)
		{
			combination[num][i]=temp[i];
		}
		num++;
	}
	else
	{
		for(int i=0;i<length;i++)
		{
			if(tag[i]==1)
				continue;
			temp[currentLength]=a[i];
			tag[i]=1;
			getAllCombination(a,tag,temp,combination,length,currentLength+1,num);
			tag[i]=0;
		}
	}
}
bool compare(int * a,int(*edg)[13],int(*edg2)[13],int length)
{
	bool s=true;
	cout<<endl; 
	int temp[13][13];
	int temp1[13][13];
	for(int i=0;i<length;i++)//更换矩阵的行 
	{
		for(int j=0;j<length;j++)
		{
			temp[i][j]=edg[a[i]][j];
		}
			
	}
	for(int i=0;i<length;i++)//更换矩阵的列 
	{
		for(int j=0;j<length;j++)
		{
			temp1[j][i]=temp[j][a[i]]; 
		}
			
	}
	
	cout<<"第一个图顶点的组合:";
	for(int i=0;i<length;i++)
	{
		cout<<a[i];
	} 
	cout<<endl;
	
	cout<<"该组合下的图:" <<endl; 
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			cout<<temp1[i][j]<<" ";
		}
		cout<<endl;	
	}
	cout<<endl;	
	
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			s=(temp1[i][j]==edg2[i][j]);
			if(!s)
			break;
		}
		if(!s)
		break;
	}
	if(s)
		cout<<"匹配"<<endl;
	else
		cout<<"不匹配"<<endl; 
	return s;
}
