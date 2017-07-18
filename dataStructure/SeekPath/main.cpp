#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int y3;
int x3;
void seekPark(int start_x,int start_y,int end_x,int end_y,int(*a)[100],int(*edge)[100],int*x,int*y,int current_i);
void call(int start_x,int start_y,int end_x,int end_y,int(*a)[100],int(*edge)[100],int*x,int*y,int current_i);
int main(int argc, char** argv) {
	int n;
	int a[100][100];
	int x1,y1,x2,y2;
	for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				a[i][j]=1;
			}
		}
	cout<<"请输入迷宫的横数(横数和列数相同):"<<endl;
	cin>>n;
	cout<<"请输入迷宫："<<endl;
	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
	int edge[100][100];
	for(int i=1;i<100;i++){
			for(int j=0;j<100;j++){
				edge[i][j]=a[i][j];
			}
		}
	cout<<"请输入迷宫的入口"<<endl;
	cin>>x1>>y1;
	cout<<"请输入迷宫的出口"<<endl;
	cin>>x2>>y2;
	y3=y1;
	x3=x1;
	int x[10];
	int y[10];
	for(int i=0;i<10;i++){
		x[i]=0;
		y[i]=0;
	}
	x[0]=x1;
	y[0]=y1;
	seekPark(x1,y1,x2,y2,a,edge,x,y,1);
	return 0;
}
void seekPark(int start_x,int start_y,int end_x,int end_y,int(*a)[100],int(*edge)[100],int*x,int*y,int current_i){
	if((start_y==end_y&&start_x==end_x)){
		cout<<start_x<<" "<<"x3:" <<x3<<endl;
		for(int i=0;x[i]!=0;i++){
			cout<<"<"<<x[i]<<","<<y[i]<<">"<<" ";
		}
		cout<<endl<<endl; 
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				edge[i][j]=a[i][j];
			}
		}
		return;
	}else if(edge[start_x-1][start_y-1]==1&&edge[start_x-1][start_y]==1&&edge[start_x-1][start_y+1]==1&&edge[start_x][start_y-1]==1&&edge[start_x][start_y+1]==1&&edge[start_x+1][start_y-1]==1&&edge[start_x+1][start_y]==1&&edge[start_x+1][start_y+1]==1){
		edge[start_x][start_y]==1;
//		cout<<"courrent_i:"<<current_i<<endl;
		x[current_i-1]=0;
		y[current_i-1]=0;
	}else{
		int temp_x[10];
		int temp_y[10];
		for(int i=0;i<10;i++){
			temp_x[i]=x[i];
			temp_y[i]=y[i];
		}
//		cout<<start_x<<" "<<start_y<<endl;
		if(edge[start_x-1][start_y-1]!=1){
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			edge[start_x][start_y]=1;
			call(start_x-1,start_y-1,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		} 
		if(edge[start_x-1][start_y]!=1){
			edge[start_x][start_y]=1;
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			call(start_x-1,start_y,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		}
		if(edge[start_x-1][start_y+1]!=1){
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			edge[start_x][start_y]=1;
			call(start_x-1,start_y+1,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		}
		if(edge[start_x][start_y-1]!=1){
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			edge[start_x][start_y]=1;
			call(start_x,start_y-1,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		}
		if(edge[start_x][start_y+1]!=1){
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			edge[start_x][start_y]=1;
			call(start_x,start_y+1,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		}
		if(edge[start_x+1][start_y-1]!=1){
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			edge[start_x][start_y]=1;
			call(start_x+1,start_y-1,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		}
		if(edge[start_x+1][start_y]!=1){
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			edge[start_x][start_y]=1;
			call(start_x+1,start_y,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		}
		if(edge[start_x+1][start_y+1]!=1){
			for(int i=0;i<10;i++){
			x[i]=temp_x[i];
			y[i]=temp_y[i];
			}
			edge[start_x][start_y]=1;
			call(start_x+1,start_y+1,end_x,end_y,a,edge,x,y,current_i);
			edge[start_x][start_y]=0;
		}
	}
}
void call(int start_x,int start_y,int end_x,int end_y,int(*a)[100],int(*edge)[100],int*x,int*y,int current_i){
//    cout<<"call:"<<start_x<<" "<<start_y<<endl;
	x[current_i]=start_x;
	y[current_i]=start_y;
//	cout<<"current_i:" <<current_i<<endl;
	seekPark(start_x,start_y,end_x,end_y,a,edge,x,y,current_i+1);
}
