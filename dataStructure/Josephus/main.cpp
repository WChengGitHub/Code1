#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getLast(int n,int m);
int main(int argc, char** argv) {
	cout<<getLast(6,5)<<endl;
	return 0;
}
int getLast(int n,int m){
	
    int position=0;
    
	int dist[n+1];//��ǵ�i+1�����Ƿ��Ѿ������ˣ�0����δ���֣�1�����Ѿ����� 
	for(int i=0;i<n;i++){
		dist[i]=0;
	}
	
    dist[n]=1;//������nλ��ʵ��ѭ�� 
    
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			
			for(;dist[position]!=0;position++){//�жϵ�position+1λ�������Ƿ���� ������Ѿ����ֱ���������Ч��ֱ���ҵ���һ����Ч�ı����� 
				if(position==n){
					position=-1;//��position�� Ϊ-1������ΪΪ����Ϊ0ʱ����һ�������Զ���Ϊ1������֪��i=0����һ���ˣ�������Ƿ��Ѿ������� 
				}
			}
			
			if(j==m-1){//�ж��ǲ������һ���������� 
				break;
			}
			
			position++; //ָ����һ���� 
			if(position==n){
				position=0;
			}
			
			}
			dist[position]=1;
		}
	
	position=-1;
	for(int i=0;i<n;i++){
		if(dist[i]==0){
			position=i;
			break;
		}
	}
	
	return position+1;
}
