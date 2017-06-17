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
    
	int dist[n+1];//标记第i+1个人是否已经出局了，0代表未出局，1代表已经出局 
	for(int i=0;i<n;i++){
		dist[i]=0;
	}
	
    dist[n]=1;//借助第n位来实现循环 
    
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			
			for(;dist[position]!=0;position++){//判断第position+1位报数人是否出局 ，如果已经出局表明报数无效，直到找到下一个有效的报数人 
				if(position==n){
					position=-1;//把position置 为-1，是因为为当置为0时，下一次它会自动变为1，并不知道i=0（第一个人）这个人是否已经出局了 
				}
			}
			
			if(j==m-1){//判断是不是最后一个报数的人 
				break;
			}
			
			position++; //指向下一个人 
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
